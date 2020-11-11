#include <stdio.h>
#include "../eval-libft/libft.h"

int		main(void)
{
	printf("checking atoi crutch\n");
	printf("expected: %d\n", 42);
	printf("__test__: %d\n", ft_atoi("000000000000000000000042"));
	printf("\n");

	printf("checking substr return when index out of string\n");
	char *substr_ret;
	substr_ret = ft_substr("HelloCat", 15, 3);
	if (substr_ret == NULL)
		printf("you return NULL :( expected empty string. it is stupid, but fact.\n");
	else
	{
		printf("expected: %s\n", "");
		printf("__test__: %s\n", substr_ret);
	}
	printf("\n");

	printf("checking split with a string containing only delimiters\n");
	char **splited;
	splited = ft_split("    ", ' ');
	if (splited == NULL)
		printf("you return NULL :( expected array of pointers with one element pointing to NULL\n");
	else
	{
		printf("expected: %s\n", "(null)");
		printf("__test__: %s\n", *splited);
	}
}
