/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-bayd <tal-bayd@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 09:27:39 by tal-bayd          #+#    #+#             */
/*   Updated: 2024/06/29 09:27:40 by tal-bayd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_next(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	line = (char *)malloc((ft_strlen(save) - i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		line[j++] = save[i++];
	line[j] = '\0';
	free(save);
	return (line);
}

char	*ft_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(char *save, int fd)
{
	char	*line;
	int		read_byte;

	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, line, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(line);
			free(save);
			return (NULL);
		}
		line[read_byte] = '\0';
		if (!save)
			save = ft_strdup("");
		save = ft_free(save, line);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(line);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_file(save, fd);
	if (!save)
		return (NULL);
	buffer = ft_line(save);
	save = ft_next(save);
	return (buffer);
}
