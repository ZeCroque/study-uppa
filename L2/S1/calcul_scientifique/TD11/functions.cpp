#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;

char intToChar(int a)
{
  if (a>=0 && a<=9)
  {
    return '0'+a;
  }
  else
  {
    return 'A'+a-10;
  }
  return '\0';
}

string convertIntToBase(int x, int b)
{
  int tmp=x;
  string str="";
  string buf="";

  if (b<17)
  {
    if (tmp==0)
    {
      return "0";
    }
    while (tmp!=0)
    {
      buf=intToChar(tmp%b);
      str.insert(0, buf);
      tmp/=b;
    }
    return str;
  }

  cout<<"ERREUR BASE MAX 16"<<endl;
  return "\0";
}

string convertFloatToBase(int num, int denom, int b)
{
  bool loop=true;
  int i=0;
  int quotient=(num/denom);
  int tmp=num-(quotient*denom);
  vector<int> numPrecedent;
  numPrecedent.push_back(0);

  string str="";
  string buf="";

  if (b<17)
  {
    str=convertIntToBase(quotient, b)+'.';

    while(loop)
    {
      tmp*=b;
      quotient=(tmp/denom);
      tmp-=(quotient*denom);

      if(quotient>0)
      {
        str.append("1");
      }
      else
      {
        str.append("0");
      }

      for(i=0; i<numPrecedent.size() && numPrecedent[i]!=tmp; i++);

      if(i==numPrecedent.size())
      {
        numPrecedent.push_back(tmp);
      }
      else
      {
        loop=false;
        if(tmp!=0)
        {
          str.erase(str.size()-1,str.size());
          str.append("...");
        }
      }
    }

    return str;
  }

  cout<<"ERREUR BASE MAX 16"<<endl;
  return "\0";
}

string convertFloatToBinary(float x)
{
  bool loop=true;
  int i=0;
  int entier=(int)x;
  double tmp=x-entier;
  vector<int> numPrecedent;
  numPrecedent.push_back(0);

  string str="";
  string buf="";

    while(loop)
    {
      tmp*=2;
      entier=(int)tmp;
      tmp-=entier;

      if(entier>0)
      {
        str.append("1");
      }
      else
      {
        str.append("0");
      }

      for(i=0; i<numPrecedent.size() && numPrecedent[i]!=tmp; i++);

      if(i==numPrecedent.size())
      {
        numPrecedent.push_back(tmp);
      }
      else
      {
        loop=false;
        str.erase(str.size()-1,str.size());
      }
    }

    return str;
}

float convertIEEE754ToFloat(string x)
{
  int i=0;
  float exposant=0;
  float mantisse=0;

  for(i=9; i<32; i++)
  {
    exposant+=(x[i]-'0')*pow(2,-(i-8));
  }

  for(i=1; i<9; i++)
  {
    mantisse+=(x[i]-'0')*pow(2,8-i);
  }
  mantisse-=128;
  mantisse=pow(2,mantisse);

  return (1-2*(x[0]-'0'))*exposant*mantisse;

}

string convertFloatToIEEE754(float x)
{
  int i=0;
  float tmp=x;
  string mantisse;
  string exposant;

  do
  {
      tmp=x/pow(2,i);
      i++;
  } while(tmp>1.0);

  mantisse=convertFloatToBinary(tmp);
  exposant=convertIntToBase(i+127,2);
  for(i=mantisse.size(); i<23; i++)
  {
    mantisse+="0";
  }

  if(x>0)
  {
    return "0"+exposant+mantisse;
  }
  return  "1"+exposant+mantisse;

}
