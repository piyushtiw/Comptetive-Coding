bool compare(string &a, string &b)
{
  return (a.size() < b.size());
}

class Solution
{
public:
  int longestStrChain(vector<string> &words)
  {
    sort(words.begin(), words.end(), compare);
    map<string, int> m;

    int ans = 0;
    for (int i = 0; i < words.size(); i++)
    {
      int best_len = 0;
      for (int j = 0; j < words[i].size() && words[i].size() > 1; j++)
      {
        string str = words[i].substr(0, j) + words[i].substr(j + 1);

        if (m[str])
        {
          if (m[str] + 1 > best_len)
          {
            best_len = m[str] + 1;
          }
        }
      }

      m[words[i]] = best_len + 1;
      if (ans < m[words[i]])
        ans = m[words[i]];
    }

    return ans;
  }
};
