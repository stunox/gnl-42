/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:24:59 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/27 11:19:04 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# define MAX_FD 1024

char			*add_str(char *str, char *buffer, int to_free);
char			*ft_strdup(char *s);
unsigned int	ft_strlen(char *s);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
char			*get_next_line(int fd);

#endif // GET_NEXT_LINE_BONUS_H 