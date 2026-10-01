#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const char* token_str[] = {
	"PUNCT",
	"STRING",
	"NUMBER",
	"TRUE",
	"FALSE",
	"NULL",
	"EOF"
};

#include "tokenize.h"

token** tokenize(char* v) {
	size_t tks_index = 0;
	token** tks = malloc(sizeof(token*) * TOKENS_SIZE);
	memset(tks, 0, sizeof(token*) * TOKENS_SIZE);
	token* tk = NULL;

#define c (*v)
	while(*v) {
		if(tk == NULL) tk = malloc(sizeof(token));
		if(isspace(c)) {
			v++;
			continue;
		}
		if(c == ',' || c == ':' || c == '{' || c == '}' || c == '[' || c == ']') {
			tk->type = tk_PUNCT;
			tk->value[0] = c;
			tk->value[1] = 0;
			tk->value_len = 1;
			tks[tks_index++] = tk; tk = NULL;
		}
		else if(c == '"') {
			v++;
			tk->type = tk_STRING;
			int i = 0;
			while(c != '"') {
				tk->value[i++] = c;
				v++;
			}
			tk->value[i] = 0;
			tk->value_len = i;
			tks[tks_index++] = tk; tk = NULL;
			// printf("[DEBUG]: %c\n", c);
		}
		else if(isalpha(c)) {
			// tk->type = tk_;
			int i = 0;
			while(isalpha(c)) {
				tk->value[i++] = c;
				v++;
			}
			tk->value_len = i;
			if(strncmp(tk->value, "true", 4) == 0) {
				tk->type = tk_TRUE;
			}
			else if(strncmp(tk->value, "null", 4) == 0) {
				tk->type = tk_NULL;
			}
			else if(strncmp(tk->value, "false", 5) == 0) {
				tk->type = tk_FALSE;
			}
			v--;
			tk->value[i] = 0;
			tks[tks_index++] = tk; tk = NULL;
		}
		else if(isalnum(c) || c == '-') {
			tk->type = tk_NUMBER;
			int i = 0;
			while(c == '-' || c == '+' || c == '.' || c == 'e' || c == 'E' || isalnum(c)) {
				tk->value[i++] = c;
				v++;
			}
			v--;
			tk->value[i] = 0;
			tks[tks_index++] = tk; tk = NULL;
		}
		v++;
	}
	return tks;
}
