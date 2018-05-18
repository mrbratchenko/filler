/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:15:26 by sbratche          #+#    #+#             */
/*   Updated: 2018/04/22 18:15:28 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_map				*ft_map_init(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		free(map);
	map->player_symbol = '\0';
	map->enemy_symbol = '\0';
	map->len = 0;
	map->wid = 0;
	map->piece_len = 0;
	map->piece_wid = 0;
	map->manh = 0;
	map->ret_x = 0;
	map->ret_y = 0;
	return (map);
}

t_point				*ft_point_init(void)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		free(point);
	point->x = 0;
	point->y = 0;
	point->symbol = '\0';
	point->next = NULL;
	return (point);
}

t_piece				*ft_piece_init(void)
{
	t_piece	*piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		free(piece);
	piece->x = 0;
	piece->y = 0;
	piece->temp_x = -1;
	piece->temp_y = -1;
	piece->symbol = '\0';
	piece->next = NULL;
	return (piece);
}

void				ft_free_point(t_point *point)
{
	t_point *curr;

	curr = point;
	while (point != NULL)
	{
		curr = point;
		free(curr);
		point = point->next;
	}
}

void				ft_free_piece(t_piece *piece)
{
	t_piece *curr;

	curr = piece;
	while (piece != NULL)
	{
		curr = piece;
		free(curr);
		piece = piece->next;
	}
}
