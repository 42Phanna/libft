/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 14:16:22 by phanna            #+#    #+#             */
/*   Updated: 2019/04/29 16:13:21 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define SUCCESS 1
# define ERROR -1
# define BUFF_SIZE 4096
# define FD_MAX 10240

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_create_elem(void *data);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));

void			ft_delmap(int **map, int x, int y);
void			ft_deltab(char **tab);
void			ft_lstdelone(t_list **alst, void (*del) (void*, size_t));
void			ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f) (t_list *elem));
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int nb, int fd);
void			ft_striter(char *s, void(*f) (char *));
void			ft_striteri(char *s, void(*f) (unsigned i, char *));
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);

char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_ftoa(float f, int d);
char			*ft_uitoa_base(unsigned int n, int base);
char			*ft_ltoa(long long nb);
char			*ft_ultoa(unsigned long long n);
char			*ft_ultoa_base(unsigned long long n, int base);
char			*ft_strnew(size_t size);
char			*ft_strstr(const char *str, const char *tofind);
char			*ft_strnstr(const char *str, const char *tofind, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strmap(char const *s, char(*f) (char));
char			*ft_strmapi(char const *s, char(*f) (unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *str, char c);
char			*ft_strlowcase(char *str);
char			*ft_strcapitalize(char *str);
char			ft_toupper(char c);
char			ft_tomin(char c);

int				ft_str_is_alpha(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_uppercase(char *str);
int				ft_str_is_printable(char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_intlen(int n);
int				ft_uintlen(unsigned int n);
int				ft_uintlen_base(unsigned int n, int base);
int				ft_sqrt(int nb);
int				ft_factorial(int nb);
int				ft_power(int nb, int power);
int				ft_isspace(char c);
int				ft_atoi(char *str);
int				ft_linisdigit(char *str);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				get_next_line(const int fd, char **line);

long			ft_longlen(long n);
long			ft_recur_power_long(long long nb, int pow);

size_t			ft_strlen(const char *s);
size_t			ft_strlen_skip_white(const char *s);

#endif
