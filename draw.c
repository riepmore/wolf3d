/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 18:07:31 by pmore             #+#    #+#             */
/*   Updated: 2014/05/17 18:07:32 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			find_color(t_env *env)
{
	if (env->side == 0)
	{
		if (env->mapx < env->posx)
			env->color = env->colorn;
		else
			env->color = env->colors;
	}
	else if (env->side == 1)
	{
		if (env->mapy < env->posy)
			env->color = env->colore;
		else
			env->color = env->colorw;
	}
	if (env->worldmap[env->mapx][env->mapy] == 4)
		env->color = env->color_door;
	if (env->worldmap[env->mapx][env->mapy] == 3)
		env->color = env->color_tp;
}

void			ft_verline(int x, int drawstart, int drawend, t_env *env)
{
	int			y;

	y = 0;
	while (y < SCREENH)
	{
		if (y < drawstart)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, x, y, CIEL);
		else if (y < drawend)
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, x, y, env->color);
		else
			mlx_pixel_put(env->mlx_ptr, env->mlx_win, x, y, SOL);
		y++;
	}
}

void			check_teleport(t_env *env)
{
	static int		i;

	if (env->worldmap[(int)env->posx][(int)env->posy] == 3 && i == 0)
	{
		drop_map(env, "map2");
		env->posx = 1.5;
		env->posy = 1.5;
		i++;
	}
	if (env->worldmap[(int)env->posx][(int)env->posy] == 3 && i == 1)
	{
		drop_map(env, "map3");
		env->posx = 3.5;
		env->posy = 3.5;
		i++;
	}
}

void			start_raycasting(t_env *env)
{
	int			x;

	x = 0;
	while (x < SCREENW)
	{
		check_teleport(env);
		define_env(env, x);
		check_ray(env);
		check_hit(env);
		if (env->drawstart < 0)
			env->drawstart = 0;
		find_color(env);
		ft_verline(x, env->drawstart, env->drawend, env);
		x++;
	}
}

int				expose_hook(t_env *env)
{
	start_raycasting(env);
	return (0);
}
