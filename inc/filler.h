/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:16:07 by sbratche          #+#    #+#             */
/*   Updated: 2018/04/22 18:16:08 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"

typedef struct		s_point
{
	int				x;
	int				y;
	char			symbol;
	struct s_point	*next;

}					t_point;

typedef struct		s_map
{
	char			player_symbol;
	char			enemy_symbol;
	int				len;
	int				wid;
	int				piece_len;
	int				piece_wid;
	int				manh;
	int				ret_x;
	int				ret_y;

}					t_map;

typedef struct		s_piece
{
	int				x;
	int				y;
	int				temp_x;
	int				temp_y;
	char			symbol;
	char			temp_symbol;
	struct s_piece	*next;

}					t_piece;

void				ft_output(int x, int y);
void				ft_get_player_nr(char *line, t_map *map);
void				ft_find_manh(int sol_x, int sol_y,
										t_point *point, t_map *map);
void				ft_validate_position(t_piece *piece, t_map *map,
													t_point *point);
void				ft_solve(t_piece *piece, t_map *map, t_point *point);
void				ft_read_map(t_map *map, t_point *point, char *line);
void				ft_read_piece(t_piece *piece, t_map *map);
int					main(void);
t_point				*ft_point_init(void);
t_map				*ft_map_init(void);
t_piece				*ft_piece_init(void);
int					ft_abs(int value);
void				ft_multiple_free(char **str);
void				ft_free_point(t_point *point);
void				ft_free_piece(t_piece *piece);
void				ft_filler(t_piece *piece, t_map *map,
										t_point *point, char *line);
void				ft_write_points(t_map *map, t_point *point, char *line);
void				ft_write_pieces(t_piece *piece, char *line, t_map *map);

#endif
