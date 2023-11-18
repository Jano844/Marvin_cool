/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:25:02 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/15 03:17:42 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_error_message(t_stash **stack)
{
	t_stash *temp;

	if (!stack || !(*stack))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (stack == NULL || *stack != NULL)
	{
		while (*stack)
		{
			temp = ((*stack)->next);
			free(*stack);
			*stack = temp;
		}
	}
	*stack = NULL;
	write(2, "Error\n", 6);
	exit(1);
}

void	array_exit_message(char **split_args, t_stash **stack)
{
	int	i;

	i = 0;
	while(split_args[i] != 0)
		i++;
	while (i--)
		free(split_args[i]);
	free(split_args);
	single_error_message(stack);
}
