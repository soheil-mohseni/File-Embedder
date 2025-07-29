/* embeded.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include "helperutils.h"


typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;
// typedef unsigned  _BitInt(128) int128;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $16 (int128)
#define $c (char *)
#define $i (int)


enum e_language {
    c = 0,
    asmb = 1
};

typedef  enum e_language language ;



int8 *convert(int8,language);
void printbody(language);

void printheader(int8*,language);
int16 length(int8 *str);
bool compare(int8 *xs, int8 *ys);
int main(int,char**);
void usage(int8 *arg);