/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:43:41 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/23 12:54:33 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(src) + 1;
	dup = (char *)malloc(sizeof(char) * len);
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
