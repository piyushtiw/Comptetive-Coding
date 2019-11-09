#include <iostream>
#include <cstdio>
#include<vector>

using namespace std;

int maxElevation(int columnCount, int rowCount, vector< vector < int > > mat){
  int ans = 0;

  mat[rowCount - 1][columnCount - 1] = INT_MAX;
  vector<vector<int>> dp(rowCount, vector<int>(columnCount, INT_MAX));

  for(int i = 0; i< rowCount; i++){
    for(int j = 0; j < columnCount; j++){
      if((i==0 && j==0))continue;
      int a=INT_MIN, b=INT_MIN;
      if(i-1>=0)a = dp[i-1][j];
      if(j-1>=0)b = dp[i][j-1];

      dp[i][j] = min(mat[i][j], max(a, b));
    }
  }

  ans = dp[rowCount-1][columnCount-1];
  return ans;
}

int main(){
  vector< vector < int > > v = {
    {1, 2, 3},
    {4, 5, 1}
  };

  cout << maxElevation(3, 2, v);
  return 0;
}
