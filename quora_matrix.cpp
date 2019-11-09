#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> ans;

set<int> a;

void NumMatrix(vector<vector<int>> &matrix)
{
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      int k = 0, l = 0, m = 0;
      if (j - 1 >= 0)
        k = matrix[i][j - 1];
      if (i - 1 >= 0)
        l = matrix[i - 1][j];
      if (i - 1 >= 0 && j - 1 >= 0)
        m = matrix[i - 1][j - 1];
      matrix[i][j] = k + l - m + matrix[i][j];
    }
  }

  ans = matrix;
}

int sumRegion(int row1, int col1, int row2, int col2)
{
  int n = 0, m = 0, k = 0, l = 0;

  if (row1 - 1 >= 0)
  {
    l = ans[row1 - 1][col2];
  }

  if (col1 - 1 >= 0)
  {
    m = ans[row2][col1 - 1];
  }

  if (row1 - 1 >= 0 && col1 - 1 >= 0)
  {
    n = ans[row1 - 1][col1 - 1];
  }
  return (n + ans[row2][col2] - m - l);
}

vector<int> matrix(vector<vector<int>> v, int k)
{
  vector<int> y;
  vector<vector<int>> z = v;
  NumMatrix(v);

  int ma = INT_MIN;


  for(int i = 0; i< v.size(); i++){
    for(int j = 0; j < v[0].size(); j++){
      int t = i+k-1;
      int f = j+k-1; 
      if(t < v.size() && f < v[0].size()){
        int sum = sumRegion(i, j, t, f);

        if (sum > ma){
          a.clear();
          ma = sum;
        }
        if (sum >= ma)
        {
          for (int m = i; m <= t; m++)
          {
            for (int n = j; n <= f; n++)
            {
              a.insert(z[m][n]);
            }
          }
        }
      }
    }
  }


  for(int i: a){
    y.push_back(i);
  }
  return y;
}

int main()
{
  vector<vector<int>> v = {
    {1, 2, 1},
    {2, 2, 2},
    {1, -2, 8}
  };

  vector<int> y = matrix(v, 2);

  for(int i: y){
    cout << i << " ";
  }
  return 0;
}
