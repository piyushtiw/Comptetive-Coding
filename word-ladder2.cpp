class Solution
{
  struct TreeNode
  {
    string s;
    int len;
    struct TreeNode *t;
  };

  struct TreeNode *make_struct(string st, struct TreeNode *f, int len)
  {
    struct TreeNode *n = new TreeNode;
    n->s = st;
    n->t = f;
    n->len = len;
    return n;
  }

  bool is_not_already_added(string tmp, struct TreeNode *t)
  {
    while (t != NULL)
    {
      if (t->s == tmp)
        return false;
      t = t->t;
    }

    return true;
  }

public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    queue<struct TreeNode *> q;

    vector<vector<string>> ans;

    //unordered_set<string>se(wordList.begin(), wordList.end());

    map<string, int> m;
    map<string, int> v;

    for (string s : wordList)
    {
      m[s]++;
    }

    q.push(make_struct(beginWord, NULL, 1));

    bool more_queue = false;

    int ml = INT_MAX;

    while (!q.empty())
    {
      struct TreeNode *t = q.front();
      q.pop();

      if (t->s == endWord)
      {
        if (t->len <= ml)
        {
          ml = t->len;
          vector<string> temp;

          while (t != NULL)
          {
            temp.insert(temp.begin(), t->s);
            t = t->t;
          }

          ans.push_back(temp);
          more_queue = true;
        }
      }

      if (!more_queue)
      {
        for (int i = 0; i < t->s.size(); i++)
        {
          string tmp = t->s;
          for (int j = 0; j < 26; j++)
          {
            tmp[i] = 'a' + j;
            if ((!v[tmp] || is_not_already_added(tmp, t)) && m[tmp])
            {
              q.push(make_struct(tmp, t, t->len + 1));
              v[tmp]++;
            }
          }
        }
      }
    }

    return ans;
  }
};
