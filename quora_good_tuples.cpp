#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int goodTuples(vector<int> v)
{
  int ans = 0;
  if(v.size()< 3)return 0;

  int a = v[0];
  int b = v[1];

  for(int i = 2; i < v.size(); i++){
    if(v[i]==a && v[i]!=b)ans++;
    else if(v[i]==b && v[i]!= a)ans++;
    else if(a==b && v[i]!= a)ans++;

    a=b;
    b=v[i]; 
  }

  return ans;
}

int main()
{
  vector<int> v = {1,2,2,1,5,3,2,3};

  cout << goodTuples(v);
  return 0;
}
