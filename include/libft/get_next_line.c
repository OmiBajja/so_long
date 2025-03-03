/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:42:45 by obajja            #+#    #+#             */
/*   Updated: 2024/12/19 15:07:35 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*line_printer(char *stash, int *i)
{
	char	*line;
	int		c;

	c = 0;
	line = NULL;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while ((stash[c]))
	{
		if (stash[c] == '\n')
		{
			line = ft_substr(stash, 0, c + 1);
			*i = c + 1;
			return (line);
		}
		c++;
	}
	*i = c;
	line = ft_substr(stash, 0, c);
	return (line);
}

char	*ft_strjoinz(char *s1, char *s2, int lens1, int lens2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_reader(int fd, char *stash, int *r)
{
	char	*buffer;
	char	*temp;
	int		lenstash;

	lenstash = 0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (lenstash < BUFFER_SIZE)
		buffer[lenstash++] = '\0';
	lenstash = 0;
	*r = read(fd, buffer, BUFFER_SIZE);
	if (*r < 0)
		return (free(buffer), NULL);
	if (*r == 0)
		return (free(buffer), stash);
	buffer[*r] = '\0';
	while (stash[lenstash])
		lenstash++;
	temp = ft_strjoinz(stash, buffer, lenstash, *r);
	free (stash);
	stash = temp;
	return (free(buffer), stash);
}

char	*line_checker(int fd, int i, int r, char **stash)
{
	char	*line;
	char	*temp;

	line = NULL;
	temp = NULL;
	while (r != 0 && !ft_strchrs(*stash, '\n'))
	{
		*stash = ft_reader(fd, *stash, &r);
		if (!*stash || *stash == NULL)
			return (NULL);
	}
	line = line_printer(*stash, &i);
	if ((*stash)[i])
	{
		temp = ft_strdupz(&(*stash)[i]);
		free(*stash);
		*stash = NULL;
		*stash = temp;
	}
	else if (r < BUFFER_SIZE || !(*stash)[i])
	{
		ft_strtqt(NULL, &(*stash));
		*stash = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		ft_strtqt(NULL, &stash);
		return (NULL);
	}
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	str = line_checker(fd, 0, 1, &stash);
	if (!str || *str == '\0')
	{
		free(str);
		if (stash)
			ft_strtqt(NULL, &stash);
		return (NULL);
	}
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	static int fd;
// 	char *line = NULL;

// 	// fd = open("numbers", O_RDONLY);
// 	fd = open("test.txt", O_RDONLY);
// 	// if (fd < 0)
// 	// 	return (0);
// 	// fd = 24;
// 	int i = 0;
// 	while (i < 3)
// 	{
// 		line = get_next_line(fd);
// 		i++;
// 		printf("Line: %s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }