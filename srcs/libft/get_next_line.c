/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:41:47 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/24 09:44:46 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s, size_t n)
{
	unsigned int	i;
	char			*dup;

	if (!(dup = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*reader(char **file, char *buff, int fd)
{
	char		*tmp;
	int			ret;

	ret = 1;
	while (!(ft_strchr(*file, '\n')) && ret)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret)
		{
			if (buff[0] == 0)
				return (NULL);
			buff[ret] = '\0';
			tmp = *file;
			if (!(*file = ft_strjoin(tmp, buff)))
				return (NULL);
			free(tmp);
		}
	}
	free(buff);
	return (*file);
}

char	*liner(char **file)
{
	char	*buff;
	char	*ret;
	char	*tmp;

	buff = ft_strchr(*file, '\n');
	tmp = NULL;
	if (buff)
	{
		if (!(ret = ft_strndup(*file, buff - *file)))
			return (NULL);
		tmp = *file;
		if (!(*file = ft_strdup(buff + 1)))
			return (NULL);
		free(tmp);
	}
	else if (!(ret = ft_strdup(*file)))
		return (NULL);
	if (!(*file) || !tmp)
	{
		free(*file);
		*file = NULL;
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char	*file = NULL;
	char		*buff;

	if (!line || BUFF_SIZE <= 0 || !(buff = ft_strnew(BUFF_SIZE + 1)) \
		|| read(fd, buff, 0) == -1 || (file == NULL && !(file = ft_strnew(0))))
		return (-1);
	if (!(reader(&file, buff, fd)))
		return (-1);
	if (*file)
	{
		if (!(*line = liner(&file)))
			return (-1);
		return (1);
	}
	return (0);
}
