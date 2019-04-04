/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 20:49:19 by pmore             #+#    #+#             */
/*   Updated: 2014/01/18 02:29:04 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

# define MAPH			24
# define MAPW 			24
# define SCREENW		640
# define SCREENH		340
# define SOL 			0x66CC00
# define CIEL 			0x33FFFF
# define RSPEED			0.1

typedef struct		s_env
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			worldmap[MAPW][MAPH];
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineh;
	int			drawstart;
	int			drawend;
	int			color;
	int			colorn;
	int			colors;
	int			colore;
	int			colorw;
	int			color_door;
	int			color_tp;
	double		ms;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		oldirx;
	double		oldplanex;
	double		camx;
	double		raypx;
	double		raypy;
	double		raydx;
	double		raydy;
	double		sided_x;
	double		sided_y;
	double		deltad_x;
	double		deltad_y;
	double		pw;
}					t_env;

void				check_ray(t_env *env);
void				check_hit(t_env *e);
void				init_pos(t_env *env);
void				define_env(t_env *e, int x);
void				find_color(t_env *env);
void				ft_verline(int x, int drawstart, int drawend, t_env *env);
void				start_raycasting(t_env *env);
int					expose_hook(t_env *env);
void				ft_right_left_key(t_env *e, int key);
int					key_hook(int keycode, t_env *e);
void				drop_map(t_env *env, char *map);

#endif
