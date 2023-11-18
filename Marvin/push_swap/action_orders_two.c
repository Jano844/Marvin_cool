/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_orders_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:38:39 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/18 18:30:51 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stash **stack)
	{
		t_stash *current;
		t_stash *second;
		if (*stack && (*stack)->next)
		{
			current = *stack;
			second = current->next;
			if (second->next)
				second->next->prev = current;
			current->next = second->next;
			second->prev = current->prev;
			second->next = current;
			current->prev = second;
			*stack = second;
		}
	}
void	rotate_a(t_stash **a_stack)
{
	t_stash	*last;

	if (*a_stack == NULL || (*a_stack)->next == NULL)
		return ;
	last = *a_stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *a_stack;
	(*a_stack)->prev = last;
	*a_stack = (*a_stack)->next;
	(*a_stack)->prev->next = NULL;
	(*a_stack)->prev = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stash **b_stack)
{
	t_stash	*last;

	if (*b_stack == NULL || (*b_stack)->next == NULL)
		return ;
	last = *b_stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *b_stack;
	(*b_stack)->prev = last;
	*b_stack = (*b_stack)->next;
	(*b_stack)->prev->next = NULL;
	(*b_stack)->prev = NULL;
	write(1, "rb\n", 3);
}

void	rotates(t_stash **a_stack, t_stash **b_stack)
{
	t_stash	*last_a;
	t_stash	*last_b;

	if (*a_stack == NULL || (*a_stack)->next == NULL
		|| *b_stack == NULL || (*b_stack)->next == NULL)
		return ;
	last_a = *a_stack;
	last_b = *b_stack;
	while (last_a->next != NULL)
		last_a = last_a->next;
	while (last_b->next != NULL)
		last_b = last_b->next;
	last_a->next = *a_stack;
	(*a_stack)->prev = last_a;
	*a_stack = (*a_stack)->next;
	(*a_stack)->prev->next = NULL;
	(*a_stack)->prev = NULL;
	last_b->next = *b_stack;
	(*b_stack)->prev = last_b;
	*b_stack = (*b_stack)->next;
	(*b_stack)->prev->next = NULL;
	(*b_stack)->prev = NULL;
	write(1, "rr\n", 3);
}

void eff_rotate(t_stash **stack, int i)
{
	int	smallest_index;
	int bottom_distance;
	int	top_distance;

	smallest_index = find_smallest_num(*stack);
	bottom_distance = current_to_bottom(*stack, smallest_index);
	top_distance = i - bottom_distance;
	if (bottom_distance <= top_distance)
		while((*stack)->index != smallest_index)
			rotate_a(stack);
	else
		while((*stack)->index != smallest_index)
			rev_rotate_a(stack);
}


void eff_rotate_too(t_stash **stack, int biggest_index)
{
	int bottom_distance;
	int	top_distance;

	bottom_distance = current_to_bottom(*stack, biggest_index);
	top_distance = biggest_index - bottom_distance;
	if (bottom_distance <= top_distance)
		while((*stack)->index != biggest_index)
			rotate_b(stack);
	else
		while((*stack)->index != biggest_index)
			rev_rotate_b(stack);
}