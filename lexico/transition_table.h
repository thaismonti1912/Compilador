#ifndef TRANSITION_TABLE_H_INCLUDED
#define TRANSITION_TABLE_H_INCLUDED
#define NUMBER_STATES 19
#define NUMBER_INPUTS_TYPES 15

#include "../utils/token.h"
//Tipos de entradas diferentes consideradas nas transicoes de estado
typedef enum{
	LETTER = 0,
	NUMBER = 1,
	ARITH_SYMBOL = 2,
	DOUBLE_QUOTE = 3,
	SINGLE_QUOTE = 4,
	END_OF_COMMAND = 5,
	EQUALS = 6,
	COMPARATOR = 7,
	UNDERLINE = 8,
	BLANK = 9,
	SEPARATOR = 10,
	UNKNOWN = 11,
	NEWLINE = 12,
	HASHTAG = 13,
	POINT = 14
}InputTypes;

//Ver no relatorio o que significa cada estado
typedef enum{
	S0 = 0, //inicial *
	S1 = 1, //ponto e virgula
	S2 = 2, //identificador
	S3 = 3, //comparador 1 caracter
	S4 = 4, //comparador 2 caracteres
	S5 = 5, //numero
	S6 = 6, //operador aritmetico
	S7 = 7, //tudo exceto " *
	S8 = 8, //completa ""
	S9 = 9, //tudo exceto ' *
	S10 = 10, //completa ''
	S11 = 11, //separadores
	S12 = 12, //desconhecidos
	S13 = 13, //atribuicao
	S14 = 14, //float
	S15 = 15, //comentario de linha
	S16 = 16, //possivel comentario de bloco
	S17 = 17, //abertura de comentario de bloco
	S18 = 18 //fechando comentario de bloco
}States;

extern const int STATE_TRANSITION_TABLE[NUMBER_STATES][NUMBER_INPUTS_TYPES];

extern const char *RESERVED_WORDS[];

//converte um char p/ um InputType
int input_converter_function(char character);
//Converte um States p/ o Token_type que o estado gera
Token_type state_converter_token_type(States state, char buffer[50]);
//retorna 0 se string for uma palavra reservada, senão -1
int is_reserved(char string[50]);

#endif //TRANSITION_TABLE_H_INCLUDED