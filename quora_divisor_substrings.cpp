#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int divisorSubstring(int n, int k)
{
  int ans = 0;

  string s = to_string(n);
  map < string, int > m;

  int i = 0;

  while(true){
    if(i+k<=s.size()){
      string t = s.substr(i, k);
      if(m[t]){
        i++;
        continue;
      }
      m[t]++;
      int y = stoi(t);
      if(y!=0 && n%stoi(t)==0)ans++;
      i++;
    } else {
      break;
    }
  }

  return ans;
}

int main()
{
  cout << divisorSubstring(120, 1);
  return 0;
}
