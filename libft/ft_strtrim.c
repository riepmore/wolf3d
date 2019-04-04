/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/27 19:35:04 by pierremore        #+#    #+#             */
/*   Updated: 2014/10/29 00:53:06 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			find_len1(char *str)
{
	int		len1;

	len1 = 0;
	while (str[len1] == ' ' || str[len1] == '\t')
		len1++;
	return (len1);
}

char		*ft_strtrim(char *str)
{
	char	*new_str;
	int		i;
	int		len1;
	int		len2;

	len1 = find_len1(str);
	len2 = 0;
	i = ft_strlen(str) - 1;
	while (str[i] == ' ' || str[i] == '\t')
	{
		i--;
		len2++;
	}
	new_str = malloc(sizeof(char *) * ft_strlen(str) - (len1 + len2) + 1);
	len2 = i + 1;
	i = 0;
	while (len1 < len2)
	{
		new_str[i] = str[len1];
		len1++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
