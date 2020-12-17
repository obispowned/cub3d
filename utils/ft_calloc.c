/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:47:26 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 11:47:28 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	while (n--)
		*str1++ = *str2++;
	return (dst);
}

void				*ft_memset(void *ptr, int x, size_t n)
{
	size_t			i;
	char			*a;

	i = 0;
	a = ptr;
	while (i < n)
	{
		a[i] = (unsigned char)x;
		i++;
	}
	return (&a[0]);
}

void				*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	sum;

	sum = count * size;
	if (!(ptr = malloc(sum)))
		return (0);
	ft_memset(ptr, 0, sum);
	return ((void *)ptr);
}
