#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

vector<int> maxone(vector<int> &A, int B)
{
  vector<int> ans;
  int mss = 0, mse = 0;
  int i = 0;
  int zc = 0, ws = 0, ms = 0;
  int zsi = 0, zs = 0;

  while (i < A.size())
  {
    if(zc <= B){
      if(A[i] == 0){
        zc++;
      }
      i++;
    }

    if(zc > B){
      if(A[ws] == 0){
        zc--;
      }

      ws++;
    }

    if ((i - ws > ms) && (zc <= B))
    {
      ms = i - ws;
      mss = ws;
      mse = i;
    }
  }

  for(int j = mss; j < mse; j++){
    ans.push_back(j);
  }
  
  return ans;
}

int main(){
  vector<int> v(10, 1);

  v[2] = v[5] = v[6] = 0;

  vector<int> ans = maxone(v, 2);

  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }

  cout << endl;

  return 0;
}
