#include <iostream>
#include <stdio.h>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;

class KthLargest
{
public:
  KthLargest(int k, vector<int> &nums)
  {
    for (int i = 0; i < nums.size(); i++) {
        q.push(nums[i]);
        if (q.size() > k) q.pop();
    }
    m = k;
  }

  int add(int val)
  {
    q.push(val);
    if (q.size() > m) q.pop();
    return q.top();
  }

private:
  int m;
  priority_queue< int, vector<int>, greater<int> > q;
};

int main()
{
  int k = 2;
  vector< int > nums;

  nums.push_back(0);

  KthLargest *obj = new KthLargest(k, nums);
  int param_1 = obj->add(-1);
  cout << param_1 << endl;
  return 0;
}
