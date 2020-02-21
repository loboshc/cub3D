/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:52:02 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/02/20 21:02:17 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *s)
{
	ft_putstr_fd(s, 1);
	exit(EXIT_FAILURE);
}

void	free_and_null(void *obj)
{
	free(obj);
	obj = NULL;
}
