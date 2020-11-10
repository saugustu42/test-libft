#include <stdio.h>
#include "../eval-libft/libft.h"

int		main(void)
{
	printf("checking atoi crutch\n");
	printf("expected: %d\n", 987);
	printf("__test__: %d\n", ft_atoi("000000000000000000000987"));
	printf("\n");
}
