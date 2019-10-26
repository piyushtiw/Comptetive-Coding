#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int largestRectangleArea(vector<int> &heights)
{
  vector<int> v = heights;
  int a = 0;
  int ma = 0;
  int t;
  int i = 0;
  stack<int> s;

  while (i < v.size())
  {
    if (s.empty() || v[i] >= v[s.top()])
    {
      s.push(i++);
    }
    else
    {
      t = s.top();
      s.pop();
      a = v[t] * (s.empty() ? i : i - s.top() - 1);
      cout << t << " " << a << endl;
      if (ma < a)
        ma = a;
    }
  }

  while (!s.empty())
  {
    t = s.top();
    s.pop();
    a = v[t] * (s.empty() ? i : i - s.top() - 1);
    cout << "----------- " << t << " " << a << endl;
    if (ma < a)
      ma = a;
  }

  return ma;
}


int main(){
  vector<int> v = {2,0,2,1,1};

  cout << largestRectangleArea(v) << endl;
  return 0;
}
