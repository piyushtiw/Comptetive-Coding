#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution
{
public:
  int longestArithSeqLength(vector<int> &A)
  {
    vector<vector<int> > dp(A.size(), vector<int>(A.size(), 0));
    int ans = 2;
    map<int, int> m;

    for (int i = 0; i < dp.size(); i++)
    {
      for (int j = i + 1; j < dp[i].size(); j++)
      {
        int x = 2 * A[i] - A[j];
        dp[i][j] = 2;

        if (m[x])
        {
          dp[i][j] = max(dp[m[x] - 1][i] + 1, dp[i][j]);
        }
        m[A[i]] = i + 1;
        if (ans < dp[i][j])
          ans = dp[i][j];
      }
    }

    return ans;
  }
};

int  main(){
  vector < int> v;
  v.push_back(2);
  v.push_back(2);
  v.push_back(2);
  v.push_back(2);

  Solution obj;

  cout << obj.longestArithSeqLength(v);

  return 0;
}
