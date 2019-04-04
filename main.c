/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 23:12:29 by pmore             #+#    #+#             */
/*   Updated: 2014/04/30 23:12:30 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				main(void)
{
	t_env			env;

	env.mlx_ptr = mlx_init();
	env.mlx_win = mlx_new_window(env.mlx_ptr, SCREENW, SCREENH, "wolf3d");
	drop_map(&env, "map");
	init_pos(&env);
	mlx_expose_hook(env.mlx_win, expose_hook, &env);
	mlx_hook(env.mlx_win, 2, 1, key_hook, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
