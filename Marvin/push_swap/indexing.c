/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:29:18 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/13 20:38:27 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_stash *a_stack, int i)
{
	t_stash *compare;

	compare = a_stack;
	if (compare->content == INT_MAX && compare->index == 0)
		compare->index = i;
}

void	indexing(t_stash *a_stack, int i)
{
	t_stash *compare;
	t_stash	*lowest;
	int 	num;
	int		min_value;

	min_value = 0;
	while(++min_value < i + 1)
	{
		lowest = NULL;
		num = INT_MAX;
		compare = a_stack;
		while(compare)
		{
			if (compare->content < num && compare->index == 0)
			{
				num = compare->content;
				lowest = compare;
				compare = a_stack;
			}
			else
				compare = compare->next;
		}
		if (lowest != NULL)
			lowest->index = min_value;
	}
}
