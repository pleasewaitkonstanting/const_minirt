/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:52:04 by swilmer           #+#    #+#             */
/*   Updated: 2022/01/27 03:03:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libkd.h"

void	kd_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		kd_lstlast(*lst)->next = new;
	else
		*lst = new;
}
