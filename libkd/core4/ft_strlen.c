/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:56:50 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/02 20:56:51 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libkd.h"

size_t	kd_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
