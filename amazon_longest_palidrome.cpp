class Solution
{
public:
  string longestPalindrome(string s)
  {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for (int i = 0; i < s.size(); i++)
    {
      dp[i][i] = true;
      if (i != s.size() and s[i] == s[i + 1])
      {
        dp[i][i + 1] = true;
      }
    }
    for (int i = s.size() - 1; i >= 0; i--)
    {
      for (int j = i + 2; j < s.size(); j++)
      {
        if (j - i >= 2)
        {
          if (s[i] == s[j] and dp[i + 1][j - 1])
          {
            dp[i][j] = true;
          }
        }
      }
    }
    int tmp = 0;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
      for (int j = i; j < s.size(); j++)
      {
        if (dp[i][j])
        {
          if (j - i + 1 > tmp)
          {
            tmp = j - i + 1;
            res = s.substr(i, j - i + 1);
          }
        }
      }
    }
    return res;
  }
};
