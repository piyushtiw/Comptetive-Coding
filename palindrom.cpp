#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution1
{
public:
  bool isPalindrome(int x)
  {
    stack<int> s;

    if (x < 0)
      return false;
    int l = 0;

    while (x != 0)
    {
      int d = x % 10;
      s.push(d);
      x = x / 10;
      l++;
    }

    int y = l / 2;
    stack<int> q;
    for (int i = 0; i < y; i++)
    {
      int d = s.top();
      q.push(d);
      s.pop();
    }

    if (l % 2 != 0)
      s.pop();

    while (!s.empty())
    {
      if (s.top() != q.top())
        return false;
      s.pop();
      q.pop();
    }
    return true;
  }
};

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

  Solution1 obj;

  int t = 505;

  bool h = obj.isPalindrome(t);

  cout << h << endl;
  return 0;
}
