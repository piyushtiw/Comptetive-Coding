#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int find_words(vector<string> v, vector<string> words)
{
  int ans = 0;
  
  map <string, int> m;
  for(string i: v){
    m[i]++;
  }

  for(string s: words){
    if(m[s]){
      ans++;
      continue;
    }
    
    for(int i = 1; i<s.size(); i++){
      string s1 = s.substr(0, i);
      string s2 = s.substr(i, s.size());

      if(m[s1] && m[s2]){
        ans++;
        break;
      }
    }
  }

  return ans;
}

int main()
{
  vector<string> v = {"one", "two", "three"};
  vector<string> words = {"one", "onetwo", "onethre"};

  cout << find_words(v, words);
  return 0;
}
