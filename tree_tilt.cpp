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
    int findTilt(struct node* root) {
        if(root == NULL)return 0;
        
        int ltilt = findTilt(root->left);
        int rtilt = findTilt(root->right);
        
        int tilt = abs(sum_of_subtree_rooted_as_node(root->left) - sum_of_subtree_rooted_as_node(root->right));
        
        return(tilt + ltilt + rtilt);
    }
    
private:
    int sum_of_subtree_rooted_as_node(struct node* node){
        if(node == NULL)return 0;
        
        int k = sum_of_subtree_rooted_as_node(node->left);
        int j = sum_of_subtree_rooted_as_node(node->right);
        
        return (k + j + node->data);
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
  
  printf("%d\n", obj.findTilt(root)); 
  return 0; 
} 
