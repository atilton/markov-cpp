// Austin Tilton March 2018
#include "markov.h"
using namespace std;

/**
 * Loads the given wordlist, creates a dictionary object in program memory
 * and then writes the assembled dictionary to the given dictionary file
 * location to be loaded at a later time.
 *
 * @param wordlist File location for wordlist text file
 * @param link_size Number of links in new dictionary's key
 * @param dict_file File location at which new dictionary will be saved
 *
 * @return True on successful creation, False on an invalid wordlist file
 *
 */
bool Markov::create_dictionary(char* wordlist, int link_size, char* dict_file)
{
  ifstream wordlist_f(wordlist);
  
  // error checking, make sure given wordlist file is valid
  if( !wordlist_f.good() )
  {
    cerr << wordlist << " is an invalid file.\n";
    return false;
  }

  // instantiate new dictionary object, perform the creation and saving
  Dictionary new_dict;
  new_dict.create(wordlist, link_size);
  new_dict.save(dict_file);

  return true; // success
}

/**
 * Assuming a valid primary command is recieved from main(), perform the
 * additional error checking necessary for each command, and then call
 * the appropriate function for that command.
 *
 * @param argc Number of arguments provided by main().
 * @param argv Array of command line parameters from main().
 *
 */
void Markov::first_command(int argc, char* argv[])
{
  string s = argv[1];
  
  // check for invalid commands, any not in map are not supported
  if( commands.find(s) == commands.end() )
  {
    cout << s << " is an invalid command. See $markov help\n";
    return;
  }

  Command command = commands[s];

  // perform appropriate error checking and function calls for each command
  switch(command)
  {
    // check for correct argument count and prompt appropirate error lines
    case CREATE:
    if( argc != 5 )
      cout << "Usage:\n  markov create <wordlist> <link size> <dictionary>\n";
    else
      if( !create_dictionary(argv[2], atoi(argv[3]), argv[4]) )
        return;
    break;

    case LOAD:
    if( argc != 3 )
      cout << "Usage:\n  markov load <dictionary>\n";
    else
      cout << "Load command\n";
    break;

    case PRINT:
    if( argc != 4 )
      cout << "Usage:\n  markov print <dictionary> <length>\n";
    else
      cout << "Print command\n";
    break;

    case START:
    if( argc != 2 && argc != 3 )
      cout << "Usage:\n  markov start <dictionary>(OPTIONAL)\n";
    else
      cout << "Start command\n";
    break;

    case HELP:
    print_help();
    break;
  }

  return;
}

void Markov::print_help()
{
  cout << "Usage: <operation> <arguments...>\n"
    << "operations:\n"
    << "  create <wordlist> <link size> <dictionary>:\n"
    << "    Generates a dictionary from a given wordlist file & link\n"
    << "    size. The resulting dictionary is saved into <dictionary>.\n"
    << "  load <dictionary>:" << endl
    << "    Loads a given dictionary file and then enters command line\n"
    << "    mode.\n"
    << "  print <dictionary> <length>:\n"
    << "    Loads a given dictionary file then generates text of <length>\n"
    << "    size output.\n"
    << "  start <dictionary>(OPTIONAL):\n"
    << "    Begins the program in command line mode. If a dictionary file\n"
    << "    is provided, it will be loaded first.\n"
    << "  help:\n"
    << "    Prints this usage prompt\n";
}

/**
 * Markov class initialization function.
 *
 * Initializes the valid primary command keywords in the commands map,
 * for quick reference upon parsing.
 *
 */
Markov::Markov()
{
  commands["create"] = CREATE;
  commands["c"] = CREATE;
  commands["load"] = LOAD;
  commands["l"] = LOAD;
  commands["print"] = PRINT;
  commands["p"] = PRINT;
  commands["start"] = START;
  commands["s"] = START;
  commands["help"] = HELP;
  commands["h"] = HELP;
}

