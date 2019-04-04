/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 21:02:13 by pmore             #+#    #+#             */
/*   Updated: 2013/11/30 21:02:16 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		f(&s[i]);
		i++;
	}
}
