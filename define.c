/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 18:08:00 by pmore             #+#    #+#             */
/*   Updated: 2014/05/17 18:08:00 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_pos(t_env *env)
{
	env->posx = 1.5;
	env->posy = 1.5;
	env->dirx = -1;
	env->diry = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->colorn = 0xFF6600;
	env->colors = 0xFFCC33;
	env->colore = 0xFF9933;
	env->colorw = 0xFF3333;
	env->color_door = 0x663300;
	env->color_tp = 0x000000;
	env->ms = 0.3;
}

void			define_env(t_env *e, int x)
{
	e->camx = 2 * x / (double)SCREENW - 1;
	e->raypx = e->posx;
	e->raypy = e->posy;
	e->raydx = e->dirx + e->planex * e->camx;
	e->raydy = e->diry + e->planey * e->camx;
	e->mapx = (int)e->raypx;
	e->mapy = (int)e->raypy;
	e->deltad_x = sqrt(1 + (e->raydy * e->raydy) / (e->raydx * e->raydx));
	e->deltad_y = sqrt(1 + (e->raydx * e->raydx) / (e->raydy * e->raydy));
	e->hit = 0;
}
