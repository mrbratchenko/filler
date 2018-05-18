/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:59:56 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/19 21:00:19 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visual.h"

t_node			*ft_node_init(void)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		free(node);
	node->x = 0;
	node->y = 0;
	node->z = 0;
	node->symbol = '\0';
	node->i = 0;
	node->temp_x = 0;
	node->temp_y = 0;
	node->temp_z = 0;
	node->centr_x = 0;
	node->centr_y = 0;
	node->dx = 0;
	node->dy = 0;
	node->sx = 0;
	node->sy = 0;
	node->x0 = 0;
	node->y0 = 0;
	node->x1 = 0;
	node->y1 = 0;
	node->next = NULL;
	return (node);
}

void			ft_ptrs_init(t_struct *ptrs)
{
	ptrs->mlx_ptr = mlx_init();
	ptrs->win_ptr = mlx_new_window(ptrs->mlx_ptr, 1000, 1000, "mlx 42");
	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, 1000, 1000);
	ptrs->img_a = 0;
	ptrs->img_b = 0;
	ptrs->img_c = 0;
	ptrs->image = mlx_get_data_addr(ptrs->img_ptr,
					&ptrs->img_a, &ptrs->img_b, &ptrs->img_c);
	ptrs->map_length = 0;
	ptrs->map_width = 0;
	ptrs->win_height = 1000;
	ptrs->x_angle = 0;
	ptrs->y_angle = 0;
	ptrs->z_angle = 0;
	ptrs->zoom = 70;
	ptrs->color = 255;
	ptrs->pl1color = 10092441;
	ptrs->pl2color = 16751001;
	ptrs->moved_x = 0;
	ptrs->moved_y = 0;
	ptrs->score1 = 0;
	ptrs->score2 = 0;
}

void			ft_init_strings(t_struct *ptrs, char *pl1, char *pl2)
{
	int		color1;
	int		color2;
	char	*s1;
	char	*s2;

	s1 = ft_itoa(ptrs->score1);
	s2 = ft_itoa(ptrs->score2);
	color1 = ptrs->score1 > ptrs->score2 ? 65280 : 16711680;
	color2 = ptrs->score1 > ptrs->score2 ? 16711680 : 65280;
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 50, 100,
		ptrs->pl1color, pl1);
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 350, 100,
		color1, s1);
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 50, 125,
		ptrs->pl2color, pl2);
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 350, 125,
		color2, s2);
	free(s1);
	free(s2);
}

int				ft_key(int key, t_struct *ptrs)
{
	if (key == 53)
	{
		mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
		exit(0);
	}
	return (0);
}

void			ft_get_score(t_struct *ptrs, char *line)
{
	char *str;

	str = ft_strdup(line + 10);
	ptrs->score1 = ft_atoi(str);
	free(str);
	free(line);
	get_next_line(0, &line);
	str = ft_strdup(line + 10);
	ptrs->score2 = ft_atoi(str);
	free(line);
	free(str);
}
