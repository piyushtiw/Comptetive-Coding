#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
using namespace std;

bool mucomp(const pair<int, string> &v1, const pair<int, string> &v2){
  return (v1.first > v2.first);
}

vector<string> strangeSort(vector<int> mapping, vector<string> nums)
{
  vector<string> ans;

  map<int, int> m;

  for(int i = 0 ; i < mapping.size(); i++){
    m[mapping[i]]=i;
  }

  vector<pair< pair<int, int>, string> > v;
  for(int i=0; i<nums.size(); i++){
      string s = nums[i];
      int t = 0;

      for(char c: s){
        int x = m[c-'0'];
        t = t * 10 + x;
      }
      v.push_back(make_pair(make_pair(t,i) , s));
  }

  std::sort(v.begin(), v.end(), [](auto &left, auto &right) {
    if (left.first.first == right.first.first){
      return (left.first.second < right.first.second);
    }
      return (left.first.first < right.first.first);
  });

  for(auto i: v){
    ans.push_back(i.second);
  }

  return ans;
}

int main()
{
  vector<int> a = {2,1,4,8,6,3,0,9,7,5};
  vector<string> b = {"12", "02", "4", "023", "65", "83", "224", "50"};

  vector < string > ans;
  ans = strangeSort(a, b);

  for(auto s: ans){
    cout << s << " ";
  }
  return 0;
}
