/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:54:46 by hyna              #+#    #+#             */
/*   Updated: 2022/05/20 19:39:40 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h" 

char	*ft_itoa_base(unsigned int n, char	*base);
int		ft_printf(const char	*format, ...);
int		conversion_c(va_list	ap);
int		conversion_di(va_list	ap);
int		conversion_p(va_list	ap);
int		conversion_p_util(unsigned long long nbr, char	*base);
int		conversion_s(va_list	ap);
int		conversion_u(va_list	ap);
int		conversion_x(va_list	ap);
int		conversion_upper_x(va_list	ap);

#endif
