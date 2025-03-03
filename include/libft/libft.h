/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajja <obajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:48:50 by obajja            #+#    #+#             */
/*   Updated: 2025/01/14 19:25:22 by obajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_calloc(size_t elementCount, size_t elementSize);
int					ft_isascii(int str);
char				**ft_strsdup(char **src, size_t size);
void				ft_freestrs(char **tab);
char				*ft_itoa(int n);
int					ft_putchar_pf(char c);
int					ft_putstr_pf(char *s);
void				*ft_memset(void *str, int a, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
char				*ft_strchr(const char *str, int tofind);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(const char *str);
char				*ft_strnstr(const char *str, const char *tofind, int n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
int					ft_isalnum(int str);
int					ft_isdigit(int str);
void				*ft_memcpy(void *dest, const void *src, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr(char *s);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strrchr(const char *str, int tofind);
int					ft_tolower(int c);
void				*ft_bzero(void *str, size_t n);
int					ft_isalpha(int str);
int					ft_isprint(int str);
void				*ft_memmove(void *dest, const void *src, size_t size);
void				*ft_memchr(const void *str, int searchedChar, size_t size);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void				ft_putendl_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *str1, const char *str2, int n);
char				*ft_strtrim(char const *s1, char const *s2);
int					ft_toupper(int c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_printf(const char *str, ...);
int					ft_printadress(unsigned long ptr);
int					ft_putchar_pf(char c);
int					ft_putstr_pf(char *s);
int					ft_putnbr_upf(unsigned int n, int *count);
int					ft_putnbr_pf(int n, int *count);
int					ft_putnbrhexalow(unsigned int n, int *count);
int					ft_putnbrhexaupp(unsigned int n, int *count);

#endif
