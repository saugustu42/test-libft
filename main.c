#include <stdio.h>
#include "./eval-libft/libft.h"
#include <string.h>

int		main(void)
{
	printf("checking atoi crutch\n");
	printf("expected: %d\n", 42);
	printf("__test__: %d\n", ft_atoi("000000000000000000000042"));
	printf("\n");

	printf("checking substr return when index is out of the string\n");
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

	printf("\nSPLIT with empty string\n\n");
	splited = ft_split("", ' ');
	if (splited == NULL)
		printf("you return NULL :(\n");
	else
		printf("EXP: (null)\n");
		printf("GOT: %s\n", splited[0]);


	printf("\nchecking split with string and \\0 as delimiter\n");
	splited = ft_split("Hello, world!", '\0');
	if (splited == NULL)
		printf("you return NULL :(\n");
	else
	{
		printf("EXP: Hello, world!\n");
		printf("GOT: %s\n", splited[0]);
	}


	printf("\nSTRNSTR\n\n");
	printf("EXP: %s\n", strnstr("000000123", "123", 9));
	printf("GOT: %s\n", ft_strnstr("000000123", "123", 9));

	printf("\nSUBSTR\n\n");
	printf("EXP: %s\n", "RUN!");
	printf("GOT: %s\n", ft_substr("1 2 3... RUN!", 9, 4));

	printf("\nchecking trim with empty strings\n");
	printf("EXP: %s\n", "");
	printf("GOT: %s\n", ft_strtrim("", " "));
	printf("\nEXP: %s\n", "");
	printf("GOT: %s\n", ft_strtrim("", ""));
	
}
