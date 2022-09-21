#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int	main(void)
{
	char	buff[BUFF_SIZE];
	int		fd;
	ssize_t ck;

	if (0 < (fd = open("./test.txt", O_RDONLY)))
	{
		read(fd, buff, BUFF_SIZE);
		printf("%s", buff);
		printf("%d", fd);
		close(fd);
	}
	else
		printf("파일열기에 실패했습니다");
	return 0;
}
