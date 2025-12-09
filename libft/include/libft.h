/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncorrear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 21:07:35 by ncorrear          #+#    #+#             */
/*   Updated: 2025/12/07 10:25:16 by ncorrear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define FT_MOD(a, b) (((a) % (b) + (b)) % (b))

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_dict_node
{
	char				*key;
	void				*content;
	struct s_dict_node	*next;
}	t_dict_node;

typedef struct s_dict
{
	t_dict_node	*entry;
	size_t		size;
}	t_dict;

// char
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

// string
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, size_t start, size_t len);
char		*ft_strjoin(char const *s1, const char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strndup(const char *str, size_t n);

// memory
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);

// write
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// chained list
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new_node);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new_node);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// dict
t_dict		*ft_dict_new(void);
t_dict_node	*ft_dict_set(t_dict *dict, char *key, void *value);
void		*ft_dict_get(t_dict *dict, char *key);
t_dict_node	*ft_dict_get_node(t_dict *dict, char *key);
t_dict_node	*ft_dict_new_node(char *key, void *content);
void		ft_dict_clear_node(t_dict_node *node, void (*del)(void *));
void		ft_dict_clear(t_dict *dict, void (*del)(void *));
void		ft_dict_unset(t_dict *dict, char *key);

// utils
void		free_2d(void **tab, void (*del)(void *));

#endif
