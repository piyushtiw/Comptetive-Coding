#include <stdio.h> 
#include <stdlib.h> 
#include<iostream>
#include<vector>

using namespace std;

struct Node
{
  char data;
  vector<Node *> child;
};

class Solution {
public:
    int diameterOfTree(Node* root) {
        if(root == NULL)return 0;
        int max1 = 0;
        int max2 = 0;
        int max_dia = 0;

        for (vector<Node *>::iterator it = root->child.begin();
             it != root->child.end(); it++)
        {
          int k = height(*it);

          if(k> max1){
            max2 = max1;
            max1 = k;
          } else if ( k> max2){
            max2 = k;
          }
        }

        for (vector<Node *>::iterator it = root->child.begin();
             it != root->child.end(); it++)
        {
          max_dia = max(max_dia, diameterOfTree(*it));
        }
        
        return max((max1 + max2 + 1), max_dia);
    }

private:
    int height(Node *root){
      if(root==NULL)return 0;

      int max_height = 0;

      for (vector<Node *>::iterator it = root->child.begin();
          it != root->child.end(); it++){
        max_height = max(max_height, height(*it));
      }

      return (1 + max_height);
    }
};
 
Node* newNode(char data)
{ 
  Node* node = new Node;
  node->data = data;
  
  return(node); 
} 

int max(int a, int b) 
{ 
  return (a >= b) ? a: b; 
}     

int main() 
{
  Node *root = newNode('A');
  (root->child).push_back(newNode('B'));
  (root->child).push_back(newNode('F'));
  (root->child).push_back(newNode('D'));
  (root->child).push_back(newNode('E'));
  (root->child[0]->child).push_back(newNode('K'));
  (root->child[0]->child).push_back(newNode('J'));
  (root->child[2]->child).push_back(newNode('G'));
  (root->child[3]->child).push_back(newNode('C'));
  (root->child[3]->child).push_back(newNode('H'));
  (root->child[3]->child).push_back(newNode('I'));
  (root->child[0]->child[0]->child).push_back(newNode('N'));
  (root->child[0]->child[0]->child).push_back(newNode('M'));
  (root->child[3]->child[2]->child).push_back(newNode('L'));

  Solution obj;
  
  printf("Diameter of the given tree is %d\n", obj.diameterOfTree(root)); 
  return 0; 
} 
