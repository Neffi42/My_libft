/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oget_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:37:14 by abasdere          #+#    #+#             */
/*   Updated: 2024/01/04 10:43:49 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_oget_next_line(int fd, char **line)
{
	*line = ft_get_next_line(fd);
	return (*line);
}
