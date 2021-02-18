/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:15:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/18 17:30:19 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define LIBFT_H


//	라이브러리
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_mms/mlx.h"

# define key_esc 53
# define key_w 13
# define key_a 0
# define key_s 1
# define key_d 2

//	구조체
typedef struct		s_win
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	int			*data;
	int			img_height;
}					t_win;

typedef struct		s_img
{
	void		*ptr;
	int			*data;
	int			height;
	int			width;
	int			size_l;
	int			bpp;
	int			endian;
}					t_img;

//	함수 프로토 타입 선언





#endif
