#include<iostream>
#include<stdio.h>
#include<vector>
#include <string>

using namespace std;

vector<string> permuations(string s){
  vector<string> ans;

  if(s.size() <= 1){
  	ans.push_back(s);
  	return ans;
  }

  vector<string> pers = permuations(s.substr(1, s.size() - 1));

  char k = s[0];

  for(int i = 0; i < pers.size(); i++){
    for(int j = 0; j <= pers[i].size(); j++){
      string t = pers[i];
      ans.push_back(t.insert(j, 1, k)); 
    }
  }

  return ans;
}

int main(){
  string s = "abcd";
  vector < string > v =  permuations(s);

  for(int i = 0; i < v.size(); i++){
    cout << v[i] << endl;
  }
  return 0;
}
