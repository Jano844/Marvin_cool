/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_orders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:35:06 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/18 15:21:38 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stash **a_stack)
{
	swap(a_stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_stash **b_stack)
{
	swap(b_stack);
	write(1, "sb\n", 3);
}

void swaps(t_stash **a_stack, t_stash **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	write(1, "ss\n", 3);
}


void	pushto_a(t_stash **b_stack, t_stash **a_stack)
{
	t_stash	*node_b;

	if (b_stack != NULL && *b_stack != NULL)
	{
		node_b = *b_stack;
		if (node_b->next != NULL)
			node_b->next->prev = node_b->prev;
		if (node_b->prev != NULL)
			node_b->prev->next = node_b->next;
		else
			*b_stack = node_b->next;
		node_b->next = *a_stack;
		node_b->prev = NULL;
		if (*a_stack != NULL)
			(*a_stack)->prev = node_b;
		*a_stack = node_b;
		write(1, "pa\n", 3);
	}
}

void	pushto_b(t_stash **a_stack, t_stash **b_stack)
{
	t_stash	*node_a;

	if (a_stack != NULL)
	{
		node_a = *a_stack;
		if (node_a->next != NULL)
			node_a->next->prev = node_a->prev;
		if (node_a->prev != NULL)
			node_a->prev->next = node_a->next;
		else
			*a_stack = node_a->next;
		node_a->next = *b_stack;
		node_a->prev = NULL;
		if (*b_stack != NULL)
			(*b_stack)->prev = node_a;
		*b_stack = node_a;
		write(1, "pb\n", 3);
	}
}
