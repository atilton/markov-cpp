// Austin Tilton
#include "entry.h"

Entry::Entry(int link_size) : key_length(link_size)
{
}

bool Entry::matches(Entry other)
{
  if( other.key_length != key_length )
    return false;

  for(int i = 0; i < key.size(); i++)
    if(key[i] != other.key[i])
      return false;
  return true;
}
