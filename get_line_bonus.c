/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarredon <jarredon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:10:15 by jarredon          #+#    #+#             */
/*   Updated: 2022/05/09 11:39:04 by jarredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#define BUFFER_SIZE 20

static int	ft_line_len(char *ptr)
{
	int	len;

	len = 0;
	while (ptr[len] && ptr[len] != '\n')
		len++;
	if (ptr[len] == '\n')
		len++;
	return (len);
}

static void	ft_clean_memory(char **memory)
{
	char	*new_memo;
	int		len;
	int		new_size;

	if (*memory == NULL)
	{
		*memory = (char *) malloc (sizeof(char));
		**memory = '\0';
		return ;
	}
	len = ft_line_len(*memory);
	new_size = ft_strlen(&(*memory)[len]) + 1;
	new_memo = (char *) malloc(sizeof(char) * new_size);
	ft_memcpy(new_memo, &(*memory)[len], new_size);
	free(*memory);
	*memory = new_memo;
}

static int	ft_fill_memory(char **memory, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;
	char	*tmp;

	ft_clean_memory(memory);
	ret = 1;
	while (!ft_strchr(*memory, '\n') && ret)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 1)
			return (ret);
		buffer[ret] = '\0';
		tmp = *memory;
		*memory = ft_strjoin(*memory, buffer);
		free(tmp);
	}
	return (ret);
}

static char	*ft_get_line(char **memory)
{
	char	*line;
	int		len;
	int		i;

	len = ft_line_len(*memory);
	if (len == 0)
		return (NULL);
	line = (char *) malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		line[i] = (*memory)[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*memory = NULL;
	char		*line;

	if (ft_fill_memory(&memory, fd) == -1)
	{
		free(memory);
		memory = NULL;
		return (NULL);
	}
	line = ft_get_line(&memory);
	if (!line)
	{
		free(memory);
		memory = NULL;
	}
	return (line);
}
