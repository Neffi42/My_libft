/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:17:36 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/01 16:44:07 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	int		i[2];
	int		start;
	int		len;
	va_list	ap;

	i[0] = -1;
	i[1] = STDOUT_FILENO;
	start = 0;
	len = 0;
	va_start(ap, s);
	while (s[++(i[0])])
	{
		if (!s[i[0] + 1])
			write(STDOUT_FILENO, &(s[start]), i[0] + 1 - start);
		if (s[i[0]] == '%')
		{
			write(STDOUT_FILENO, &(s[start]), i[0] - start);
			i[0] += ft_read_flag(s, &ap, i, &len);
			start = i[0] + 1;
		}
		else
			len++;
	}
	va_end(ap);
	return (len);
}
