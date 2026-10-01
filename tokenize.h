#ifndef TOKENIZE_H
#define TOKENIZE_H

extern const char* token_str[];

#define TOKENS_SIZE 48

typedef enum token_type {
	tk_PUNCT,
	tk_STRING,
	tk_NUMBER,
	tk_TRUE,
	tk_FALSE,
	tk_NULL,
	tk_EOF,
}token_type;

typedef struct token {
	token_type type;

	size_t value_len;
	// size_t value_cap;
	char value[24];
}token;

token** tokenize(char* v);

#endif // TOKENIZE_H
