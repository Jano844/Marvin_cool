/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:16:59 by mleibeng          #+#    #+#             */
/*   Updated: 2023/11/18 17:18:39 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stash
{
	int				content;
	int				index;
	struct s_stash	*next;
	struct s_stash	*prev;
}	t_stash;

void	swap_a(t_stash **top_a_stack);
void	swap_b(t_stash **top_b_stack);
void	swaps(t_stash **top_a_stack, t_stash **top_b_stack);
void	swap(t_stash **stack);
void	pushto_a(t_stash **b_stack, t_stash **a_stack);
void	pushto_b(t_stash **a_stack, t_stash **b_stack);
void	rotate_a(t_stash **a_stack);
void	rotate_b(t_stash **b_stack);
void	rotates(t_stash **a_stack, t_stash **b_stack);
void	rev_rotate_a(t_stash **a_stack);
void	rev_rotate_b(t_stash **b_stack);
void	rev_rotates(t_stash **a_stack, t_stash **b_stack);
t_stash	*dl_lstnew(int content);
void	dl_lstadd_front(t_stash **a_stack, int content);
void	small_algo(t_stash **a_stack);
void	eff_rotate(t_stash **a_stack, int i);
int		empty_string_check(char *argv);
int		false_value_check(char **argv);
int		false_value_check_two(char **argv);
int		false_value_parse(char *arg);
int		input_check_one(char **argv);
int		check_duplicates(t_stash **a_stack, int control_var);
int		maxint_check(char **split_args);
void	single_error_message(t_stash **stack);
void	array_exit_message(char **split_args, t_stash **stack);
int		find_smallest_num(t_stash *a_stack);
t_stash	*calc_median(t_stash *a_stack, int i);
int 	is_sorted(t_stash *a_stack);
void	init_index(t_stash *a_stack, int i);
void	indexing(t_stash *a_stack, int i);
t_stash	*take_args(int argc, char **argv);
int		count_elements(t_stash **a_stack);
void	push_swap(t_stash **a_stack, t_stash **b_stack);
int		main(int argc, char **argv);
void	bigger_algo(t_stash **a_stack, t_stash **b_stack, int i);
t_stash	*take_arg(char **argv);
void	dl_lstadd_back(t_stash **a_stack, int content);
int		current_to_bottom(t_stash *stack, int i);
void	free_stacks(t_stash **a_stack, t_stash **b_stack);
int		find_chunky_bot_dist(t_stash *a_stack, int chunky_checker);
int		find_chunky_top_dist(t_stash *a_stack, int chunky_checker);
void	big_algo(t_stash **a_stack, t_stash **b_stack, int i);
void	rotate_chunkies(t_stash **a_st, int t_chunk, int b_chunk);
int		absol(int num);
int		find_chunky_top_dist(t_stash *a_stack, int chunky_checker);
int		find_chunky_bot_dist(t_stash *a_stack, int chunky_checker);
void	init_b_stack(t_stash **a_st, t_stash **b_st, int chunky_index);
void	move_chunkies(t_stash **a_st, t_stash **b_st, int chunky_index, int size);
void	prep_b(t_stash **a_st, t_stash **b_st);
void	prep_b_rotate_calc(t_stash **b_st, int closest);
int		chunk_divider(int size);
int		closest_distance(t_stash **stack, t_stash **b_stack);
void	eff_rotate_too(t_stash **stack, int biggest_index);
int		find_biggest_index(t_stash *b_stack);

#endif