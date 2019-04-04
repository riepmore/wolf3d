/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 18:07:55 by pmore             #+#    #+#             */
/*   Updated: 2014/05/17 18:07:56 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			check_ray(t_env *env)
{
	if (env->raydx < 0)
	{
		env->stepx = -1;
		env->sided_x = (env->raypx - env->mapx) * env->deltad_x;
	}
	else
	{
		env->stepx = 1;
		env->sided_x = (env->mapx + 1.0 - env->raypx) * env->deltad_x;
	}
	if (env->raydy < 0)
	{
		env->stepy = -1;
		env->sided_y = (env->raypy - env->mapy) * env->deltad_y;
	}
	else
	{
		env->stepy = 1;
		env->sided_y = (env->mapy + 1.0 - env->raypy) * env->deltad_y;
	}
}

void			check_hit(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sided_x < e->sided_y)
		{
			e->sided_x += e->deltad_x;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sided_y += e->deltad_y;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->worldmap[e->mapx][e->mapy] > 1)
			e->hit = 1;
		if (e->side == 0)
			e->pw = fabs((e->mapx - e->raypx + (1 - e->stepx) / 2) / e->raydx);
		else
			e->pw = fabs((e->mapy - e->raypy + (1 - e->stepy) / 2) / e->raydy);
		e->lineh = abs((int)(SCREENH / e->pw));
		e->drawstart = -e->lineh / 2 + SCREENH / 2;
		e->drawend = e->lineh / 2 + SCREENH / 2;
	}
}
