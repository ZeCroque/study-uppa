#include "outils.h"

using namespace std;

unsigned int readUnsignedInt()
{
  string input="";
  unsigned int result=0;

  cin>>input;
  for(unsigned int i=0; i<input.size(); i++)
  {
    if(input[i]<='0' && input[i]>='9')
    {
      return -1;
    }
    result*=10;
    result+=input[i]-'0';
  }
  return result;
}

int readBool()
{
  string input="";
  cin>>input;

  if(input!="y" && input!="n")
  {
    return -1;
  }
  return input=="y";
}

string intToString(int number)
{
  stringstream stream;
  stream<<number;
  return stream.str();
}
