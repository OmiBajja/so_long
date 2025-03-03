/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:13:54 by obajja            #+#    #+#             */
/*   Updated: 2024/12/19 14:47:27 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s)
	{
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		if (s[start] == '\0')
		{
			str[0] = '\0';
			return (str);
		}
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

int	ft_strchrs(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdupz(const char *src)
{
	int		i;
	int		f;
	char	*cpy;

	f = 0;
	if (src)
	{
		while (src[f])
			f++;
		i = 0;
		cpy = malloc((f + 1) * sizeof(char));
		if (!cpy)
			return (NULL);
		while (src[i])
		{
			cpy[i] = src[i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	return (NULL);
}

char	*ft_strtqt(char **stash, char **trash)
{
	char	*str;

	str = NULL;
	if ((stash == NULL || *stash == NULL) && trash && *trash)
	{
		free(*trash);
		*trash = NULL;
		return (NULL);
	}
	if (stash && *stash)
	{
		str = ft_strdupz(*stash);
		free(*stash);
		*stash = NULL;
	}
	return (str);
}
