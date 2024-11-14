/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:47 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/11/13 14:33:54 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *mand_arg, ...)
{
	int	i;
	int count;
	int	a;
	va_list ap; //argument pointer


	void	va_start(ap, mand_arg)

	i = 0;
	count = 0;
	
	while (mand_arg[i] != '\0')
	{
		if (mand_arg[i] == '%')
		{
			i++;
			count += ft_printf_format(mand_arg[i++], ap);
		}
		else
			count += write(1, mand_arg[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
