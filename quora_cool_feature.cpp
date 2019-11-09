#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

map <int, int> m;


void modifyArray(vector < int > &b, int x, int y){
  b[x-1] = y;
  return;
}

int search(vector<int> b, int k){
  int ans = 0;

  for(auto j: b){
    if(m[k-j])ans++;
  }

  return ans;
}

vector<int> coolFeature(vector<int> a, vector<int> b, vector<vector<int>> v)
{
  vector <int> ans;

  for(int i: a){
    m[i]++;
  }

  for(auto i: v){
    if(i.size()==3){
      modifyArray(b, i[1], i[2]);
    }

    else {
      int s = search(b, i[1]);
      ans.push_back(s);
    }
  }
  return ans;
}

int main()
{
  vector<int>a = {1,2,3};
  vector < int> b = {3,4};

  vector < vector < int > > v = {
    {1,5},
    {1,1,1},
    {1,5}
  };
  vector < int> ans = coolFeature(a, b, v);

  for(int i: ans){
    cout << i << " ";
  }
  return 0;
}
