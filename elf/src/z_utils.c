#include <stdlib.h>

void *z_memset(void *s, int c, size_t n)
{
	unsigned char *p = s, *e = p + n;
	while (p < e)
		*p++ = c;
	return s;
}

void *z_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *p = src, *e = p + n;
	while (p < e)
		*d++ = *p++;
	return dest;
}


int z_memcmp(void* dest, const void* src, size_t n) {
	unsigned char *d = dest;
	const unsigned char *p = src, *e = p + n;
	int idx = 1;
	while (p < e) {
		if(*d++ != *p++) {
			return idx;
		}
		++idx;
	}
	return 0;
}
