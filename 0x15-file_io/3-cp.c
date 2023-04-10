#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates 1024 bytes for buffer.
 * @file: is the name of the file buffers storing chars
 * Return: pointer is returned to the newly allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - file descriptors close
 * @fd: is the closed descriptor
 */
void close_file(int fd)
{
	int cl;

	cl = close(fd);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - this copies contents from file to file
 * @argc: is number of arguments in a program
 * @argv: points to the arguments
 *
 * Return: 0 (success)
 *
 * Description: If the argument count is incorrect - 97 (exit code)
 * file does not exist or not readable - 98 (exit code)
 * file cannot be created or written - 99 (exit code)
 * file cannot be closed - 100 (exit)
 */
int main(int argc, char *argv[])
{
	int from, to, re;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	re = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0064);

	do {
		if (from == -1 || re == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		re = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (re > 0);
	free(buffer);
	close_file(to);

	return (0);
}
