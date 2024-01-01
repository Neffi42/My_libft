/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:42:13 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/01 16:44:43 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert_flag(char c, va_list *ap, int fd)
{
	if (c == 'c')
		return (ft_count_putchar_fd(va_arg(*ap, int), fd));
	else if (c == 's')
		return (ft_s_flag(va_arg(*ap, char *), fd));
	else if (c == 'p')
		return (ft_p_flag(va_arg(*ap, unsigned long), fd));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base_fd(va_arg(*ap, int), DECI_BASE, fd));
	else if (c == 'u')
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), DECI_BASE, fd));
	else if (c == 'x')
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), X_BASE_LO, fd));
	else if (c == 'X')
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), X_BASE_UP, fd));
	else if (c == '%')
		return (ft_count_putchar_fd('%', fd));
	return (FALSE);
}

int	ft_read_flag(const char *s, va_list *ap, int *i, int *len)
{
	int		l;

	l = 0;
	if (ft_strchr(CONV_FLAGS, s[i[0] + 1]))
	{
		l = ft_convert_flag(s[i[0] + 1], ap, i[1]);
		if (!l)
		{
			*len += 1;
			return (FALSE);
		}
		else if (l == -1)
			return (TRUE);
		*len += l;
	}
	return (TRUE);
}
