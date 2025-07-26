/* embeded.c */
#include "embeded.h"
#include "helperutils.h"

void usage(int8 *arg) {
  fprintf(stderr, "USAGE: %s [-h | --help | -a] <identifier>\n", $c arg);
  exit(-1);
}

int16 length(int8 *str) {
  int8 *p;
  int16 n;

  for (p = str, n = 0; *p; p++, n++)
    ;

      return n;
}

bool compare(int8 *xs, int8 *ys) {

    bool result ;
    int8 *px, *py;
    int16 n,nx,ny;

    nx = length(xs);
    ny = length(ys);
    if (nx != ny) {
        return false;
    }

    for (px = xs, py = ys, n = nx, result= true; n; n--, px++, py++) {
        if (*px != *py) {
            return false;
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
  int8 *identifier;
  bool use_asm;
  use_asm = false;

  if (argc > 2) {
    if ((compare($1 argv[1], $1 "-h")) || (compare($1 argv[1], $1 "--help"))) {
      usage($1 argv[0]);
    }

    if (argc == 2) {
      identifier = $1 argv[1];
    } else if (argc == 3) {
      if (compare($1 argv[1], $1 "-a")) {
        use_asm = true;
        identifier = $1 argv[2];
      }
    } else {
      usage($1 argv[0]);
    }
  }

  printf("use_asm=\t %s\n"
         "identifier = '%s'\n",
         (use_asm) ? "true" : "false", $c identifier);
  return 0;
}
