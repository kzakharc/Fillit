/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:15:49 by kzakharc          #+#    #+#             */
/*   Updated: 2017/02/17 21:20:23 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ret_function(void)
{
	write(1, "error\n", 6);
	return (1);
}

int		main(int argc, char **argv)
{
	char		buff[546];
	int			fd;
	int			i;
	int			m_size;
	t_tetra		*tetra;

	i = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == (-1))
			return (ret_function());
		while (read(fd, buff + i, 1))
			i++;
		buff[i] = '\0';
		if (!chck_map_m(buff) || !chck_map(buff) || !(tetra = fill_coord(buff)))
			return (ret_function());
		m_size = map_size(buff);
		fill_tetra(m_size, tetra);
		close(fd);
		return (0);
	}
	else
		write(1, "usage: ./fillit source_file\n", 28);
}
