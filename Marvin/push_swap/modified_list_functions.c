/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_list_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:20:17 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/12 23:38:48 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stash	*dl_lstnew(int content)
{
	t_stash	*node;

	node = malloc(sizeof(t_stash));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}

void	dl_lstadd_front(t_stash **a_stack, int content)
{
	t_stash	*a_node;

	a_node = dl_lstnew(content);

	if (a_stack == NULL)
		*a_stack = a_node;
	else
	{
		a_node->next = *a_stack;
		(*a_stack)->prev = a_node;
		*a_stack = a_node;
	}
}

void	dl_lstadd_back(t_stash **a_stack, int content)
{
	t_stash	*a_node;
	t_stash	*temp_node;

	a_node = dl_lstnew(content);

	if (*a_stack == NULL)
		*a_stack = a_node;
	else
	{
		temp_node = *a_stack;
		while (temp_node->next)
			temp_node = temp_node->next;
		temp_node->next = a_node;
		a_node->prev = temp_node;
	}
}
	/* if (a_node == NULL)
	{
		*a_stack = NULL;
		temp = *a_stack;
		while(temp->prev != NULL)
		{
			temp = temp->prev;
			free(temp->next);
		}
		free(temp);
		//single_error_message(a_stack);
	}
	*/