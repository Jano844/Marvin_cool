/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:32:43 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/18 18:37:59 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_algo(t_stash **a_stack)
{
	int current;
	int next;
	int last;

	current = (*a_stack)->index;
	next = (*a_stack)->next->index;
	last = (*a_stack)->next->next->index;
	if(current > next && next < last && current < last)
		swap_a(a_stack);
	else if (current > next && next > last && current > last)
	{
		swap_a(a_stack);
		rev_rotate_a(a_stack);
	}
	else if (current > next && next < last && current > last)
		rotate_a(a_stack);
	else if (current < next && current < last && next > last)
	{
		swap_a(a_stack);
		rotate_a(a_stack);
	}
	else if (current < next && current > last && next > last)
		rev_rotate_a(a_stack);
}

void	bigger_algo(t_stash **a_stack, t_stash **b_stack, int i)
{
	int count_three;

	count_three = i;
	b_stack = ft_calloc(1, sizeof(t_stash));
	if(!b_stack)
		single_error_message(a_stack);
	while(count_three > 3)
	{
		eff_rotate(a_stack, i);
		pushto_b(a_stack, b_stack);
		count_three--;
	}
		small_algo(a_stack);
	while(count_three < i)
	{
		pushto_a(b_stack, a_stack);
		count_three++;
	}
}

void	big_algo(t_stash **a_stack, t_stash **b_stack, int size)
{
	int	chunky_index;
	int	divider;
	int counter;
	int	biggest_index;

	divider = chunk_divider(size);
	counter = divider;
	chunky_index = size / divider;
	init_b_stack(a_stack, b_stack, chunky_index);
	while (counter)
	{
		move_chunkies(a_stack, b_stack, chunky_index, (size / divider));
		chunky_index += (size / divider);
		counter--;
	}
	while (*b_stack)
	{
		biggest_index = find_biggest_index(*b_stack);
		if ((*b_stack)->index != biggest_index)
			eff_rotate_too(b_stack, biggest_index);
		pushto_a(b_stack, a_stack);
	}
}

int	find_chunky_top_dist(t_stash *a_stack, int chunky_checker)
{
	int distance;
	t_stash *min_node;

	distance = 0;
	min_node = a_stack;
	while (min_node->index > chunky_checker)
	{
		min_node = min_node->next;
		distance++;
		if (!min_node)
			return (-1);
	}

	return (distance);
}

int	find_chunky_bot_dist(t_stash *a_stack, int chunky_checker)
{
	int distance;
	t_stash *min_node;

	distance = 0;
	min_node = a_stack;
	while (a_stack->next)
		a_stack = a_stack->next;
	while (a_stack->index > chunky_checker)
	{
		a_stack = a_stack->prev;
		distance++;
	}
	return (distance);
}

void	rotate_chunkies(t_stash **a_st, int t_chunk, int b_chunk)
{
	if (t_chunk < b_chunk)
	{
		while (t_chunk)
		{
			rotate_a(a_st);
			t_chunk--;
		}
	}
	else
	{
		while (b_chunk)
		{
			rev_rotate_a(a_st);
			b_chunk--;
		}
	}
}

void	init_b_stack(t_stash **a_st, t_stash **b_st, int chunky_index)
{
	int	init;
	int	top_chunker;
	int	bot_chunker;

	init = 2;
	while (init)
	{
		top_chunker = find_chunky_top_dist((*a_st), chunky_index);
		bot_chunker	= find_chunky_bot_dist((*a_st), chunky_index);
		rotate_chunkies(a_st, top_chunker, bot_chunker);
		pushto_b(a_st, b_st);
		init--;
	}
}

void	move_chunkies(t_stash **a_st, t_stash **b_st, int chunky_index, int size)
{
	int	top_chunker;
	int	bot_chunker;

	while (size)
	{
		if (!(*a_st))
		{
			size = 0;
			break ;
		}
		top_chunker = find_chunky_top_dist((*a_st), chunky_index);
		if (top_chunker == -1)
		{
			size = 0;
			break ;
		}
		bot_chunker	= find_chunky_bot_dist((*a_st), chunky_index);
		rotate_chunkies(a_st, top_chunker, bot_chunker);
		prep_b(a_st, b_st);
		pushto_b(a_st, b_st);
		if ((*b_st)->index < (*b_st)->next->index)
			swap_b(b_st);
		size--;
	}
}

void	prep_b(t_stash **a_st, t_stash **b_st)
{
	int closest;

	closest = closest_distance(a_st, b_st);
	prep_b_rotate_calc(b_st, closest);
}
int closest_distance(t_stash **stack, t_stash **b_stack) {
	int target_index = (*stack)->index;
	int min_distance = -1;
	int closest_index = -1;
	int	current_distance;
	t_stash *current;

	current = (*b_stack);
	if ((*stack) == NULL)
		return (-1);
	while (current != NULL) {
		current_distance = absol(current->index - target_index);
		if (min_distance == -1 || current_distance < min_distance ||
			(current_distance == min_distance && current->index > closest_index)) {
			min_distance = current_distance;
			closest_index = current->index;
		}
		current = current->next;
	}
return (closest_index);
}

void	prep_b_rotate_calc(t_stash **b_st, int closest)
{
	int bottom_distance;
	int top_distance;

	bottom_distance = current_to_bottom(*b_st, closest);
	top_distance = closest - bottom_distance;
	if (bottom_distance <= top_distance)
		while((*b_st)->index != closest)
			rotate_b(b_st);
	else
		while((*b_st)->index != closest)
			rev_rotate_b(b_st);
}

int	chunk_divider(int size)
{
	int optimal_chunkies;
	int	min_chunkies;
	int i;

	optimal_chunkies = 1;
	min_chunkies = 5;
	i = 2;
	while (++i <= size)
	{
		if (size % i == 0)
		{
			optimal_chunkies = i;
			break ;
		}
	}
	if (optimal_chunkies > 14 || optimal_chunkies < 5)
		optimal_chunkies = min_chunkies;
	return (optimal_chunkies);
}