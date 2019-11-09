#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int max_ap(vector<int> a, vector<int> b){
  map<int, int> m;
  for(auto i: b){
    m[i]++;
  }

  vector<int> v;
  int min = INT_MAX;

  for(int i = 1; i< a.size(); i++){
    if(a[i]-a[i-1]<min)min = a[i]-a[i-1];
    v.push_back(a[i]-a[i-1]);
  }


  if(min == 0){
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i] != 0)
        return -1;
    }

    int ans = a.size();

    for(int i = 0; i < b.size(); i++){
      if(b[i]==a[0])ans++;
    }

    return ans;
  }

  int ans = a.size();
  int ret = 0;
  int y = 0;

  for (int i = 1; i < a.size(); i++)
  {
    if (a[i] - a[i - 1] != 1)
    {
      int t = a[i - 1] + 1;

      while (t != a[i])
      {
        if (!m[t]){
          ret = 1;
          break;
        }
        y++;
        t++;
      }
    }
  }

  if(ret == 0) return ans + y;

  for(int j = 0; j < v.size(); j++){
    if(v[j]%min != 0){
      return -1;
    }
  }

  for(int i = 0; i < v.size(); i++){
    if(v[i]-min==0)continue;

    while(a[i]+min != a[i+1]){
      if(!m[a[i]+ min])return -1;
      m[a[i]+min]--;
      a[i] = a[i]+min;
      ans++;
    }
  }

  while(m[a[a.size()-1]+min]){
    ans++;
    a[a.size() - 1] = a[a.size() - 1] + min;
  }

  return ans;
}

int main()
{
  vector < int > a = {0, 8, 12, 16};
  vector < int> b = {1,2,4,5,6,7,9,10,11,12,13,14,15,20, 28};

  cout << max_ap(a,b);
  return 0;
}
