/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:01:07 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/11/14 18:59:11 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int		ft_print_nbr(int nbr)
{
	long	n;
	char	c;
	int		count;

	n = nbr;
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_print_nbr(n / 10);
		count += ft_print_nbr(n % 10);
	}
	else
	{
		c = n + '0';
		count += ft_print_char(c);
	}
	return (count);
}

int		ft_print_hex(unsigned long n, char c)
{
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_hex(n / 16, c);
		count += ft_print_hex(n % 16, c);
	}
	else
	{
		if (c == 'x')
			count += ft_print_char("0123456789abcdef"[n]);
		if (c == 'X')
			count += ft_print_char("0123456789ABCDEF"[n]);
	}
	return (count);
}

int		ft_print_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i++], 1);
	}
	return (i);
}

int		ft_print_ptr(unsigned long p)
{
	int		count;

	count = 0;
	count += ft_print_str("0x");
	count += ft_print_hex(p, 'x');
	return (count);
}

int main()
{
//    int result = printf("Sentence to know how many %s\n", "characters were written");
//    printf("% characters were written in total (both 2 arguments)%i\n", result);

	int *p;
	int a;
	a = 21;
	p = &a;
  //  int count = ft_print_ptr(&a);
  //  printf ("\n%i\n", count);
	ft_print_ptr(p);
   
}