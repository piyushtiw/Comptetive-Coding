#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int> > &v, int i, int j, int dir){
  v[i][j] = -1;

  if (dir == 0){
    if (j + 1 < v[0].size() && v[i][j + 1] == 1){
      dfs(v, i, j + 1, dir);
      return;
    }

    if (j + 1 == v[0].size() || (j + 1 < v[0].size() && v[i][j + 1] != 1)){
      dir = 1;
      if(i+1 < v.size() && v[i+1][j] == 1){
        dfs(v, i+1, j, dir);
        return;
      }
    }
  }

  if (dir == 1)
  {
    if (i + 1 < v.size() && v[i+1][j] == 1)
    {
      dfs(v, i+1, j, dir);
      return;
    }

    if (i + 1 == v.size() || (i + 1 < v.size() && v[i+1][j] != 1))
    {
      dir = 2;
      if (j - 1 >= 0 && v[i][j-1] == 1)
      {
        dfs(v, i, j-1, dir);
        return;
      }
    }
  }

  if (dir == 2)
  {
    if (j - 1 >= 0 && v[i][j-1] == 1)
    {
      dfs(v, i, j-1, dir);
      return;
    }

    if (j - 1 < 0  || (j - 1 >= 0 && v[i][j-1] != 1))
    {
      dir = 3;
      if (i - 1 >= 0 && v[i-1][j] == 1)
      {
        dfs(v, i-1, j, dir);
        return;
      }
    }
  }

  if (dir == 3)
  {
    if (i - 1 >= 0 && v[i - 1][j] == 1)
    {
      dfs(v, i - 1, j, dir);
      return;
    }

    if (i - 1 < 0 || (i - 1 >= 0 && v[i - 1][j] != 1))
    {
      dir = 0;
      if (j + 1 < v[0].size() && v[i][j + 1] == 1)
      {
        dfs(v, i, j + 1, dir);
        return;
      }
    }
  }
}

int main()
{
  int n , m , k;

  cin >> n >> m >> k;

  vector< vector<int> > v (n, vector < int> (m, 1));

  int a, b;
  for(int i = 0; i< k; i++){
    cin >> a >> b;
    v[a-1][b-1] = 0;
  }

  dfs(v, 0, 0, 0);

  for(auto x: v){
    for(int j: x){
      if(j == 1){
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  cout << "YES" << endl;
  return 0;
}
