#include <stdbigos/pstring.h>
#include <stdbigos/string.h>
#include <stddef.h>

struct pstring_t {
	size_t len;
	char* data;
};

struct pstring_t pstring_cringe2based(char* str) {
	return (struct pstring_t){.len = strlen(str), .data = str};
}

size_t pstring_memcpy(struct pstring_t* dest, const struct pstring_t* src) {
	if (!dest || !src || !src->data || !dest->data)
		return 0;
	size_t min_len = (src->len < dest->len) ? src->len : dest->len;
	dest->data = (char*)memcpy(dest->data, src->data, min_len);
	return min_len;
}

size_t pstring_fill(struct pstring_t* dest, char val) {
	if (!dest || !dest->data)
		return 0;
	for (size_t i = 0; i < dest->len; i++) {
		dest->data[i] = val;
	}
	return dest->len;
}

size_t pstring_memmove(struct pstring_t* dest, const struct pstring_t* src) {
	if (!dest || !src || !src->data || !dest->data)
		return 0;
	size_t min_len = (src->len < dest->len) ? src->len : dest->len;
	dest->data = (char*)memmove(dest->data, src->data, min_len);
	return min_len;
}

int pstring_cmp(const struct pstring_t* lhs, const struct pstring_t* rhs) {
	if (lhs->len != rhs->len) {
		return lhs->len < rhs->len ? -1 : 1;
	}
	size_t i = 0;
	size_t j = 0;
	while (i < lhs->len && j < rhs->len) {
		int cmp = lhs->data[i] - rhs->data[j];
		if (cmp != 0) {
			return cmp;
		}
		i++;
		j++;
	}
	return 0;
}

size_t pstring_len(const struct pstring_t* ps) {
	if (!ps || !ps->data) {
		return 0;
	}
	return ps->len;
}

/*
[[reproducible, gnu::nonnull]]
void* memcpy(void* restrict dest, const void* restrict src, size_t n);

[[reproducible, gnu::nonnull]]
void* memset(void* dest, int val, size_t n);

[[reproducible, gnu::nonnull]]
void* memset_explicit(void* dest, int val, size_t n);

[[gnu::nonnull]]
void* memmove(void* dest, const void* src, size_t n);

[[reproducible, gnu::nonnull]]
void* memccpy(void* restrict dest, const void* restrict src, int c, size_t count);

[[unsequenced, gnu::nonnull, gnu::pure]]
int memcmp(const void* lhs, const void* rhs, size_t n);

[[unsequenced, gnu::nonnull, gnu::pure]]
void* memchr(const void* ptr, int ch, size_t n);

[[unsequenced, gnu::nonnull, gnu::pure]]
size_t strlen(const char* str);

[[unsequenced, gnu::nonnull, gnu::pure]]
size_t strnlen(const char* str, size_t n);

[[reproducible, gnu::nonnull]]
char* strcpy(char* restrict dest, const char* restrict src);

[[reproducible, gnu::nonnull]]
char* strncpy(char* restrict dest, const char* restrict src, size_t count);

[[gnu::nonnull]]
char* strcat(char* restrict dest, const char* restrict src);

[[gnu::nonnull]]
char* strncat(char* restrict dest, const char* restrict src, size_t count);

[[unsequenced, gnu::nonnull, gnu::pure]]
int strcmp(const char* lhs, const char* rhs);

[[unsequenced, gnu::nonnull, gnu::pure]]
int strncmp(const char* lhs, const char* rhs, size_t n);

[[unsequenced, gnu::nonnull, gnu::pure]]
char* strchr(const char* str, int c);

[[unsequenced, gnu::nonnull, gnu::pure]]
char* strrchr(const char* str, int c);

[[unsequenced, gnu::nonnull, gnu::pure]]
size_t strspn(const char* dest, const char* chars);

[[unsequenced, gnu::nonnull, gnu::pure]]
size_t strcspn(const char* dest, const char* chars);

[[unsequenced, gnu::nonnull, gnu::pure]]
char* strpbrk(const char* dest, const char* breakset);

[[unsequenced, gnu::nonnull, gnu::pure]]
char* strstr(const char* str, const char* substr);

*/
