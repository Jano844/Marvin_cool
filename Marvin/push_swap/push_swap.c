/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:16:56 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/18 17:55:11 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stash	*take_arg(char **argv)
{
	t_stash *a_stack;
	char	**split_args;
	int		i;
	int		num;

	i = 0;
	a_stack = NULL;
	split_args = ft_split(argv[1], ' ');
	if (!split_args)
		single_error_message(&a_stack);
	if (false_value_check(split_args) || maxint_check(split_args))
		array_exit_message(split_args, &a_stack);
	while (split_args[i] != NULL)
	{
		num = ft_atoi(split_args[i]);
		if (check_duplicates(&a_stack, num))
			array_exit_message(split_args, &a_stack);
		dl_lstadd_back(&a_stack, num);
		i++;
	}
	while (i--)
		free(split_args[i]);
	free(split_args);
	return(a_stack);
}

t_stash	*take_args(int argc, char **argv)
{
	t_stash *a_stack;
	int		i;
	int		num;

	i = 0;
	a_stack = NULL;
	if (false_value_check_two(argv))
		single_error_message(&a_stack);
	while (++i < argc)
	{
		if (empty_string_check(argv[i]))
			single_error_message(&a_stack);
		num = ft_atoi(argv[i]);
		if (check_duplicates(&a_stack, num))
			single_error_message(&a_stack);
		dl_lstadd_back(&a_stack, num);
	}
	return (a_stack);
}
/* i looked at the topic again, this ^ function won't work, I need to split the string given using ft_split first!!!
Steps to take!						 |
split argv argument 1 of argc,		 |
then save that in an array,
then iterate over the array and convert characters into integers!!!
so the iteration has to change from argc to length of split array,
to make sure all saved arguments are converted to a linked list element
--> fixed it hopefully.
*/

int	count_elements(t_stash **a_stack)
{
	int		i;
	t_stash *temp;

	i = 0;
	temp = *a_stack;
	if (a_stack == NULL)
		return (i);
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	push_swap(t_stash **a_stack, t_stash **b_stack)
{
	int	i;

	i = count_elements(a_stack);
	init_index(*a_stack, i);
	indexing(*a_stack, i);
	if (i == 2 && !is_sorted(*a_stack))
		swap_a(a_stack);
	else if (i <= 3)
		small_algo(a_stack);
	else if (i <= 5)
		bigger_algo(a_stack, b_stack, i);
	else if (i > 5)
		big_algo(a_stack, b_stack, i);
}

int	main(int argc, char **argv)
{
	t_stash *a_stack;
	t_stash *b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (argc < 2)
		return (0);
	if (input_check_one(argv))
			single_error_message(NULL);
	if (argc == 2)
	{
		a_stack = take_arg(argv);
	}
	else
		a_stack = take_args(argc, argv);
	if (is_sorted((a_stack)))
		return (0);
	push_swap(&a_stack, &b_stack);
	free_stacks(&a_stack, &b_stack);
	return (0);
}
// I should think about either implementing a merge or quick sort.
// For a quick sort I would first
//  -> need to determine which median value is my pivot point
// For the merge sort i need to arrange a size
//  -> thats comparable to the values given in my a list, also to my b list.
// 3rd option would be to try a Radix sort (LSD)
// -> compares digits by comparing bit
// --> (would utilize bitshifting) to sort(probably)
// + it has a stable sorting time of O(n * l)