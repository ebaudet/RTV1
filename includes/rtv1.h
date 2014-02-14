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

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	o;
	t_vector	d;
}				t_ray;

typedef struct	s_sphere
{
	t_vector	position;
	double		radius;
}				t_sphere;


/*
** error.c
*/
void	ft_error(char *str);

/*
** rtv1.c
*/
void	rtv1(char *scene);
void	init_scene(char *scene);
void	display_scene();

/*
** vector.c
*/
void		vector_normalize(t_vector *v);
double		vector_dot(t_vector *a, t_vector *b);
t_vector	*vector_copy(t_vector *a);
t_vector	*vector_sub(t_vector *a, t_vector *b);

#endif /* !RTV1_H */