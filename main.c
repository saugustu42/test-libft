#include <stdio.h>
#include "./eval-libft/libft.h"
#include <string.h>
#include "print_output.h"

void	print_result(char *exp, char *got) //print expected-result and got-result with yellow dollar (emuleted cat -e)
{
	printf("EXP: %s%s\n", exp, DOLLAR);
	printf("GOT: %s%s\n", got, DOLLAR);

}

void	print_title(char *title) //print blue bold font text
{
		printf("\n%s%s%s\n\n", BLUE, title, RESET);
}

char			*my_itoa(int n) // additional libft-function for print_result
{
	char	*str;
	int		minus;
	int		len;
	int		num_copy;
	int		i;

	if (n == -2147483648)
		return (strdup("-2147483648"));
	if (n == 0)
		return (strdup("0"));
	num_copy = n;
	i = 1;
	while (num_copy /= 10)
		i++;
	minus = n < 0;
	if (minus)
		n *= -1;
	len = minus + i;
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (minus)
		str[0] = '-';
	str[len--] = '\0';
	while (n)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
int		main(void)
{

	print_title("ATOI");

	printf("checking atoi crutch\n");
	print_result("42", my_itoa(ft_atoi("000000000000000000000042")));




	print_title("SPLIT");

	printf("checking split with a string containing only delimiters\n");
	char **splited;
	splited = ft_split("    ", ' ');
	if (splited == NULL)
		print_result("\033[31m :( expected array of pointers with one element pointing to NULL\033[0m", "(null)");
	else
		print_result("(null)", *splited);
	printf("\nchecking split with empty string\n");
	splited = ft_split("", ' ');
	if (splited == NULL)
		print_result("\033[31m :( expected array of pointers with one element pointing to NULL\033[0m", "(null)");
	else
		print_result("(null)", *splited);
	printf("\nchecking split with string and \\0 as delimiter\n");
	splited = ft_split("Hello, world!", '\0');
	if (splited == NULL)
		print_result("Hello, world!", "(null)");
	else
		print_result("Hello, world!", *splited);
	printf("\nchecking split with empty string and \\0 as delimiter\n");
	splited = ft_split("", '\0');
	if (splited == NULL)
		print_result("\033[31m :( expected array of pointers with one element pointing to NULL\033[0m", "(null)");
	else
		print_result("(null)", *splited);




	print_title("STRNSTR");

	printf("checking basic case\n");
	print_result("123", ft_strnstr("000000123", "123", 9));




	print_title("SUBSTR");

	printf("\nchecking basic cases\n");
	print_result("RUN!", ft_substr("1 2 3... RUN!", 9, 4));
	print_result("est", ft_substr("test", 1, 8));
	printf("checking substr return when index is out of the string\n");
	char *substr_ret;
	substr_ret = ft_substr("HelloCat", 15, 3);
	if (substr_ret == NULL)
		print_result("\033[31mexpected empty string. it is stupid, but fact :( \033[0m", "(null)" );
	else
		print_result("", substr_ret);




	print_title("STRTRIM");

	printf("checking with empty strings\n");
	print_result("", ft_strtrim("", " "));
	print_result("", ft_strtrim("", ""));
	printf("\nchecking basic cases\n");
	print_result("A**A", ft_strtrim("*@****@**A**A***@*", "*@"));
	print_result("B", ft_strtrim("*@*..****@**@**....B....***@****..*@***", ".*@"));
	print_result("C", ft_strtrim("*@****@*******@*C", "*@"));
	print_result("D", ft_strtrim("D", "123456789"));
}
