/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:43:09 by obajja            #+#    #+#             */
/*   Updated: 2024/12/19 13:37:47 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_freer(char **stash, char **temp, char **buffer);
int		ft_strchrs(char *s, int c);
char	*ft_strtqt(char **stash, char **trash);
char	*ft_strdupz(const char *src);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
