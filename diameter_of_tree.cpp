#include <stdio.h> 
#include <stdlib.h> 
#include<iostream>

using namespace std;

struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 

class Solution {
public:
    int diameterOfBinaryTree(struct node* root) {
        if(root == NULL)return 0;
        
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        int k = diameterOfBinaryTree(root->left);
        int j = diameterOfBinaryTree(root->right);
        
        return max((lheight + rheight + 1), max(k, j));
    }
private:
    int height(struct node *root){
        if(root==NULL)return 0;
        
        return (1 + max(height(root->left), height(root->right)));
    }
};
 
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 

int max(int a, int b) 
{ 
  return (a >= b)? a: b; 
}     

int main() 
{
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);

  Solution obj;
  
  printf("Diameter of the given binary tree is %d\n", obj.diameterOfBinaryTree(root)); 
  return 0; 
} 
