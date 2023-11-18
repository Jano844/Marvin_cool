/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:31:08 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/17 03:07:24 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int absol(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int is_sorted(t_stash *a_stack)
{

	while (a_stack->next != NULL)
	{
		if(a_stack->content > a_stack->next->content)
			return (0);
		a_stack = a_stack->next;
	}
		return (1);
}

void	free_stack(t_stash **stack)
{
		t_stash *temp;

		if (stack != NULL)
			while(*stack)
			{
				temp = ((*stack)->next);
				free(*stack);
				*stack = temp;
			}
}

void	free_stacks(t_stash **a_stack, t_stash **b_stack)
{
	free_stack(a_stack);
	free_stack(b_stack);
	a_stack = NULL;
	b_stack = NULL;
}
