/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 18:07:26 by pmore             #+#    #+#             */
/*   Updated: 2014/05/17 18:07:27 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define UP		65362
#define DOWN	65364
#define RIGHT	65363
#define LEFT	65361
#define SPACE	32
#define COL		99
#define MORE	65451
#define LESS	65453

void		secret_color(t_env *env)
{
	if (env->colorn <= 0)
		env->colorn = 0xFFFFFF;
	env->colorn = env->colorn - 10000;
	if (env->colors <= 0)
		env->colors = 0xFFFFFF;
	env->colors = env->colors - 10000;
	if (env->colore <= 0)
		env->colore = 0xFFFFFF;
	env->colore = env->colore - 10000;
	if (env->colorw <= 0)
		env->colorw = 0xFFFFFF;
	env->colorw = env->colorw - 10000;
	if (env->color_door <= 0)
		env->color_door = 0xFFFFFF;
	env->color_door = env->color_door - 10000;
}

void		secret_door(t_env *env)
{
	if (env->worldmap[(int)env->posx + 1][(int)env->posy] == 4)
		env->worldmap[(int)env->posx + 1][(int)env->posy] = 1;
	else if (env->worldmap[(int)env->posx - 1][(int)env->posy] == 4)
		env->worldmap[(int)env->posx - 1][(int)env->posy] = 1;
	else if (env->worldmap[(int)env->posx][(int)env->posy + 1] == 4)
		env->worldmap[(int)env->posx][(int)env->posy + 1] = 1;
	else if (env->worldmap[(int)env->posx][(int)env->posy - 1] == 4)
		env->worldmap[(int)env->posx][(int)env->posy - 1] = 1;
	else if (env->worldmap[(int)env->posx + 1][(int)env->posy] == 1)
		env->worldmap[(int)env->posx + 1][(int)env->posy] = 4;
	else if (env->worldmap[(int)env->posx - 1][(int)env->posy] == 1)
		env->worldmap[(int)env->posx - 1][(int)env->posy] = 4;
	else if (env->worldmap[(int)env->posx][(int)env->posy + 1] == 1)
		env->worldmap[(int)env->posx][(int)env->posy + 1] = 4;
	else if (env->worldmap[(int)env->posx][(int)env->posy - 1] == 1)
		env->worldmap[(int)env->posx][(int)env->posy - 1] = 4;
}

void		find_secret(t_env *env, int keycode)
{
	if (keycode == SPACE)
		secret_door(env);
	else if (keycode == COL)
		secret_color(env);
	else if (keycode == MORE)
	{
		env->ms = env->ms + 0.1;
		if (env->ms > 0.7)
			env->ms = 0.7;
	}
	else if (keycode == LESS)
	{
		env->ms = env->ms - 0.1;
		if (env->ms < 0)
			env->ms = 0.0001;
	}
}

void		ft_right_left_key(t_env *e, int key)
{
	if (key == RIGHT)
	{
		e->oldirx = e->dirx;
		e->dirx = e->dirx * cos(-RSPEED) - e->diry * sin(-RSPEED);
		e->diry = e->oldirx * sin(-RSPEED) + e->diry * cos(-RSPEED);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(-RSPEED) - e->planey * sin(-RSPEED);
		e->planey = e->oldplanex * sin(-RSPEED) + e->planey * cos(-RSPEED);
	}
	else if (key == LEFT)
	{
		e->oldirx = e->dirx;
		e->dirx = e->dirx * cos(RSPEED) - e->diry * sin(RSPEED);
		e->diry = e->oldirx * sin(RSPEED) + e->diry * cos(RSPEED);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(RSPEED) - e->planey * sin(RSPEED);
		e->planey = e->oldplanex * sin(RSPEED) + e->planey * cos(RSPEED);
	}
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == UP)
	{
		if (e->worldmap[(int)(e->posx + e->dirx * e->ms)][(int)(e->posy)] <= 3)
			e->posx += e->dirx * e->ms;
		if (e->worldmap[(int)(e->posx)][(int)(e->posy + e->diry * e->ms)] <= 3)
			e->posy += e->diry * e->ms;
	}
	else if (keycode == DOWN)
	{
		if (e->worldmap[(int)(e->posx - e->dirx * e->ms)][(int)(e->posy)] <= 3)
			e->posx -= e->dirx * e->ms;
		if (e->worldmap[(int)(e->posx)][(int)(e->posy - e->diry * e->ms)] <= 3)
			e->posy -= e->diry * e->ms;
	}
	else if (keycode == RIGHT || keycode == LEFT)
		ft_right_left_key(e, keycode);
	else if (keycode == 65307)
		exit(0);
	find_secret(e, keycode);
	start_raycasting(e);
	ft_printf("position: %i:%i\n", (int)e->posx, (int)e->posy);
	return (0);
}
