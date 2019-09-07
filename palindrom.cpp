#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  bool isPalindrome(int x)
  {
    string t = to_string(x);

    int i = 0, j = t.size() - 1;

    while (j > i)
    {
      if (t[i] != t[j])
        return false;
      i++;
      j--;
    }

    return true;
  }
};

int main()
{

  Solution obj;

  int t = 505;

  bool h = obj.isPalindrome(t);

  cout << h << endl;
  return 0;
}
