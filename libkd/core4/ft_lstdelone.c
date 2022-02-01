/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:52:29 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 01:27:12 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libkd.h"

void	kd_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	lst = kd_free(lst);
}
