#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution
{
  bool is_next_in_sequence(string a, string b)
  {
    int ans = 0;

    if (a.size() != b.size())
      return false;

    for (int j = 0; j < a.size(); j++)
    {
      if (a[j] != b[j])
        ans++;
    }

    if (ans == 1)
      return true;

    return false;
  }

  struct Tn
  {
    string s;
    int k;
  };

  struct Tn make_struct(string s, int i)
  {
    struct Tn t;
    t.s = s;
    t.k = i;
    return t;
  }

public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {

    queue<struct Tn> q;

    unordered_set<string> se(wordList.begin(), wordList.end());

    q.push(make_struct(beginWord, 0));

    int ans = 0;

    while (!q.empty())
    {
      struct Tn t = q.front();
      q.pop();

      if (t.s == endWord)
        return t.k + 1;

      for (int i = 0; i < t.s.size(); i++)
      {
        string tmp = t.s;
        for (int j = 0; j < 26; j++)
        {
          tmp[i] = 'a' + j;
          if (se.count(tmp))
          {
            q.push(make_struct(tmp, t.k + 1));
            se.erase(tmp);
          }
        }
      }
    }

    return 0;
  }
};


int main(){
  
}
