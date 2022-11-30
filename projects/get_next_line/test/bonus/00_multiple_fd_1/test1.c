#include "header.h"


int test(int fd, char *cmp, int failed)
{
	char	*s;

	if (failed)
		return (1);

	s = FT_FUNCTION(fd);
	if (!s && !cmp)
		return (0);
	if (strcmp(s, cmp))
	{
		if (!s)
		{
			printf("Get NULL");
		}
		else if (!cmp)
		{
			printf("Expected NULL");
		}
		else
			printf("Expected : \"%s\"\nbut...   : \"%s\"", cmp, s);
		if (s)
			free(s);
		return(1);
	}
	if (s)
		free(s);
	return (0);

}

int main()
{
	char *path1 = malloc(strlen(FOLDER) + 30);
	char *path2 = malloc(strlen(FOLDER) + 30);
	char *path3 = malloc(strlen(FOLDER) + 30);
	char *path4 = malloc(strlen(FOLDER) + 30);
	
	strcpy(path1, FOLDER);
	strcpy(path2, FOLDER);
	strcpy(path3, FOLDER);
	strcpy(path4, FOLDER);
	
	strcat(path1, "/files/test1");
	strcat(path2, "/files/test2");
	strcat(path3, "/files/test3");
	strcat(path4, "/files/test4");
	
	int fd1 = open(path1, O_RDONLY);
	int fd2 = open(path2, O_RDONLY);
	int fd3 = open(path3, O_RDONLY);
	int fd4 = open(path4, O_RDONLY);
	
	int	failed = 0;

	failed = test(fd1, "123\n", failed);
	failed = test(fd2, "\n", failed);
	failed = test(fd1, "456\n", failed);
	failed = test(fd2, "\n", failed);
	failed = test(fd2, "\n", failed);
	failed = test(fd3, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n", failed);
	failed = test(fd4, 0, failed);
	failed = test(fd1, "789\n", failed);
	failed = test(fd3, 0, failed);
	failed = test(fd2, ".\n", failed);
	failed = test(fd2, "\n", failed);
	failed = test(fd3, 0, failed);
	failed = test(fd2, "\n", failed);
	failed = test(fd2, "\n", failed);
	failed = test(fd2, 0, failed);
	failed = test(fd2, 0, failed);
	
	free (path1);
	free (path2);
	free (path3);
	free (path4);
	
	return (!failed);

}
