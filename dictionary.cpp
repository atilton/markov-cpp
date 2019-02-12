// Austin Tilton March 2018
#include "dictionary.h"

/**
 * Generates a string with a given number of words using the currently loaded
 * dictionary of this object. If this dictionary object is not initialized or
 * has no valid dictionary currently loaded, an exception will be thrown.
 *
 * @param length Number of words that will be put into the returned string
 *
 * @return Fully formatted string of provided length of successful return
 */

string Dictionary::generate(int length)
{
  
  return "";
}

/**
 * Creates a new dictionary object using the provided wordlist file as a
 * source with a key containing <link_size> number of words. The resulting
 * dictionary will be stored in this object during program runtime.
 *
 * @param wordlist_location File location for the wordlist text file
 * @param link_size Number of links in new dictionary's key
 *
 */
void Dictionary::create(char* wordlist_location, int link_size)
{
  // initialization
  ifstream wordlist_f(wordlist_location); //open wordlist file (already valid)
  string line, word;
  dict.clear(); // Reset the dictionary incase there is already one loaded
  vector<string> current_key; // vector key for the current key/value pair
  
  // while loop to process wordlist one line at a time
  while( getline(wordlist_f, line) )
  {
    // Each new line represents beginning of new quote
    for(int i = 0; i < link_size; i++)
      current_key.push_back("NULL"); // thus, set NULL flags on all keys

    stringstream ss(line);
    line >> word;
    
    for(int i = 0; i < link_size-1; i++)
      current_key[i] = current_key[i+1];
  }

  return;
}

/**
 * Saves the dictionary stored in this object to a formatted file at the
 * provided <dictionary_location> spot. 
 *
 * @param dictionary_location File location dictionary to be saved at
 *
 * @return True on successful save, false when current dictionary empty
 */
bool Dictionary::save(char* dictionary_location)
{
  

  return true;
}
