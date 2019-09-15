class Solution
{
public:
  vector<ListNode *> splitListToParts(ListNode *root, int k)
  {
    int l = length(root);

    vector<ListNode *> ans;

    int per = l / k;
    int extra = l % k;

    ListNode *temp = root;
    int z;

    for (int i = 0; i < k; i++)
    {
      ans.push_back(temp);

      if (temp == NULL)
        continue;
      int n = 0;
      if (extra > 0)
        z = 1;
      else
        z = 0;

      extra--;

      while (n < per + z - 1)
      {
        temp = temp->next;
        n++;
      }

      ListNode *tem = temp->next;
      if (temp != NULL)
        temp->next = NULL;
      temp = tem;
    }

    return ans;
  }

  int length(ListNode *root)
  {
    int len = 0;
    while (root != NULL)
    {
      len++;
      root = root->next;
    }
    return len;
  }
};
