/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanna <phanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 09:07:33 by phanna            #+#    #+#             */
/*   Updated: 2019/01/24 15:23:50 by phanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ================
** |			  |
** |   Includes	  |
** |			  |
** ================
*/

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

/*
** ===============
** |			 |
** |	Macros	 |
** |			 |
** ===============
*/

# define BUFF_SIZE_PTF 4096
# define D_SIZE 64

/*
** ===============
** |			 |
** |	Struct	 |
** |			 |
** ===============
*/

typedef struct	s_printf
{
	va_list		ap;
	char		str[BUFF_SIZE_PTF];
	int			i;
	int			j;
	int			len;
	void		(*funptr[58])();
}				t_printf;

typedef struct	s_check
{
	char		option;
	char		modif;
	int			width;
	int			prec;
	int			ifprec;
	int			ifplus;
	int			minos;
	int			plus;
	int			zero;
	int			space;
	int			hash;
	int			to_fill;
	int			to_fill_s;
	int			to_fill_z;
	int			len;
}				t_check;

typedef struct	s_conv
{
	char		c;
	void		(*conv)(t_printf*, t_check*);
}				t_conv;

/*
** ===============
** |	Core	 |
** |			 |
** |  functions	 |
** ===============
*/

int				ft_printf(const char *format, ...);
void			test_char(const char *format, t_printf *box);
void			fill_str(t_printf *box, char c);
void			cmp_fill(t_check *flag, int arg);
void			cmp_fill_prec(t_check *flag, int arg);
void			cmp_fill_o(t_check *flag, int arg);
void			cmp_fill_o_prec(t_check *flag, int arg);
void			cmp_fill_x(t_check *flag);
void			cmp_fill_prec_x(t_check *flag, int arg);
void			cmp_fill_prec_x2(t_check *flag);
void			fill_void(t_printf *box, t_check *flag, const char *str);
void			fill_void_prec(t_printf *box, t_check *flag, const char *str
	, int arg);
void			fill_void_prec2(t_printf *box, t_check *flag, const char *str
	, int arg);

void			fill_void_o(t_printf *box, t_check *flag, const char *str);
void			fill_void_prec_o(t_printf *box, t_check *flag, const char *str
	, int a);
void			fill_void_prec_o2(t_printf *box, t_check *flag, const char *str
	, int arg);
void			fill_void_prec_u(t_printf *box, t_check *flag, const char *str
	, int arg);
void			fill_void_prec_u2(t_printf *box, t_check *flag, const char *str
	, int arg);
void			fill_void_prec_x(t_printf *box, t_check *flag, const char *str
	, int a);
void			fill_void_prec_x2(t_printf *box, t_check *flag, const char *s);
void			fill_void_prec_x_up(t_printf *box, t_check *flag, const char *s
	, int a);
void			fill_void_prec_x_up2(t_printf *box, t_check *flag
	, const char *s);
void			w_fill(t_check *flag, int arg);

/*
** ===============
** |	Check	 |
** |			 |
** |  functions	 |
** ===============
*/

void			check_option(const char *format, t_printf *box);
void			check_width_prec(const char *format, t_printf *box
	, t_check *flag);
void			check_modif(const char *format, t_printf *box, t_check *flag);
void			check_conv(const char *format, t_printf *box, t_check *flag);

/*
** ===============
** |   Choose	 |
** |			 |
** |   convs	 |
** ===============
*/

void			choose_conv_d(t_printf *box, t_check *flag);
void			choose_conv_ld(t_printf *box, t_check *flag);
void			choose_conv_f(t_printf *box, t_check *flag);
void			choose_conv_o(t_printf *box, t_check *flag);
void			choose_conv_lo(t_printf *box, t_check *flag);
void			choose_conv_x(t_printf *box, t_check *flag);
void			choose_conv_x_up(t_printf *box, t_check *flag);

/*
** ===============
** |	Conv	 |
** |			 |
** |  functions	 |
** ===============
*/

void			conv_c(t_printf *box, t_check *flag);
void			conv_s(t_printf *box, t_check *flag);
void			conv_100(t_printf *box, t_check *flag);
void			conv_p(t_printf *box, t_check *flag);

void			conv_d(t_printf *box, t_check *flag);
void			conv_hd(t_printf *box, t_check *flag);
void			conv_ld(t_printf *box, t_check *flag);
void			conv_zd(t_printf *box, t_check *flag);

void			conv_d_prec(t_printf *box, t_check *flag);
void			conv_hd_prec(t_printf *box, t_check *flag);
void			conv_ld_prec(t_printf *box, t_check *flag);
void			conv_zd_prec(t_printf *box, t_check *flag);

void			conv_o(t_printf *box, t_check *flag);
void			conv_lo(t_printf *box, t_check *flag);
void			conv_zo(t_printf *box, t_check *flag);

void			conv_o_prec(t_printf *box, t_check *flag);
void			conv_lo_prec(t_printf *box, t_check *flag);
void			conv_zo_prec(t_printf *box, t_check *flag);

void			conv_x(t_printf *box, t_check *flag);
void			conv_hx(t_printf *box, t_check *flag);
void			conv_jx(t_printf *box, t_check *flag);
void			conv_lx(t_printf *box, t_check *flag);

void			conv_x_prec(t_printf *box, t_check *flag);
void			conv_hx_prec(t_printf *box, t_check *flag);
void			conv_jx_prec(t_printf *box, t_check *flag);
void			conv_lx_prec(t_printf *box, t_check *flag);

void			conv_x_up(t_printf *box, t_check *flag);
void			conv_lx_up(t_printf *box, t_check *flag);

void			conv_x_up_prec(t_printf *box, t_check *flag);
void			conv_x_up_prec2(t_printf *box, t_check *flag
	, unsigned long long arg, char *str);
void			conv_x_up_prec3(t_printf *box, t_check *flag, unsigned int arg
	, char *str);
void			conv_lx_up_prec(t_printf *box, t_check *flag);

void			conv_u(t_printf *box, t_check *flag);
void			conv_lu(t_printf *box, t_check *flag);

void			conv_u_prec(t_printf *box, t_check *flag);
void			conv_lu_prec(t_printf *box, t_check *flag);

void			conv_f(t_printf *box, t_check *flag);
void			conv_f_prec(t_printf *box, t_check *flag);

#endif
