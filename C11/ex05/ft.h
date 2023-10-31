/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:44:51 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/08/03 17:44:52 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	plus(int a, int b);
void	minus(int a, int b);
void	mult(int a, int b);
void	div(int a, int b);
void	mod(int a, int b);
void	ft_exept(int nb);
void	ft_putnbr(int nb);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
void	*do_op(char *op);

#endif
