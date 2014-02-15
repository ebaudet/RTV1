/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 18:52:59 by ebaudet           #+#    #+#             */
/*   Updated: 2014/02/14 18:52:59 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"

# define WIDTH		1000
# define HEIGHT		1000
# define KEY_ESC	65307

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	*o;
	t_vector	*d;
}				t_ray;

typedef struct	s_sphere
{
	t_vector	*position;
	double		radius;
}				t_sphere;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	t_img		*img;
}				t_win;

/*
** error.c
*/
void	ft_error(char *str);

/*
** rtv1.c
*/
void	rtv1(char *scene);
void	init_scene(char *scene);
void	eb_mlx();
void	display_scene(t_img *img);

/*
** vector.c
*/
t_vector	*vector_new(double x, double y, double z);
void		vector_del(t_vector *vector);
void		vector_set(t_vector *vector, double x, double y, double z);
void		vector_normalize(t_vector *v);
double		vector_dot(t_vector *a, t_vector *b);
t_vector	*vector_copy(t_vector *a);
t_vector	*vector_sub(t_vector *a, t_vector *b);

/*
** sphere.c
*/
t_sphere	*sphere_new(double x, double y, double z, double radius);
void		sphere_del(t_sphere *sphere);
int			intersection_sphere(t_sphere *sphere, t_ray *ray, double *t);

/*
** env.c
*/
t_win	*env_init(void);
void	env_del(void);

/*
** image.c
*/
t_img		*img_init(void);
void		img_del(t_img *img);
void		eb_put_pixel_to_img(t_img *img, int x, int y, int color);

/*
** ray.c
*/
t_ray	*ray_new(void);
void	ray_del(t_ray *rayon);

/*
** hook.c
*/
int		eb_mlx_key_hook(int	keycode);
int		eb_expose_hook(t_img *img);

#endif /* !RTV1_H */