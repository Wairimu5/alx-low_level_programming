#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void close_file(int fd);
void copy_file(char *file_from, char *file_to);

/**
 * close_file - Closes the file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
    int result = close(fd);
    if (result == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}

/**
 * copy_file - Copies the contents of one file to another.
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 */
void copy_file(char *file_from, char *file_to)
{
    int fd_from, fd_to;
    ssize_t r, w;
    char buffer[BUFFER_SIZE];

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        exit(98);
    }

    fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
        close_file(fd_from);
        exit(99);
    }

    while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        char *write_ptr = buffer;
        do
        {
            w = write(fd_to, write_ptr, r);
            if (w == -1)
            {
                dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
                close_file(fd_from);
                close_file(fd_to);
                exit(99);
            }
            r -= w;
            write_ptr += w;
        } while (r > 0);
    }

    if (r == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        close_file(fd_from);
        close_file(fd_to);
        exit(98);
    }

    close_file(fd_from);
    close_file(fd_to);
}

/**
 * main - Entry point.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    copy_file(argv[1], argv[2]);

    return (0);
}
