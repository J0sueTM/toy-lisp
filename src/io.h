#ifndef IO_H
#define IO_H

#include <string.h>
#include <assert.h>

typedef enum Mode {
  MODE_COMP, // compilation
  MODE_RUN,
  MODE_REPL
} Mode;

Mode get_mode(int argc, char **argv);

#endif
