/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:15:15 by sbratche          #+#    #+#             */
/*   Updated: 2018/04/22 18:15:17 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void				ft_write_points(t_map *map, t_point *point, char *line)
{
	int		col;
	int		row;
	char	*str;

	row = 0;
	while (row < map->len)
	{
		get_next_line(0, &line);
		str = ft_strdup(line + 4);
		free(line);
		col = 0;
		while (col < map->wid)
		{
			point->x = row;
			point->y = col;
			point->symbol = str[col];
			point->next = ft_point_init();
			point = point->next;
			col++;
		}
		row++;
		free(str);
	}
}

void				ft_write_pieces(t_piece *piece, char *line, t_map *map)
{
	int		row;
	int		col;

	row = 0;
	while (row < map->piece_len)
	{
		col = 0;
		get_next_line(0, &line);
		while (col < map->piece_wid)
		{
			piece->x = row;
			piece->y = col;
			piece->symbol = line[col];
			piece->next = ft_piece_init();
			piece = piece->next;
			col++;
		}
		row++;
		free(line);
	}
}

void				ft_read_piece(t_piece *piece, t_map *map)
{
	char	*line;
	char	**splitted;

	get_next_line(0, &line);
	splitted = ft_strsplit(line, ' ');
	map->piece_len = ft_atoi(splitted[1]);
	map->piece_wid = ft_atoi(splitted[2]);
	ft_multiple_free(splitted);
	free(line);
	ft_write_pieces(piece, line, map);
}

void				ft_read_map(t_map *map, t_point *point, char *line)
{
	char	**splitted;

	splitted = ft_strsplit(line, ' ');
	map->len = ft_atoi(splitted[1]);
	map->wid = ft_atoi(splitted[2]);
	ft_multiple_free(splitted);
	get_next_line(0, &line);
	free(line);
	ft_write_points(map, point, line);
}

void				ft_get_player_nr(char *line, t_map *map)
{
	if (line[10] == '1')
	{
		map->player_symbol = 'O';
		map->enemy_symbol = 'X';
	}
	else
	{
		map->player_symbol = 'X';
		map->enemy_symbol = 'O';
	}
}
