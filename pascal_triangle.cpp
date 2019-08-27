#include <iostream>
#include <stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector < vector < int > > v;
        
        int i = 0;
        while(numRows--){
            vector<int> temp;
            i++;
            if(i == 1){
                temp.push_back(1);
            } else if ( i == 2 ){
                temp.push_back(1);
                temp.push_back(1);
            } else {
                for(int j = 0; j < i; j++){
                    if(j == 0 || j == i-1)temp.push_back(1);
                    else {
                        temp.push_back(v[i-2][j] + v[i-2][j-1]);
                    }
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};

int main()
{

  Solution obj;
  vector < vector < int > > ans = obj.generate(5); 
  
  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
