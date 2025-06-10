#include <debug/debug_stdio.h>
#include <debug/panic.h>

void panic(const char* msg) {
	DEBUG_PUTS("OVERCOOKED: ");
	DEBUG_PUTS(msg);
	DEBUG_PUTS("\n");

	while (1) {
	}
}

void error(const char* msg) {
	DEBUG_PUTS("BURNT: ");
	DEBUG_PUTS(msg);
	DEBUG_PUTS("\n");
}
