#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

bool constructorNames(string a, string b)
{
  bool ans = false;

  if(a.size()!=b.size())return false;
  map < char, int > m;
  map <char, int> n;

  for(char i: a){
    m[i]++;
  }

  for (char i : b)
  {
    n[i]++;
  }

  int t=0;
  char f1;
  char f2;
  for(auto i: m){
    if(n[i.first] != i.second){
      t++;

      if(t>2)return false;

      if(t==1)f1=i.first;
      if (t == 2)
        f2 = i.first;
    }
  }

  if(t==0)return true;
  if(m[f1] == n[f1] && m[f2] == n[f2])return true;
  return ans;
}

int main()
{
  cout << constructorNames("x", "y");
  return 0;
}
