class Solution
{
public:
  int numPairsDivisibleBy60(vector<int> &time)
  {
    int ans = 0;

    map<int, int> m;

    for (int i = 0; i < time.size(); i++)
    {
      m[time[i] % 60]++;
    }

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
      if (m[60 - it->first] && it->first != 30)
      {
        ans += m[60 - it->first] * m[it->first];
      }
      else if (it->first == 0 || it->first == 30)
      {
        ans += (m[it->first] * (m[it->first] - 1)) / 2;
      }

      m[it->first] = 0;
    }

    return ans;
  }
};
