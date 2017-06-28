/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:01:30 by arosset           #+#    #+#             */
/*   Updated: 2017/05/17 14:01:38 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# define BIGGER(x, y) ((x > y) ? x : y)

typedef struct		s_gl
{
	char			*s;
	int				fd;
}					t_gl;

typedef struct		s_vark
{
	char			*buff;
	char			*tmp;
	t_gl			*gnl;
}					t_vark;

/*
**					DEFINE GNL
*/
# define BUFF_SIZE 32
# define ECON  		elem->content
# define ESIZE 		elem->content_size

/*
**					DEFINE PRINTF
*/
# define S_OPE 		cylva->operation
# define S_M_LEN 	cylva->m_lenght
# define S_PREC 	cylva->precision
# define S_MO_ZE 	cylva->f_mo_ze
# define S_DIESE 	cylva->f_diese
# define S_PL_SP 	cylva->f_pl_sp
# define S_STR 		cylva->str

/*
**					STRUCTURE LIST LIBFT
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**					STRUCTURE LIST GNL
*/
typedef struct		s_lgnl
{
	void			*content;
	size_t			content_size;
	struct s_lgnl	*next;
	int				fd;
}					t_gnl;
/*
**					STRUCTURE PRINTF
*/
typedef struct		s_args
{
	char			f_diese;
	char			f_pl_sp;
	char			f_mo_ze;
	int				len_print;
	int				width;
	int				precision;
	int				base;
	char			m_lenght;
	char			operation;
	wchar_t			wchar;
	wchar_t			*wstr;
	int				c;
	char			*str;
}					t_args;
/*
**					FONCTION GLOBAL
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_putchar(char c);
void				ft_put_n_char(char c, int n);
void				ft_putwchar(wchar_t wc);

void				ft_putstr(const char *s);
void				ft_put_len_str(char const *s, int len);
void				ft_putwstr(wchar_t *ws, int len);

void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

size_t				ft_strlen(const char *s);
int					ft_power(int n, int pow);

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strdup(const char *s1);

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, \
	size_t len);

char				*ft_strchr(char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_str_index(char *str, char c);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_min(int a, int b);
int					ft_max(int a, int b);

char				*ft_itoa_base(long long int value, int base);
int					nblen(long long int value, int base);
char				*ft_uitoa_base(unsigned long long int value, int base);
int					unblen(unsigned long long int value, int base);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);

void				ft_print_tab(char **tab);
void				ft_free_tab(char **tab);

int					get_next_line(int fd, char **line);
/*
**					FONCTION PRINTF
*/
int					ft_printf(char *format, ...);
void				ft_printf_init(char **format, t_args *cylva);
void				ft_convert(va_list ap, t_args *cylva);
long long int		ft_convert_nb(va_list ap, t_args *cylva);
long long int		ft_convert_uint(va_list ap, t_args *cylva);
long long int		ft_convert_int(va_list ap, t_args *cylva);
void				ft_error_tag(t_args *cylva);
void				ft_error_double_f(char **format, t_args *cylva);
void				ft_get_tag(char **format, t_args *cylva);
void				ft_get_length(char **fmt, t_args *cylva);
void				ft_get_precision(char **format, t_args *cylva);
void				ft_get_flags(char **format, t_args *cylva);
int					ft_str_max_print(t_args *cylva);
int					ft_nbr_max_print(long long int nbr, t_args *cylva);
void				ft_set_base(t_args *cylva);
int					ft_strchr_len(const char *str, char c);
void				ft_init_struct(t_args *cylva);
int					ft_str_len_print(const char *str, char c);
int					ft_wstrlen(wchar_t *ws, int max);
void				ft_print_str(t_args *cylva);
void				ft_print_nbr(t_args *cylva, long long int nbr);
void				ft_print_arg_nbr(t_args *cylva, int max, long long int nbr);
void				ft_print_base(t_args *cylva, long long int nbr);
void				ft_undefined(t_args *cylva, char **fmt, int total);

#endif
