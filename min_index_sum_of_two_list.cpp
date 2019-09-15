class Solution
{
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
  {
    map<string, int> m;

    vector<string> ans;
    int t, min_index_sum = 10000000;

    for (int i = 0; i < list1.size(); i++)
    {
      m[list1[i]] = i + 1;
    }

    for (int i = 0; i < list2.size(); i++)
    {
      if (m[list2[i]])
      {
        t = m[list2[i]] - 1 + i;

        if (t <= min_index_sum)
        {
          if (ans.size() == 0)
          {
            ans.push_back(list2[i]);
            m[list2[i]] = m[list2[i]] - 1 + i;
          }
          else
          {
            if (m[ans[0]] > t)
            {
              ans.clear();
            }
            else if (m[ans[0]] < t)
              continue;

            ans.push_back(list2[i]);
            m[list2[i]] = m[list2[i]] - 1 + i;
          }
        }
      }
    }

    return ans;
  }
};
