/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:08:48 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/09 19:10:15 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libkd.h"

int	kd_count_strings(char **strings)
{
	int	i;

	i = 0;
	while (*strings++)
		i++;
	return (i);
}
