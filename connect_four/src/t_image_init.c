/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:27:51 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/07 19:29:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "connect.h"
#include "ft_mem.h"

t_image	*t_image_init(void *mlx_ptr, int img_width, int img_height)
{
	t_image	*img;

	if (mlx_ptr == NULL || img_width < 0 || img_height < 0)
		return (NULL);
	img = (t_image *) ft_calloc(1, sizeof(t_image));
	if (img == NULL)
		return (NULL);
	img->ptr = mlx_new_image(mlx_ptr, img_width, img_height);
	if (img->ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len, &img->endian);
	if (img->addr == NULL)
	{
		mlx_destroy_image(mlx_ptr, img->ptr);
		free(img);
		return (NULL);
	}
	img->width = img_width;
	img->height = img_height;
	img->bpp_factor = img->bpp / 8;
	return (img);
}

void	t_image_destroy(void *mlx_ptr, t_image *img, bool free_ptr)
{
	if (mlx_ptr == NULL || img == NULL || img->ptr == NULL)
		return ;
	mlx_destroy_image(mlx_ptr, img->ptr);
	img->ptr = NULL;
	if (free_ptr)
		free(img);
}
