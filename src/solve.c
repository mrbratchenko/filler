/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:15:38 by sbratche          #+#    #+#             */
/*   Updated: 2018/04/22 18:15:39 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void		ft_find_manh(int sol_x, int sol_y, t_point *point, t_map *map)
{
	int			manh;
	t_point		*point_head;

	manh = 0;
	point_head = point;
	while (point && point->next)
	{
		if (point->symbol == map->enemy_symbol)
		{
			manh = ft_abs(sol_x - point->x) + ft_abs(sol_y - point->y);
			if (manh < map->manh)
			{
				map->manh = manh;
				map->ret_x = sol_x;
				map->ret_y = sol_y;
			}
		}
		point = point->next;
	}
	point = point_head;
}

void		ft_validate_position(t_piece *piece, t_map *map, t_point *point)
{
	t_point		*point_head;
	t_piece		*piece_head;
	int			flag;
	int			i;

	point_head = point;
	piece_head = piece;
	flag = 1;
	i = 0;
	while (piece && piece->next && piece->symbol != '*')
		piece = piece->next;
	while (piece && piece->next)
	{
		while (point->x != piece->temp_x || point->y != piece->temp_y)
			point = point->next;
		if (piece->symbol == '*' && point->symbol == map->player_symbol)
			i++;
		else if (piece->symbol == '*' && point->symbol == map->enemy_symbol)
			flag = 0;
		if (flag == 0 || i > 1)
			return ;
		piece = piece->next;
	}
	if (flag == 1 && i == 1)
		ft_find_manh(piece_head->temp_x, piece_head->temp_y, point_head, map);
}

void		ft_solve(t_piece *piece, t_map *map, t_point *point)
{
	t_point		*point_head;
	t_piece		*piece_head;
	int			add_x;
	int			add_y;

	map->manh = 10000;
	point_head = point;
	piece_head = piece;
	while (point && point->next)
	{
		add_x = point->x - piece->x;
		add_y = point->y - piece->y;
		while (piece && piece->next && add_x < map->len - map->piece_len + 1
									&& add_y < map->wid - map->piece_wid + 1)
		{
			piece->temp_x = piece->x + add_x;
			piece->temp_y = piece->y + add_y;
			piece = piece->next;
		}
		piece = piece_head;
		ft_validate_position(piece, map, point_head);
		point = point->next;
	}
}
