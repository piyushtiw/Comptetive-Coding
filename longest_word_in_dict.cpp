bool mycomp(string &a, string &b)
{
  return (a.size() < b.size());
}

class Solution
{
public:
  string longestWord(vector<string> &words)
  {
    sort(words.begin(), words.end(), mycomp);
    map<string, int> m;

    int max = 0;
    int cur = 0;
    string ans = "";

    for (string s : words)
    {
      string k = s.substr(0, s.size() - 1);

      if (s.size() == 1)
      {
        m[s] = 1;
        if (ans.size() < 1)
          ans = s;
      }

      if (m[k])
      {
        cur = m[k] + 1;
        m[s] = m[k] + 1;

        if (cur >= max)
        {
          max = cur;

          if (ans.size() == s.size() && ans.compare(s) > 0)
          {
            ans = s;
          }
          else if (ans.size() < s.size())
            ans = s;
        }
      }
      else
      {
        cur = 0;
      }
    }

    return ans;
  }
};
