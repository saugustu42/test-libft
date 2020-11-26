#include <stdio.h>
#define CHECK "\U00002705"
#define CROSS "\U0000274C"
#define SHIELD "\U0001F6E1"
#define BOOM  "\U0001F4A5"

int main()
{
    printf(CHECK CROSS SHIELD BOOM"\n\n");

    for(int i = 0; i < 3; i++)
        printf("%s %s %s", CHECK, CROSS, CHECK);
	printf("\n");
    return 0;
}
