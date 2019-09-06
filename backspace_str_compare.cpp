#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  bool backspaceCompare(string S, string T)
  {
    string temp = "";

    stack<char> s;

    for (int i = 0; i < S.size(); i++)
    {
      if (S[i] == '#')
      {
        if (!s.empty())
          s.pop();
      }
      else
      {
        s.push(S[i]);
      }
    }

    stack<char> t;

    for (int i = 0; i < T.size(); i++)
    {
      if (T[i] == '#')
      {
        if (!t.empty())
          t.pop();
      }
      else
      {
        t.push(T[i]);
      }
    }

    if (s.size() != t.size())
      return false;

    while (!s.empty())
    {
      if (s.top() != t.top())
        return false;
      s.pop();
      t.pop();
    }

    return true;
  }
};

int main()
{

  Solution obj;

  string s = "ab#c", t = "ad#c";

  bool h = obj.backspaceCompare(s, t);

  cout << h << endl;
  return 0;
}
