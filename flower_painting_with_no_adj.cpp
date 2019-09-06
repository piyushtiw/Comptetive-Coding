#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
  vector<int> gardenNoAdj(int N, vector<vector<int> > &paths)
  {
    vector<int> ans(N, 210);
    map<int, vector<int> > m;

    for (int i = 0; i < paths.size(); i++)
    {
      if (paths[i][0] < paths[i][1])
        m[paths[i][0]].push_back(paths[i][1]);
      else
        m[paths[i][1]].push_back(paths[i][0]);
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
      int q = get_min_value(ans[(it->first) - 1]);
      ans[(it->first) - 1] = q;

      for (int i = 0; i < it->second.size(); i++)
      {
        if (it->first < it->second[i])
        {
          ans[(it->second[i]) - 1] = get_value(ans[(it->second[i]) - 1], q);
        }
      }
    }

    for (int i = 0; i < ans.size(); i++)
    {
      if (ans[i] > 4)
      {
        ans[i] = get_min_value(ans[i]);
      }
    }

    return ans;
  }

private:
  vector<int> v{2, 3, 5, 7};
  vector<int> t{1, 2, 3, 4};

  int get_value(int val, int n)
  {
    if (val % v[n - 1] != 0)
      return val;
    return (val / v[n - 1]);
  }

  int get_min_value(int val)
  {
    for (int i = 0; i < v.size(); i++)
    {
      if (val % v[i] == 0)
        return t[i];
    }
    return 1;
  }
};

int main()
{

  Solution obj;

  int n = 4;
  //[[1,2],[3,4]]
  vector <vector < int > > v;


  vector<int> temp;
  temp.push_back(1);
  temp.push_back(2);
  vector<int> temp1;
  temp1.push_back(3);
  temp1.push_back(4);
  v.push_back(temp);
  v.push_back(temp1);

  vector<int> ans=obj.gardenNoAdj(n, v);

  for(int i = 0; i< ans.size(); i++){
    cout << ans[i] << " ";
  }

  cout << endl;
  return 0;
}
