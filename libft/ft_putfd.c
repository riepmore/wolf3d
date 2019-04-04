/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 16:33:27 by pierremore        #+#    #+#             */
/*   Updated: 2014/10/21 16:46:33 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putchar_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}

int			ft_putstr_fd(int fd, char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (write(fd, str, i));
}
