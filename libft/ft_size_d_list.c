/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_d_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:53:34 by theo              #+#    #+#             */
/*   Updated: 2014/01/07 13:50:41 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_size_d_list(d_list *list)
{
	size_t		ret;

	ret = 0;
	if (list != NULL)
	{
		ret = list->length;
	}
	return (ret);
}