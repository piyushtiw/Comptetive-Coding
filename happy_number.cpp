#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

class Solution
{
public:
  bool isHappy(int n)
  {
    map<int, int> m;

    while (n != 1)
    {
      int sum = 0;
      int c = n;

      while (c != 0)
      {
        sum += (c % 10) * (c % 10);
        c = c / 10;
      }

      if (!m[sum])
        m[sum] = 1;
      else
        return false;

      n = sum;
    }

    return true;
  }
};

int main()
{
  Solution obj;
  bool k = obj.isHappy(19);

  cout << k << endl;

  return 0;
}
