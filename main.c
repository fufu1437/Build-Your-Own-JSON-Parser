#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokenize.h"
#include "tokenize.c"  /* grader compiles ONLY this file (entrypoint "main.c" in
                          .shipthatcode.json), so pull tokenize.c in as one
                          translation unit. Never compile the two .c files
                          separately — tokenize() would be defined twice. */

/* TODO (json-tokenize): implement per the lesson description. */

int main(void) {
	char line[1024];
	while(fgets(line, sizeof line, stdin)) {
		if(line[0] == '\n' || line[0] == 0) continue;
		// printf("TODO\n");
		tokenize();
	}
	return 0;
}
