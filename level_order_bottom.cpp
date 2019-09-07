#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<queue>
#include<vector>

using namespace std;

struct node
{
  int data;
  struct node *left, *right;
};

class Solution
{
public:
  vector<vector<int> > levelOrderBottom(struct node *root)
  {
    vector<vector<int> > ans;
    vector<vector<int> > v;
    if (root == NULL)
      return ans;
    
    queue<struct node *> q;

    q.push(root);
    q.push(NULL);
    vector<int> t;

    while (!q.empty())
    {
      struct node *temp = q.front();
      q.pop();

      if (temp == NULL)
      {
        v.push_back(t);
        t.clear();
        if (!q.empty())
          q.push(NULL);
        continue;
      }

      t.push_back(temp->data);
      if (temp->left != NULL)
        q.push(temp->left);
      if (temp->right != NULL)
        q.push(temp->right);
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
      ans.push_back(v[i]);
    }

    return ans;
  }
};

struct node *newNode(int data)
{
  struct node *node = (struct node *)
      malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

int max(int a, int b)
{
  return (a >= b) ? a : b;
}

int main()
{
  struct node *root = newNode(3);
  root->left = newNode(9);
  root->right = newNode(20);
  root->left->left = newNode(17);
  root->left->right = newNode(7);

  Solution obj;

  vector< vector < int> > v = obj.levelOrderBottom(root);

  for(int i = 0; i< v.size(); i++){
    for(int j = 0; j < v[i].size(); j++){
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
