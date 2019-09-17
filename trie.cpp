#include<iostream>
#include<stdio.h>

using namespace std;

struct Node
{
  bool isEndOfWord;
  Node* children[26];
};


Node* newNode()
{
  Node* node = new Node;
  node->isEndOfWord = false;
  for (int i = 0; i < 26; i++)
    node->children[i] = NULL;
  return (node);
}

void insert(Node *root, string w)
{
  Node* temp = root;

  for (int i = 0; i < w.size(); i++)
  {
    int index = w[i] - 'a';
    if (!temp->children[index])
      temp->children[index] = newNode();

    temp = temp->children[index];
  }

  temp->isEndOfWord = true;
}

bool search(Node* root, string key)
{
  struct Node* temp = root;

  for (int i = 0; i < key.length(); i++)
  {
    int index = key[i] - 'a';
    if (!temp->children[index])
      return false;

    temp = temp->children[index];
  }

  return (temp != NULL && temp->isEndOfWord);
}

int main(){
  string words[] = {"the", "a", "there",
                    "answer", "any", "by",
                    "bye", "their"};

  int n = sizeof(words) / sizeof(words[0]);

  Node *root = newNode();

  for (int i = 0; i < n; i++)
  {
    insert(root, words[i]);
  }

  bool k = search(root, "anyt");
  cout << k << endl;

  return 0;
}

