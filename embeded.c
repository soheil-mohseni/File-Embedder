/* embeded.c */
#include "embeded.h"
#include "helperutils.h"
#include <unistd.h>

void usage(int8 *arg) {
  fprintf(stderr, "USAGE: %s [-h | --help | -a] <identifier>\n", $c arg);
  exit(-1);
}

int16 length(int8 *str) {
  int8 *p;
  int16 n;

  for (p = str, n = 0; *p; p++, n++)
    ;
  // OOOOr you can just use strlen(str) ;)
  return n;
}

bool compare(int8 *xs, int8 *ys) {

  bool result;
  int8 *px, *py;
  int16 n, nx, ny;

  nx = length(xs);
  ny = length(ys);
  if (nx != ny) {
    return false;
  }

  for (px = xs, py = ys, n = nx, result = true; n; n--, px++, py++) {
    if (*px != *py) {
      return false;
    }
  }
  return result;
}

void printheader(int8 *identifier, language lang) {
  switch (lang) {
  case asmb:
    printf("Assembly program identifier: %s\n\tdb", $1 identifier);
    break;
  case c:
    printf("C program identifier: %s\n\t\"", $1 identifier);
    break;
  }
  fflush(stdout);
  return;
}

int8 *convert(int8 ch, language lang) {
  static int8 ret[8];

  zero(ret, $2 8);
  switch (lang) {
  case asmb:
    snprintf($c ret, 7, "0x%.02hhx", (char)ch);
    break;

  default:
  case c:
    snprintf($c ret, 7, "\\x%.02hhx", (char)ch);
    break;
  }

  return ret;
}

void printbody(language lang) {
  int32 n;
  signed int ret;
  int8 buf[2];
  int8 *ch;

  *buf = *(buf + 1) = (int8)0;
  n = $4 0;

  while ((ret = read(0, $c buf, 1)) == 1) {
    if ((lang == asmb) && (n))
      write(0, ",", 1);
    n++;
    ch = convert(*buf, lang);

    switch (lang) {
    case asmb:
      if ((n > 1) && ((n - 1) % 16))
        write(1, ",", 1);
      write(1, $c ch, length(ch));

      if (!(n % 16))
        write(1, "\n\tdb ", 5);

      break;

    default:
    case c:
      write(1, $c ch, length(ch));
      if (!(n % 16))
        write(1, "\n\t\"", 4);

      break;
    }
    *buf = *(buf + 1) = (int8)0;
  }

  switch (lang) {
  case c:
    write(1, "\n", 3);
    break;
  case asmb:
  default:
    write(1, "\n", 1);
  }

  return;
}
int main(int argc, char *argv[]) {
  int8 *identifier;
  language lang;
  lang = c;
  identifier = 0;
  if (argc == 2) {
    identifier = $1 argv[1];
  } else if (argc > 2) {
    if ((compare($1 argv[1], $1 "-h")) || (compare($1 argv[1], $1 "--help"))) {
      usage($1 argv[0]);
    } else if (argc == 3) {
      if (compare($1 argv[1], $1 "-a")) {
        lang = asmb;
        identifier = $1 argv[2];
      } else {
        usage($1 argv[0]);
      }
    } else {
      usage($1 argv[0]);
    }
  } else {
    usage($1 argv[0]);
  }
  printheader(identifier, lang);
  printbody(lang);
  return 0;
}
