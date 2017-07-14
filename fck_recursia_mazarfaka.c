/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fck_recursia_mazarfaka.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:35:31 by vpoltave          #+#    #+#             */
/*   Updated: 2017/02/17 20:53:22 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**g_map;

char		**create_map(int m_size)
{
	int		i;
	int		k;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * m_size)))
		return (NULL);
	i = -1;
	while (++i < m_size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (m_size + 1))))
			return (NULL);
		map[i][m_size] = '\n';
	}
	i = -1;
	while (++i < m_size)
	{
		k = -1;
		while (++k < m_size)
			map[i][k] = '.';
	}
	return (map);
}

int			try_fig(t_tetra *tetra, int m_size)
{
	int i[2];

	i[0] = -1;
	if (tetra->c == '0')
		return (1);
	while (++(i[0]) < m_size)
	{
		i[1] = -1;
		while (++(i[1]) < m_size)
		{
			if (g_map[i[0]][i[1]] == '.')
			{
				if (place_fig(i, *tetra, m_size, tetra->c))
				{
					if (!try_fig(tetra + 1, m_size))
						place_fig(i, *tetra, m_size, '.');
					else
						return (1);
				}
			}
		}
	}
	return (0);
}

int			clear_fig(t_tetra *tetra, int *i)
{
	g_map[i[0] - (*tetra).x[0]][i[1] - (*tetra).y[0]] = '.';
	g_map[i[0] - (*tetra).x[1]][i[1] - (*tetra).y[1]] = '.';
	return (1);
}

int			place_fig(int *i, t_tetra tetra, int m_size, char c)
{
	if ((i[0] - tetra.x[0] < m_size) && (i[1] - tetra.y[0] < m_size) &&
		(g_map[i[0] - tetra.x[0]][i[1] - tetra.y[0]] ==
		((c == '.') ? tetra.c : '.')))
		g_map[i[0] - tetra.x[0]][i[1] - tetra.y[0]] = c;
	else
		return (0);
	if ((i[0] - tetra.x[1] < m_size) && (i[1] - tetra.y[1] < m_size) &&
		(g_map[i[0] - tetra.x[1]][i[1] - tetra.y[1]] ==
		((c == '.') ? tetra.c : '.')))
		g_map[i[0] - tetra.x[1]][i[1] - tetra.y[1]] = c;
	else
	{
		g_map[i[0] - tetra.x[0]][i[1] - tetra.y[0]] = '.';
		return (0);
	}
	if ((i[0] - tetra.x[2] < m_size) && (i[1] - tetra.y[2] < m_size) &&
		(g_map[i[0] - tetra.x[2]][i[1] - tetra.y[2]] ==
		((c == '.') ? tetra.c : '.')))
		g_map[i[0] - tetra.x[2]][i[1] - tetra.y[2]] = c;
	else if (clear_fig(&tetra, i))
		return (0);
	g_map[i[0]][i[1]] = c;
	return (1);
}

void		fill_tetra(int m_size, t_tetra *tetra)
{
	g_map = create_map(m_size);
	while (!try_fig(tetra, m_size))
		g_map = create_map(++m_size);
	print_map(m_size);
	free(tetra);
}
