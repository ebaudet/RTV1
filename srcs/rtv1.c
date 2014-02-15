/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:53:48 by ebaudet           #+#    #+#             */
/*   Updated: 2014/02/14 18:53:48 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include "rtv1.h"

void	rtv1(char *scene)
{
	(void)scene;
	/*init_scene(scene);*/
	eb_mlx();
}

void	init_scene(char *scene)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(scene, O_RDONLY)) == -1)
		ft_error("fichier incorrect");
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// TODO : definir la structure des fichiers scène.
	}
}

void	eb_mlx()
{
	t_win		*env;
	t_img		*img;

	env = env_init();
	img = img_init();
	mlx_expose_hook(env->win, eb_expose_hook, img);
	mlx_key_hook(env->win, eb_mlx_key_hook, NULL);
	mlx_loop(env->mlx);
}

#include <stdio.h>

void	display_scene(t_img *img)
{
	t_sphere	*sphere;
	t_vector	*a;
	t_vector	b;
	int			x;
	int			y;
	t_vector	ray_dir;
	t_ray		*rayon;
	double		coef;
	int			intersection;

	sphere = sphere_new(0, 0, 0, 300);
	a = vector_new(0, 0, -(WIDTH / (2 * tan(M_PI / 12))));
	y = 0;
	rayon = ray_new();
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			b.x = x - (WIDTH / 2);
			b.y = y - (HEIGHT / 2);
			b.z = 0;
			/*vector_normalize(&b);*/
			ray_dir.x = b.x - a->x;
			ray_dir.y = b.y - a->y;
			ray_dir.z = b.z - a->z;
			vector_normalize(&ray_dir);
			vector_set(rayon->o, a->x, a->y, a->z);
			vector_set(rayon->d, ray_dir.x, ray_dir.y, ray_dir.z);
			/*printf("norme = %f, ", vector_dot(&ray_dir, &ray_dir));*/
			coef = 200000;
			intersection = intersection_sphere(sphere, rayon, &coef);
			if (intersection != -1 && coef < 200000)
			{
				eb_put_pixel_to_img(img, x, y, 0xFF0000);
				/*ft_putchar('[');
				ft_putnbr(x);
				ft_putchar(',');
				ft_putnbr(y);
				ft_putchar(']');*/
			}
			x++;
		}
		y++;
	}
}
