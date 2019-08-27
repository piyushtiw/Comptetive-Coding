#include <iostream>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.size() < s.size())return false;
        int start = 0;
        for(int i = 0; i<s.size(); i++){
            while(start < t.size()){
                if(t[start] == s[i]){
                    start++;
                    break;
                }
                if(start == t.size()-1)return false;
                start++;
            }
        }
        
        if(start == t.size() && s[s.size()-1] != t[t.size()-1])return false;
        
        return true;
    }
};

int main()
{

  Solution obj;
  bool ans = obj.isSubsequence("abc", "aaabbccc"); 
  
  cout << ans << endl;
  return 0;
}
