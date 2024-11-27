/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/13 11:25:20 by nbasheer          #+#    #+#             */
/*   Updated: 2024/10/13 11:25:20 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_args(char *str, char *buffer, int to_free, char **new_str)
{
	if (!buffer)
	{
		*new_str = ft_strdup(str);
		if (to_free)
			free(str);
		return (0);
	}
	if (!str)
	{
		*new_str = ft_strdup(buffer);
		if (to_free)
			free(buffer);
		return (0);
	}
	return (1);
}

char	*add_b_str(char *str, char *buffer, int to_free)
{
	char			*new_str;
	unsigned int	i;
	int				j;

	i = 0;
	new_str = NULL;
	if (!check_args(str, buffer, to_free, &new_str))
		return (new_str);
	new_str = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buffer) + 1));
	if (!new_str)
		return (NULL);
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		new_str[i++] = buffer[j++];
	new_str[i] = '\0';
	free(str);
	if (to_free)
		free(buffer);
	return (new_str);
}

char	*ft_strdup(char *s)
{
	char	*res;
	int		i;

	if (!s || !*s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

unsigned int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
