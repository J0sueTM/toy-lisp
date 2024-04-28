#include "./io.h"

Mode get_mode(int argc, char **argv) {
  if (argc <= 1) {
    return MODE_REPL;
  }

  if (strcmp(argv[1], "comp") == 0) {
    assert(argc == 4 && "invalid argc. expects 3.");
    return MODE_COMP;
  } else if (!strcmp(argv[1], "run")) {
    assert(argc == 3 && "invalid argc. expects 2.");
    return MODE_RUN;
  }

  return MODE_REPL;
}
