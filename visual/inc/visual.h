/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:08:16 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/10 15:24:11 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_H
# define FT_VISUAL_H

# include "mlx.h"
# include "../../libft/inc/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

int					get_next_line(const int fd, char **line);

typedef struct		s_node
{
	double			x;
	double			y;
	double			z;
	char			symbol;
	double			temp_x;
	double			temp_y;
	double			temp_z;
	int				i;
	double			centr_x;
	double			centr_y;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	struct s_node	*next;

}					t_node;

typedef struct		s_struct
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*image;
	int				img_a;
	int				img_b;
	int				img_c;
	int				map_length;
	int				map_width;
	double			win_height;
	double			x_angle;
	double			y_angle;
	double			z_angle;
	int				zoom;
	int				color;
	int				pl1color;
	int				pl2color;
	int				moved_x;
	int				moved_y;
	int				score1;
	int				score2;
}					t_struct;

t_node				*ft_node_init();
void				ft_ptrs_init(t_struct *ptrs);
void				ft_pixel_put(t_struct *ptrs, int x, int y);
void				ft_line(int flag, t_node *node,
									t_node *current, t_struct *ptrs);
void				ft_draw_lines(t_struct *ptrs, t_node *node);
void				ft_axis_rotation(t_struct *ptrs, t_node *node);
void				ft_paralel_projection(t_struct *ptrs, t_node *node);
void				ft_perspective_projection(t_struct *ptrs, t_node *node);
int					ft_mouse_close(void);
int					main(void);
void				ft_put(t_struct *ptrs, int x, int y, int color);
void				ft_draw_sq(t_struct *ptrs, t_node *node, int x, int y);
void				ft_init_strings(t_struct *ptrs, char *pl1, char *pl2);
void				ft_multiple_free(char **str);
int					ft_key(int key, t_struct *ptrs);
void				ft_get_score(t_struct *ptrs, char *line);

#endif
