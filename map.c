/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 18:07:18 by pmore             #+#    #+#             */
/*   Updated: 2014/05/17 18:07:19 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			drop_map(t_env *env, char *map)
{
	int		fd;
	int		x;
	int		y;
	char	buf;

	x = 0;
	y = 0;
	fd = open(map, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			x = 0;
			y++;
		}
		else
		{
			env->worldmap[x][y] = ft_atoi(&buf);
			x++;
		}
	}
}
