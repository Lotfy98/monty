#include "monty.h"

/**
 * split_string - Function to split string into tokens
 * @buffer: Buffer
 * @delimiter: Delimiter
 * Return: Return array of strings
 */
char **split_string(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0;
	char **temp_ptr = NULL;
	unsigned int memory_size = 1;

	if (buffer == NULL)
	{
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * memory_size);
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: realloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (*buffer == ' ' || *buffer == '\n' || *buffer == '\t')
	{
		buffer++;
	}
	while ((tokens[i] = cut_string(buffer, delimiter)) != NULL)
	{
		i++;
		if (i >= memory_size)
		{
			temp_ptr = reallocate_memory(tokens, 8 * i, 8 * (i + 1));
			tokens = temp_ptr;
			if (tokens == NULL)
			{
				fprintf(stderr, "Error: realloc failed\n");
				exit(EXIT_FAILURE);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}
/**
 * cut_string - Function to cut string
 * @buffer: Buffer
 * @d: Delimiter
 * Return: Return string
 */
char *cut_string(char *buffer, char *d)
{
	static char *save_ptr;
	char *string = NULL, *end_ptr = NULL;

	buffer = buffer ? buffer : save_ptr;
	if (*buffer != '\0')
	{
		while (*buffer == ' ' || *buffer == '\n' || *buffer == '\t')
		{
			if (*buffer == '\n')
			{
				buffer++;
				continue;
			}
			buffer++;
		}
		end_ptr = buffer;
		if (!*end_ptr)
		{
			save_ptr = '\0';
		}
		else
		{
			string = end_ptr;
			while (*end_ptr != *d && *end_ptr != '\0')
			{
				end_ptr++;
			}
			if (*end_ptr != '\0')
			{
				*end_ptr = '\0';
				end_ptr++;
			}
			save_ptr = end_ptr;
			return (string);
		}
	}
	save_ptr = NULL;
	buffer = NULL;
	return (NULL);
}
/**
 * reallocate_memory - reallocates memory block
 * @ptr: pointer to the previous memory
 * @old_size: the old size
 * @new_size: the new size
 * Return: a pointer to the newly allocated memory
 */
void *reallocate_memory(void *ptr, size_t old_size, size_t new_size)
{
void *new_memory;

if (new_size == old_size)
return (ptr);
if (new_size == 0 && ptr)
{
free(ptr);
return (NULL);
}
new_memory = malloc(new_size);
if (new_memory == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
if (ptr == NULL)
{
fill_array(new_memory, '\0', new_size);
free(ptr);
}
else
{
copy_memory(new_memory, ptr, old_size);
free(ptr);
}
return (new_memory);
}
/**
 * fill_array - fill an array with elements
 * @str: the given array
 * @c: the given element
 * @len: the length of the array
 * Return: pointer to filled array
 */
void *fill_array(void *str, char c, size_t len)
{
char *p = str;
unsigned int i = 0;

while (i < len)
{
*p = c;
p++;
i++;
}
return (str);
}
/**
 * copy_memory - copies memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Amount of memory byte
 *
 * Return: A pointer to dest
 */
void *copy_memory(char *dest, char *src, size_t n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
dest[i] = src[i];
}
return (dest);
}
