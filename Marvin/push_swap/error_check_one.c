/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:31:19 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/18 17:50:01 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	empty_string_check(char *argv)
{
	int counter;
	int	alarm;

	counter = 0;
	alarm = 1;
	while ((argv[counter] == ' ' && argv[counter] != '\0')
	|| (argv[counter] == '\t' && argv[counter] != '\0'))
		counter++;
	if (argv[counter] != '\0')
		alarm = 0;
	return (alarm);
}

int	false_value_check(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (false_value_parse(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int	false_value_parse(char *arg)
{
	int i;

	i = 0;
	if (ft_issign(arg[i]) && arg[i + 1])
		i++;
	while(arg[i] && ft_isdigit(arg[i]))
		i++;
	if (arg[i] && !ft_isdigit(arg[i]))
		return (1);
	return (0);
}

int maxint_check(char **argv)
{
	int i;
	long num;

	i = 1;
	num = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return(1);
		i++;
	}
	return (0);
}

int	input_check_one(char **argv)
{
	int i;

	i = 1;
	if (maxint_check(argv))
		return (1);
	if (empty_string_check(argv[i]))
		return (1);
	return (0);
}
