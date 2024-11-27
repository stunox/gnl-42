/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:24:50 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/27 11:17:38 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (start > (ft_strlen(s) - 1) || len == 0)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

int	parse_line(char *buf, char **line, char **temp, int *nb)
{
	*line = add_str(*line, add_str(ft_substr(buf, 0, nb[0]), "\n", 0), 1);
	free(*temp);
	if (nb[0] == nb[1] - 1)
		*temp = NULL;
	else
		*temp = ft_strdup(&buf[nb[0] + 1]);
	return (1);
}

static int	get_line(char *buf, char **temp, char **line, int n)
{
	int	*i;

	i = (int [3]){0, ft_strlen(*line), 0};
	while (line && *line && i[0] < i[1] && (*line)[i[0]] != '\n')
		i[0]++;
	if (i[0] < i[1] && (*line)[i[0]] == '\n')
	{
		*temp = add_str(ft_strdup(&(*line)[i[0] + 1]), *temp, 1);
		(*line)[i[0] + 1] = '\0';
		return (1);
	}
	while (i[2] < n && buf && buf[i[2]] != '\n')
		i[2]++;
	if (i[2] == n && buf && buf[i[2]] != '\n')
		*line = add_str(*line, buf, 0);
	else if (buf)
		return (parse_line(buf, line, temp, (int [2]){i[2], n}));
	return (0);
}

int	load_temp(char **temp, char **line, int fd)
{
	char	*new_temp;
	int		i;

	*line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FD)
		return (-1);
	i = 0;
	if (!temp[fd])
		return (0);
	while ((temp[fd])[i] && (temp[fd])[i] != '\n')
		i++;
	if ((temp[fd])[i] == '\n')
	{
		*line = ft_substr(temp[fd], 0, i + 1);
		new_temp = ft_strdup(&(temp[fd])[i + 1]);
		free(temp[fd]);
		temp[fd] = new_temp;
		return (1);
	}
	*line = ft_strdup(temp[fd]);
	free(temp[fd]);
	temp[fd] = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp[MAX_FD];
	char		*buf;
	int			n;

	if (load_temp(temp, &line, fd) != 0)
		return (line);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (buf)
	{
		n = read(fd, buf, BUFFER_SIZE * (temp[fd] == NULL));
		if (n <= 0 || buf[0] == '\0')
		{
			if ((n == 0 && line))
				break ;
			free(line);
			line = NULL;
			break ;
		}
		buf[n] = '\0';
		if (get_line(buf, &(temp[fd]), &line, n))
			break ;
	}
	free(buf);
	return (line);
}

// TODO : remove this 

// #include <stdio.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	int i = 0;
// 	while (line != NULL && i < 10)
// 	{
// 		i++;
// 		printf("Line : [%s]\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	printf("line : %s\n", get_next_line(fd));
// 	free(line);
// 	printf("index : %d\n", i);
// 	close(fd);
// 	return (0);
// }