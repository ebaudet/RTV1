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

#include <math.h>
#include <fcntl.h>
#include "rtv1.h"

void	rtv1(char *scene)
{
	/*init_scene(scene);*/
	display_scene();
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

void	display_scene()
{
	t_sphere	sphere;
	t_vector	a;
	t_vector	b;
	int			x;
	int			y;
	t_ray		ray_direction;
	t_ray		rayon;
	double		coef;
	int			intersection;
	t_win		*env;
	t_img		*img;

	env = env_init();
	img = img_init();
	sphere = sphere_new(0, 0, 200, 20 * 2);
	a = vector_new(0, 0, -1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			b->x = x - (WIDTH / 2);
			b->y = y = (HEIGHT / 2);
			b->x = -(WIDTH / (2 * tan(30 / 2)));
			vector_normalize(b);
			ray_direction->x = b->x - a->x;
			ray_direction->y = b->y - a->y;
			ray_direction->z = b->z - a->z;
			vector_normalize(ray_direction);
			rayon->o->x = a->x;
			rayon->o->y = a->y;
			rayon->o->z = a->z;
			rayon->d->x = ray_direction->x;
			rayon->d->y = ray_direction->y;
			rayon->d->z = ray_direction->z;
			coef = 20000;
			intersection = intersection_sphere(sphere, rayon, &coef);
			if (intersection != -1 && coef < 20000)
				eb_put_pixel_to_img(img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}