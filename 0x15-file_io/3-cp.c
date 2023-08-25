#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

/**
  *read_file - Function to create a file descriptor that is read only
  *@filename: file name of the file to read
  *
  *Return: fd if success, -1 otherwise
  */

int read_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", filename);
		return (-1);
	}
	return (fd);
}

/**
  *write_file - Function to create a file descriptor that is write only
  *@filename: file name of the file to write
  *
  *Return: fd if success, -1 otherwise
  */

int write_file(char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
			00664);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		return (-1);
	}
	return (fd);
}

/**
  *copy_file - Function to copy from one file to another file
  *@fd_from: file descriptor to copy/read from
  *@fd_to: file descriptor to copy/write to
  *
  *Return: 0 if successful, -1 or -2 otherwise
  */

int copy_file(int fd_from, int fd_to)
{
	ssize_t n_read, n_write;
	char *buffer;

	n_read = BUFFER_SIZE;
	while (n_read == BUFFER_SIZE)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		if (buffer == NULL)
			n_read = -1;
		else
			n_read = read(fd_from, buffer, BUFFER_SIZE);
		if (n_read == -1)
		{
			if (buffer != NULL)
				free(buffer);
			return (-1);
		}
		n_write = write(fd_to, buffer, n_read);

		if (n_write == -1 || n_write != n_read)
		{
			free(buffer);
			return (-2);
		}
		free(buffer);
	}
	return (0);
}


/**
  *close_file - Function to close the file, and rejects
  *@fides: file descriptor to close
  *
  *Return: 0 on success, -1 otherwise.
  */

int close_file(int fides)
{
	int out;

	out = close(fides);

	if (out == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fides);
		return (-1);
	}
	return (0);
}

/**
  *main - Function to call and use above functions to copy from one
  *filee to another
  *@argc: argument count
  *@argv: vector of argument string
  *
  *Return: 0 if successful, exit otherwise
 */

int main(int argc, char **argv)
{
	int fd_to, fd_from, copy, close_file_from, close_file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = read_file(argv[1]);
	if (fd_from == -1)
		exit(98);
	fd_to = write_file(argv[2]);
	if (fd_to == -1)
		exit(99);

	copy = copy_file(fd_from, fd_to);
	if (copy == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (copy == -2)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	close_file_from = close(fd_from);
	close_file_to = close(fd_to);
	if (close_file_from == -1 || close_file_to == -1)
		exit(100);
	return (0);
}
