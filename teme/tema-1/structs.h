#include <inttypes.h>

typedef struct head {
	unsigned char type;
	unsigned int len;
} head;

typedef struct element {
	head *header;
	void *data;
} element;

typedef struct {
	char* manelist;
	int8_t ban1;
	int8_t ban2;
	char* pers;
} tip1;

typedef struct {
	char* manelist;
	int16_t ban1;
	int32_t ban2;
	char* pers;
} tip2;

typedef struct {
	char* manelist;
	int32_t ban1;
	int32_t ban2;
	char* pers;
} tip3;