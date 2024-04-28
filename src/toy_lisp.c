#include <stdio.h>
#include <stdlib.h>

#include "./io.h"

void run(char *filepath);

int main(int argc, char **argv) {
  Atom atoms[MAX_ATOMS];
  SExpr sexprs[MAX_SEXPRS];

  Mode mode = get_mode(argc, argv);
  switch (mode) {
  case MODE_COMP:
    assert(false && "comp mode not implemented");
    break;
  case MODE_RUN:
    run(argv[2]);
    break;
  case MODE_REPL:
  default:
    assert(false && "repl mode not implemented");
    break;
  }
  
  return 0;
}

void run(char *filepath) {
  printf("todo");
}
