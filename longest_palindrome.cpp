class Solution
{
public:
  int longestPalindrome(string s)
  {
    map<char, int> m;

    for (auto i : s)
    {
      m[i]++;
    }

    int odd_add = 0;
    int ans = 0;
    for (auto it : m)
    {
      if (it.second % 2 == 0)
        ans += it.second;
      else
      {
        ans += it.second - 1;
        odd_add = 1;
      }
    }

    return (ans + odd_add);
  }
};
