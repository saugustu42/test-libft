#include <stdio.h>
#include "../eval-libft/libft.h"

int		main(void)
{
	printf("checking atoi crutch\n");
	printf("expected: %d\n", 987);
	printf("__test__: %d\n", ft_atoi("000000000000000000000987"));
	printf("\n");

	printf("checking substr return when index out of string\n");
	printf("expected_until_|: %s|\n", "");
	printf("__test___until_|: %s|\n", ft_substr("HelloCat", 15, 3));
	printf("\n");
}
