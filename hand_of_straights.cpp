class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int W)
  {
    map<int, int> m;

    for (int i : hand)
    {
      m[i]++;
    }

    int i = 0;
    int k = hand.size();

    while (i < k)
    {
      int t;

      for (auto n : m)
      {
        if (n.second > 0)
        {
          t = n.first;
          break;
        }
      }

      int z = i;
      while (i < W + z && i < k)
      {
        if (!m[t])
        {
          return false;
        }
        m[t]--;
        t++;
        i++;
      }

      if (i - z != W)
      {
        return false;
      }
    }

    return true;
  }
};
