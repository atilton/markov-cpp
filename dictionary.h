// Austin Tilton March 2018
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

/**
 * Dictionary object class.
 *
 * Abstracts the concept of a dictionary object, implements the creation
 * then loading/saving of dictionaries. With a dictionary object initialized,
 * randomly generated text of varying lengths can be produced.
 *
 */
class Dictionary
{
  public:
  void create(char* wordlist_location, int link_size);
  void load(char* dictionary_location);
  void save(char *save_location);
  string generate(int length);

  private:
  int m_link_size;
  map<vector<string>, string> dict;
};
