#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
	char b[1];
	b[0] = 0xc3;
	((void(*)())&b)();
	printf("done\n");
    	return 0;
}
