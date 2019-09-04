#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int last = cost[1];
    int sec_last = cost[0];
    int ans = 0;
    int a = 0;

    for (int i = 2; i <= cost.size(); i++)
    {
      if (i == cost.size())
        a = 0;
      else
        a = cost[i];
      ans = min(last + a, sec_last + a);
      sec_last = last;
      last = ans;
    }

    return ans;
  }
};

int main()
{
  int k = 2;
  vector<int> nums;

  nums.push_back(10);
  nums.push_back(15);
  nums.push_back(20);

  Solution obj;
  int param_1 = obj.minCostClimbingStairs(nums);
  cout << param_1 << endl;
  return 0;
}
