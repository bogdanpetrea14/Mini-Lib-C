// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *Memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (Memory) {
		mem_list_add(Memory, size);
		return Memory;
	}
	return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	void *Memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (Memory) {
		memset(Memory, 0, nmemb);
		mem_list_add(Memory, size);
		return Memory;
	}
	return NULL;
}

void free(void *ptr)
{
	struct mem_list *node;
	node = mem_list_find(ptr);
	if (node) {
		munmap(ptr, node->len);
		mem_list_del(ptr);
	}
}

void *realloc(void *ptr, size_t size)
{
	void *pointer = malloc(size);
	if (pointer)
		memcpy(pointer, ptr, size);
	free(ptr);
	return pointer;
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	ptr = malloc(size * nmemb);
	if (ptr)
		return ptr;
	return NULL;
}
