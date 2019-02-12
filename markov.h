// Austin Tilton March 2018
#include<iostream>
#include<map>
#include<fstream>
#include "dictionary.h"
using namespace std;

enum Command {CREATE, LOAD, PRINT, START, HELP};

/**
 * Main program class.
 *
 * Responsible for initialization and the primary function commands to be
 * implemented, notably creating/loading/printing of dictionaries.
 *
 */
class Markov
{
  public:
  Markov();
  void first_command(int argc, char* argv[]);
  bool create_dictionary(char* wordlist, int link_size, char* dict_file);
  bool load_dictionary(string dict_file);
  bool print(string dict_file, int length);
  bool start_command_mode(string *dict_file);
  void print_help();

  private:
  map<string, Command> commands;
  Dictionary m_current_dictionary;
};
