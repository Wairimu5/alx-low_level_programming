#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/**
  *read_textfile - Read file and prints it to stdout
  *@filename: The name of the file to read from
  *@letter: The numver of letters it should read and print
  *
  *Return: A fd if success, but -1 if it fails
  */

ssize_t read_textfile(const char *filename, size_t letter)
{
	ssize_t n_read, n_write;
	int fd;
	char *str;

	if (filename == NULL || filename[0] == '\0')
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	str = malloc(sizeof(char) * letter);
	if (str == NULL)
	{
		free(str);
		close(fd);
		return (0);
	}
	n_read = read(fd, str, letter);
	if (n_read < 0)
	{
		close(fd);
		free(str);
		return (0);
	}
	n_write = write(STDOUT_FILENO, str, n_read);
	if (n_write < n_read)
	{
		close(fd);
		free(str);
		return (0);
	}
	free(str);
	close(fd);
	return (n_read);
}
