#include "../header/utils.h"

void		*ft_memset(void *ptr, int x, size_t n)
{
	size_t	i;
	char	*a;

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
