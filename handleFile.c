#include "monty.h"

/**
 * read_file - Reads a file and returns its contents as a string.
 * @file: The name of the file to read.
 *
 * Return: A pointer to a buffer containing the contents of the file,
 *or NULL if an error occurred. The caller is responsible for
 *freeing the returned buffer.
 */
char *handleFile(char *file)
{
	ssize_t len;
	int file_descriptor;
	char *buf = NULL;
	struct stat st;

	/* Check if file is NULL */
	if (file == NULL)
		return (NULL);

	/* Open the file */
	file_descriptor = open(file, O_RDONLY, 600);
	if (file_descriptor == -1)
	{
		/* Print an error message and exit if the file can't be opened */
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	/* Get the file's statistics */
	fstat(file_descriptor, &st);

	/* Allocate memory for the buffer */
	buf = malloc(sizeof(char) * st.st_size + 1);
	if (buf == NULL)
	{
		/* Print an error message and return NULL if malloc failed */
		fprintf(stderr, "Error: malloc failed\n");
		close(file_descriptor);
		return (NULL);
	}

	/* Read the file */
	len = read(file_descriptor, buf, st.st_size);
	if (len == -1)
	{
		/* Print an error message and return NULL if the file can't be read */
		fprintf(stderr, "Error: Can't read file %s\n", file);
		close(file_descriptor);
		free(buf);
		return (NULL);
	}

	/* Close the file */
	close(file_descriptor);

	/* Null-terminate the buffer */
	buf[len] = '\0';

	/* Return the buffer */
	return (buf);
}
