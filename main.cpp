// Austin Tilton July 2018
#include "markov.h"

/**
 * Main function call.
 *
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 *
 * @return Exit code.
 *
 */
int main(int argc, char* argv[])
{
  Markov markov; // create markov object
  if( argc < 2 )
    markov.print_help(); // if no arguments provided, show help prompt
  else
    markov.first_command(argc, argv); // otherwise, parse command arguments

  return 0;
}
