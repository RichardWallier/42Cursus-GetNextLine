#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char* test = "\n123\n456\n";

	int fd = open("test.txt", O_RDONLY);
	printf("mainline: %s\n", get_next_line(fd));
	return (0);
}
