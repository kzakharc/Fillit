/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fck_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:14:38 by kzakharc          #+#    #+#             */
/*   Updated: 2017/02/17 21:14:41 by kzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		chck_map_m(char *buff)
{
	int j;

	j = (f_len(buff) + 1) / 21;
	if (((chck_map_n(buff) + 1) % 5 != 0) || (chck_map_diez(buff) % 4 != 0)
			|| ((chck_map_n(buff) + 1) / 5 != j) ||
			(chck_map_diez(buff) / 4 != j))
		return (0);
	return (1);
}

int		f_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		chck_map_n(char *buff)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int		chck_map_diez(char *buff)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			j++;
		i++;
	}
	return (j);
}

int		chck_map(char *buff)
{
	int j;

	j = 0;
	while (buff[j])
	{
		if ((buff[j] == '.' || buff[j] == '#') && ((j % 21 + 1) % 5 == 0))
			return (0);
		else if ((buff[j] == '.' || buff[j] == '#') || (buff[j] == '\n' &&
												((j % 21 + 1) % 5 == 0)))
			j++;
		else if ((buff[j] == '\n') && ((j % 21 + 1) % 21 == 0))
			j++;
		else
			return (0);
	}
	return (1);
}
