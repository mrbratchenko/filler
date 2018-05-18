/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:46:50 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/24 17:46:53 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visual.h"

void		ft_paralel_projection(t_struct *ptrs, t_node *node)
{
	while (node && node->next)
	{
		ft_axis_rotation(ptrs, node);
		node->temp_z = ptrs->win_height / ptrs->zoom;
		node->temp_x = node->temp_x * node->temp_z + (ptrs->win_height / 2);
		node->temp_y = node->temp_y * node->temp_z + (ptrs->win_height / 2);
		node->i = (node->temp_x * ptrs->img_a) + (node->temp_y * ptrs->img_b);
		node = node->next;
	}
}

void		ft_axis_rotation(t_struct *ptrs, t_node *node)
{
	node->centr_x = (node->x - ptrs->map_length / 2);
	node->centr_y = (node->y - ptrs->map_width / 2);
	node->temp_x =
		node->centr_x * cos(ptrs->z_angle) - node->centr_y * sin(ptrs->z_angle);
	node->temp_y =
		node->centr_x * sin(ptrs->z_angle) + node->centr_y * cos(ptrs->z_angle);
	node->temp_y =
		node->temp_y * cos(-ptrs->x_angle) + node->z * sin(-ptrs->x_angle);
	node->temp_z =
		node->temp_y * sin(ptrs->x_angle) + node->z * cos(ptrs->x_angle);
	node->temp_x = node->temp_x + ptrs->moved_x;
	node->temp_y = node->temp_y + ptrs->moved_y;
}

void		ft_put(t_struct *ptrs, int x, int y, int color)
{
	int i;

	i = (x * ptrs->img_a) + (y * ptrs->img_b);
	if (x < 0 || x > 999 || y < 0 || y > 999)
		return ;
	ptrs->image[i] = color;
	ptrs->image[++i] = color >> 8;
	ptrs->image[++i] = color >> 16;
}

void		ft_draw_sq(t_struct *ptrs, t_node *node, int x, int y)
{
	int color;
	int k;
	int l;

	color = 0;
	if (node->symbol == 'X')
		color = ptrs->pl2color;
	else if (node->symbol == 'O')
		color = ptrs->pl1color;
	k = 0;
	while (k < node->dx)
	{
		l = 0;
		while (l < node->dx)
		{
			ft_put(ptrs, x + k, y + l, color);
			l++;
		}
		k++;
	}
}

void		ft_multiple_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
