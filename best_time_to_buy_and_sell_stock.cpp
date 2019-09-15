class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    vector<int> t;

    for (int i = 1; i < prices.size(); i++)
    {
      t.push_back(prices[i] - prices[i - 1]);
    }

    int ans = 0;
    int sum = 0;

    for (int i = 0; i < t.size(); i++)
    {
      if (sum + t[i] < 0)
        sum = 0;
      else
        sum = sum + t[i];

      if (sum > ans)
        ans = sum;
    }

    return ans;
  }
}; 
