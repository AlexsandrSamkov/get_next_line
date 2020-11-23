#include "get_next_line.h"
#include "stdio.h"
#include "fcntl.h"

int main()
{
	char *s;
	int fd;
	int k;
	k = 1;
	fd = open("/Users/aleksandrsamkov/gnl-dev2/text.txt",O_RDONLY);
	while (k == 1)
	{
		k = get_next_line(fd,&s);
		printf("%d %s \n", k, s);
		free(s);
	}
	close(fd);
	sleep(1000);
}