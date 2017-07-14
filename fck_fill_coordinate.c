/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fck_fill_coordinate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:15:21 by kzakharc          #+#    #+#             */
/*   Updated: 2017/02/17 21:15:22 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**g_map;

int			map_size(char *buff)
{
	int i;
	int j;

	i = 2;
	j = chck_map_diez(buff);
	while (i * i < j)
		i++;
	return (i);
}

void		print_map(int m_size)
{
	int i;
	int j;

	i = -1;
	while (++i < m_size)
	{
		j = -1;
		while (g_map[i][++j] != '\n')
			write(1, &g_map[i][j], 1);
		write(1, "\n", 1);
	}
}

int			x_y_fill(char *buff, int *x, int *y)
{
	int i;
	int j;
	int n;

	n = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (*buff == '#')
			{
				x[n] = (n == 0) ? i : x[0] - i;
				y[n] = (n == 0) ? j : y[0] - j;
				n++;
			}
			buff++;
		}
		buff++;
	}
	if (!first_tetr(x, y) && !second_tetr(x, y) && !third_tetr(x, y))
		return (0);
	return (1);
}

t_tetra		*fill_coord(char *buff)
{
	int		x[4];
	int		y[4];
	int		i;
	int		j;
	t_tetra	*tetra;

	i = 0;
	tetra = (t_tetra *)malloc(sizeof(t_tetra) * ((f_len(buff) + 1) / 21 + 1));
	while (*buff)
	{
		if (!(x_y_fill(buff, x, y)))
			return (0);
		j = -1;
		while (++j < 3)
		{
			tetra[i].x[j] = x[j + 1];
			tetra[i].y[j] = y[j + 1];
			tetra[i].c = i + 'A';
		}
		(buff += (buff[20]) ? 21 : 20);
		i++;
	}
	tetra[i].c = '0';
	return (tetra);
}
