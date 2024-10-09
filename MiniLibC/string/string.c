// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	if (!destination) {
		return NULL;
	}
	int max_size = strlen(source);
	int counter = 0;
	while (max_size) {
		destination[counter] = source[counter];
		max_size--;
		counter++;
	}
	destination[counter] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	if (!destination) {
		return NULL;
	}
	size_t max_size = strlen(source);
	size_t counter = 0;
	if (len < max_size) {
		while (len) {
			destination[counter] = source[counter];
			counter++;
			len--;
		}
	} else {
		while (counter != max_size) {
			destination[counter] = source[counter];
			counter++;
		}
		while (counter != len) {
			destination[counter] = '\0';
			counter++;
		}
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	int len_destination = strlen(destination);
	int len_source = strlen(source);
	for (int i = 0; i < len_source; i++) {
		destination[len_destination + i] = source[i];
	}
	destination[len_destination + len_source] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t len_destination = strlen(destination);
	size_t len_source = strlen(source);
	size_t counter = (len_source < len) ? len_source : len;
	for (int i = 0; i < counter; i++)
		destination[len_destination + i] = source[i];
	destination[len_destination + counter] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int len_1 = strlen(str1);
	int len_2 = strlen(str2);
	int min = (len_1 <= len_2) ? len_1 : len_2;
	int max = (len_1 >= len_2) ? len_1 : len_2;
	for (int i = 0; i < min; i++) {
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
	}
	for (int i = min; i < max; i++) {
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t len_1 = strlen(str1);
	size_t len_2 = strlen(str2);
	size_t min = (len_1 <= len_2) ? len_1 : len_2;
	if (min > len)
		min = len;
	for (int i = 0; i < min; i++) {
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	char *p = str;
	while (*p) {
		if (*p == c && *p != '\0')
			return p;
		p++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *p = str + strlen(str) - 1;
	while (p != str) {
		if (*p == c)
			return p;
		p--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	char *p = haystack;
	char *nd = needle;
	char *hs;
	int ok;
	while (*p != '\0') {
		if (*p == *nd) {
			hs = p;
			ok = 1;
			while (*hs != '\0' && *nd != '\0') {
				if (*hs++ != *nd++) {
					ok = 0;
				}
			}
			if (ok)
				return p;
		}
		p++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *p = haystack + strlen(haystack) - 1;
	char *nd = needle + strlen(needle) - 1;
	char *hs = NULL;
	int ok = 1;
	while (p != haystack) {
		if (*p == *nd) {
			hs = p;
			ok = 1;
			while (hs != haystack && nd != needle) {
				if (*hs-- != *nd--)
					ok = 0;
			}
			if (ok)
				return hs;
		}
		p--;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	while (num--) {
		(*(char *)destination) = (*(char *)source);
		(char *)destination++;
		(char *)source++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char buf[num];
	char *copy_source = source;
	size_t copy_num = num, counter = 0;;
	while (copy_num--) {
		buf[counter++] = *copy_source;
		copy_source++;
	}
	counter = 0;
	while (num--) {
		(*(char *)destination) = buf[counter++];
		(char *)destination++;
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p1 = (char *)ptr1;
	char *p2 = (char *)ptr2;
	while (num--) {
		if (*p1 != *p2)
			return *p1 - *p2;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *p = source;
	while (num--) {
		*p = value;
		p++;
	}
	return source;
}
