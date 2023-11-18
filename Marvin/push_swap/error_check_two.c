/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:51:13 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/14 01:43:54 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	check_duplicates(t_stash **a_stack, int control_var)
{
	t_stash *test;
	int alarm;

	alarm = 0;
	test = *a_stack;
	while(test != NULL)
	{
		if(test->content == control_var)
			alarm = 1;
		test = test->next;
	}
	return (alarm);
}

int	false_value_check_two(char **args)
{
	int i;

	i = 1;
	while (args[i])
	{
		if (false_value_parse(args[i]))
			return (1);
		i++;
	}
	return (0);
}
// int maxint_check(char **argv)
// {
// 	int i;
// 	long num;

// 	i = 1;
// 	num = 0;
// 	while (argv[i])
// 	{
// 		num = ft_atoi(argv[i]);
// 		if (num < INT_MIN || num > INT_MAX)
// 			return(1);
// 		i++;
// 	}
// 	return (0);
// }

// int	input_check_two(char **split_args)
// {
// 	int size;

// 	size = sizeof(split_args) / sizeof(split_args[0]);
// 	if (double_value_check(split_args, size))
// 		return (1);

// 	return (0);
// }
