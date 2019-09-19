class Solution
{
public:
  string reverseStr(string s, int k)
  {
    string ans = "";
    int t = 0;
    stack<char> q;

    for (int i = 0; i < s.size(); i++)
    {
      t = i;
      while (i < k + t && i < s.size())
      {
        q.push(s[i]);
        i++;
      }

      while (!q.empty())
      {
        ans = ans + q.top();
        q.pop();
      }

      while (i < (2 * k) + t && i < s.size())
      {
        ans = ans + s[i];
        i++;
      }
      i--;
    }

    return ans;
  }
};
