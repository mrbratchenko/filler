/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:15:04 by sbratche          #+#    #+#             */
/*   Updated: 2018/04/22 18:15:07 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void				ft_filler(t_piece *piece, t_map *map,
												t_point *point, char *line)
{
	t_piece		*piece_head;
	t_point		*point_head;

	point = ft_point_init();
	point_head = point;
	piece = ft_piece_init();
	piece_head = piece;
	ft_read_map(map, point, line);
	ft_read_piece(piece, map);
	ft_solve(piece, map, point);
	ft_output(map->ret_x, map->ret_y);
	ft_free_point(point_head);
	ft_free_piece(piece_head);
	free(line);
}

void				ft_multiple_free(char **str)
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

int					ft_abs(int value)
{
	if (value < 0)
		value = value * (-1);
	return (value);
}

void				ft_output(int x, int y)
{
	ft_putnbr_fd(x, 1);
	ft_putchar(' ');
	ft_putnbr_fd(y, 1);
	ft_putchar('\n');
}

int					main(void)
{
	char		*line;
	t_map		*map;
	t_point		*point;
	t_piece		*piece;

	point = NULL;
	piece = NULL;
	map = ft_map_init();
	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$ exec p", 10) != 0)
	{
		write(1, "please use as player with ./filler_vm\n", 38);
		return (1);
	}
	ft_get_player_nr(line, map);
	free(line);
	while (get_next_line(0, &line))
		ft_filler(piece, map, point, line);
	return (0);
}
