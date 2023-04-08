#include "main.h"

/**
 * append_text_to_file - appends text at file end
 * @filename: pointer to the name of the file
 * @text_content: NULL terminated string to add to end
 *
 * Return: 1 (success), -1 (fail)
 *
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int op, wr, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	wr = write(0, text_content, len);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);

	return (1);
}
