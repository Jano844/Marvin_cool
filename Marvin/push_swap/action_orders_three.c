/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_orders_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:42:01 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/15 02:38:39 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_stash **a_stack)
{
	t_stash	*first;

	if (*a_stack == NULL || (*a_stack)->next == NULL)
		return ;
	first = *a_stack;
	while (first->next != NULL)
		first = first->next;
	first->prev->next = NULL;
	first->prev = NULL;
	first->next = *a_stack;
	(*a_stack)->prev = first;
	*a_stack = first;
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stash **b_stack)
{
	t_stash	*first;

	if (*b_stack == NULL || (*b_stack)->next == NULL)
		return ;
	first = *b_stack;
	while (first->next != NULL)
		first = first->next;
	first->prev->next = NULL;
	first->prev = NULL;
	first->next = *b_stack;
	(*b_stack)->prev = first;
	*b_stack = first;
	write(1, "rrb\n", 4);
}

void	rev_rotates(t_stash **a_stack, t_stash **b_stack)
{
	t_stash	*first_a;
	t_stash	*first_b;

	if (*a_stack == NULL || (*a_stack)->next == NULL)
		return ;
	first_a = *a_stack;
	while (first_a->next != NULL)
		first_a = first_a->next;
	first_a->next = *a_stack;
	(*a_stack)->prev = first_a;
	*a_stack = first_a;
	(*a_stack)->next->prev = NULL;
	(*a_stack)->next = NULL;
	if (*b_stack == NULL || (*b_stack)->next == NULL)
		return ;
	first_b = *b_stack;
	while (first_b->next != NULL)
		first_b = first_b->next;
	first_b->next = *b_stack;
	(*b_stack)->prev = first_b;
	*b_stack = first_b;
	(*b_stack)->next->prev = NULL;
	(*b_stack)->next = NULL;
	write(1, "rrr\n", 4);
}
