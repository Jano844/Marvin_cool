/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:05:02 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/18 17:09:46 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_smallest_num(t_stash *a_stack)
{
	int num;
	t_stash *min_node;

	num = INT_MAX;
	min_node = a_stack;
	while(a_stack)
	{
		if(num > a_stack->index)
		{
			num = a_stack->index;
			min_node = a_stack;
		}
		a_stack = a_stack->next;
	}
	return (min_node->index);
}

t_stash	*calc_median(t_stash *a_stack, int i)
{
	int middle;
	t_stash *median_node;

	middle = i / 2;
	median_node = a_stack;
	while (middle > 0 && median_node != NULL)
	{
		median_node = median_node->next;
		middle--;
	}
	return (median_node);
}

int	current_to_bottom(t_stash *stack, int i)
{
	int length;
	t_stash *start;

	length = 0;
	start = stack;
	while (start->index != i)
	{
		start = start->next;
		length++;
		if (!start->next)
			return (length);
	}
	return(length);
}

int find_biggest_index(t_stash *b_stack)
{
	int num;
	t_stash *max_node;

	num = INT_MIN;
	max_node = b_stack;
	while(b_stack)
	{
		if(num < b_stack->index)
		{
			num = b_stack->index;
			max_node = b_stack;
		}
		b_stack = b_stack->next;
	}
	return (max_node->index);
}