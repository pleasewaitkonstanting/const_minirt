/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eni.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2022/01/27 16:57:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	*eni(void *ptr)
{
	if (!ptr)
	{
		kd_free_all();
		kd_exit("Error\nmlx_xpm_file_to_image() is null\n");
	}
	return (ptr);
}
