/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 00:56:14 by ebaudet           #+#    #+#             */
/*   Updated: 2014/02/15 00:56:14 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "rtv1.h"

int		eb_mlx_key_hook(int	keycode)
{
	if (keycode == KEY_ESC)
	{
		ft_error("Merci pour le poisson.");
	}
	return (0);
}

int		eb_expose_hook(t_img *img)
{
	t_win		*env;

	env = env_init();
	display_scene(img);
	mlx_put_image_to_window(env->mlx, env->win, img->img, 0, 0);
	return (0);
}
