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
	char *path = malloc(strlen(FOLDER) + 30);
	strcpy(path, FOLDER);
	strcat(path, "/files/test4");
	int fd = open(path, O_RDONLY);
	int	failed = 0;

	failed = test(fd, 0, failed);
	free (path);

	return (!failed);

}
