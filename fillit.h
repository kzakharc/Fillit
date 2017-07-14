/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:46:04 by kzakharc          #+#    #+#             */
/*   Updated: 2017/02/17 12:11:49 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_tetra
{
	int			x[3];
	int			y[3];
	char		c;
}				t_tetra;

int				chck_map_m(char *buff);
int				chck_map_diez(char *buff);
int				chck_map_n(char *buff);
int				chck_map(char *buff);
int				x_y_fill(char *buff, int *x, int *y);
t_tetra			*fill_coord(char *buff);
int				map_size(char *buff);
int				f_len(char *str);
char			**create_map(int m_size);
int				try_fig(t_tetra *tetra, int m_size);
int				place_fig(int *i, t_tetra tetra, int m_size, char c);
void			print_map(int m_size);
void			fill_tetra(int m_size, t_tetra *tetra);
int				first_tetr(int *x, int *y);
int				second_tetr(int *x, int *y);
int				third_tetr(int *x, int *y);

#endif
