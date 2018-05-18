/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:28:58 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/10 15:31:58 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visual.h"

void				free_node(t_node *node)
{
	t_node *curr;

	curr = node;
	while (node != NULL)
	{
		curr = node;
		free(curr);
		node = node->next;
	}
}

static void			ft_read_file(t_struct *ptrs, t_node *node, int rows)
{
	int		columns;
	char	*str;
	char	*line;

	while (rows <= ptrs->map_length)
	{
		get_next_line(0, &line);
		columns = 0;
		str = ft_strdup(line + 4);
		free(line);
		while (columns <= ptrs->map_width)
		{
			node->x = columns;
			node->y = rows;
			node->symbol = str[columns];
			node->next = ft_node_init();
			node = node->next;
			columns++;
		}
		free(str);
		rows++;
	}
	ptrs->map_length = columns;
	ptrs->map_width = rows;
	ptrs->zoom = ptrs->map_length * 2;
}

void				ft_draw(t_struct *ptrs, t_node *node, char *line)
{
	char	**splitted;
	t_node	*head;

	node = ft_node_init();
	head = node;
	splitted = ft_strsplit(line, ' ');
	ptrs->map_length = ft_atoi(splitted[1]);
	ptrs->map_width = ft_atoi(splitted[2]);
	ft_multiple_free(splitted);
	free(line);
	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, 1000, 1000);
	ptrs->image = mlx_get_data_addr(ptrs->img_ptr,
						&ptrs->img_a, &ptrs->img_b, &ptrs->img_c);
	ptrs->img_a /= 8;
	get_next_line(0, &line);
	free(line);
	ft_read_file(ptrs, node, 0);
	ft_paralel_projection(ptrs, node);
	ft_draw_lines(ptrs, node);
	mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr,
		ptrs->img_ptr, 0, 0);
	mlx_destroy_image(ptrs->mlx_ptr, ptrs->img_ptr);
	free_node(head);
}

static int			ft_init_graphics(t_struct *ptrs, t_node *node,
													char *pl1, char *pl2)
{
	char	*line;

	ft_ptrs_init(ptrs);
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "Plateau", 7) == 0)
			ft_draw(ptrs, node, line);
		else if (ft_strncmp(line, "== O fin:", 9) == 0)
		{
			ft_get_score(ptrs, line);
		}
		else
			free(line);
	}
	ft_init_strings(ptrs, pl1, pl2);
	mlx_hook(ptrs->win_ptr, 2, 5, ft_key, ptrs);
	mlx_loop(ptrs->mlx_ptr);
	return (0);
}

int					main(void)
{
	char		*line;
	t_node		*node;
	t_struct	*ptrs;
	char		*str;

	node = NULL;
	if (!(ptrs = (t_struct *)malloc(sizeof(t_struct))))
		free(ptrs);
	while (get_next_line(0, &line))
	{
		if (line[0] == '$')
			break ;
		free(line);
	}
	str = ft_strdup(line + 14);
	free(line);
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	free(line);
	ft_init_graphics(ptrs, node, str, ft_strdup(line + 14));
	free(str);
	sleep(1000);
	return (0);
}
