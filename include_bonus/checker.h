/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:23:46 by galambey          #+#    #+#             */
/*   Updated: 2023/07/07 13:21:48 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/ft_printf/include/ft_printf.h"
# include "../libft/get_next_line/includes/get_next_line.h"

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

/*checker.c*/
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