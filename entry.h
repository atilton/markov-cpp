// Austin Tilton
#include<string>
#include<vector>

class Entry
{
  public:
  Entry(int link_size);
  bool matches(Entry other);
  Vector<string> key;
  int key_length;
  string value;
};
