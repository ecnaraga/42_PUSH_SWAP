/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:43:52 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 12:54:03 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/include/ft_printf.h"

typedef struct s_lst_two_push_swap
{
	struct s_lst_two_push_swap	*prev;
	long int			data;
	int					index;
	int					cost;
	int					way;
	struct s_lst_two_push_swap	*next;
}						t_lst_two_push_swap;

typedef struct s_cont_push_swap
{
	t_lst_two_push_swap			*first;
	t_lst_two_push_swap			*last;
	int					size;
}						t_cont_push_swap;

typedef struct s_tip
{
	int					small;
	int					big;
}						t_tip;

/*push_swap.c*/
int						main(int ac, char **av);

/*make_cont_a.c*/
void					ft_check_input(t_cont_push_swap *cont, int bonus);
t_cont_push_swap					*ft_make_cont1(int ac, char **av, t_cont_push_swap *cont,
							int bonus);
t_cont_push_swap					*ft_make_cont2(char **av, t_cont_push_swap *cont, int bonus);

/*lst_utils.c*/
t_lst_two_push_swap				*lst_two_addnew_pushswap(long int data);
void					lst_two_addback_pushswap(t_cont_push_swap *cont, t_lst_two_push_swap *new);
int						lst_two_size_pushswap(t_cont_push_swap *cont);

/*free.c*/
void					*ft_free_lst(t_lst_two_push_swap *lst);
void					*ft_free_array(char **array);
void					ft_error(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, char **array);
void					ft_free_ok(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b);

/*atoi_mode_only_digit.c*/
long int				ft_atoi_digit(char *str);

/*set_index.c*/
void					ft_set_index(t_cont_push_swap *cont);

/*sort_five_or_less.c*/
void					ft_sort_five(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int size,
							int *cost);

/*tri.c*/
void					ft_sort_list(t_cont_push_swap *cont_a);

/*which_move.c*/
void					ft_set_cost_a(t_lst_two_push_swap *pile_a, int size, int i);
t_lst_two_push_swap				*ft_maj_pile_a(t_lst_two_push_swap *pile_b, t_cont_push_swap *cont_a);
void					ft_set_cost_b(t_lst_two_push_swap *pile_b, t_lst_two_push_swap *maj,
							int size, int i);
t_lst_two_push_swap				*ft_look_best_move(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b);

/*push.c*/
int						ft_push_a(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int write);
int						ft_push_b(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int write);

/*swap.c*/
int						ft_swap(t_cont_push_swap *cont, char *order);
int						ft_swap_s(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int write);

/*rotate.c*/
int						ft_rotate(t_cont_push_swap *cont, char *order);
int						ft_rotate_r(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b, int write);

/*resverse_rotate.c*/
int						ft_reverse_rotate(t_cont_push_swap *cont, char *order);
int						ft_reverse_rotate_r(t_cont_push_swap *cont_a, t_cont_push_swap *cont_b,
							int write);

#endif
