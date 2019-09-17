#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
  int val;
  Node *next;
  Node *pre;
};

class MyCircularDeque
{
private:
  int size = 0;
  int max_size = 0;
  Node *f = NULL;
  Node *e = NULL;

  Node *newNode(int y)
  {
    Node *temp = new Node();

    temp->next = NULL;
    temp->pre = NULL;
    temp->val = y;
    return temp;
  }

public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k)
  {
    max_size = k;
  }

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  bool insertFront(int v)
  {
    if (size == max_size)
      return false;

    size++;

    Node *node = newNode(v);

    if (f == NULL)
    {
      node->pre = node;
      node->next = node;
      f = node;
      e = node;
    }
    else
    {
      node->next = f;
      f->pre = node;
      node->pre = e;
      e->next = node;
      f = node;
    }

    cout << size << endl;
    cout << f->val << endl;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  bool insertLast(int v)
  {
    if (size == max_size)
      return false;

    size++;

    Node *node = newNode(v);

    if (f == NULL)
    {
      node->pre = node;
      node->next = node;
      f = node;
      e = node;
    }
    else
    {
      node->next = e->next;
      e->next = node;
      node->pre = e;
      f->pre = node;
      e = node;
    }

    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  bool deleteFront()
  {
    if (size == 0)
      return false;

    size--;

    if (size == 0)
    {
      f = NULL;
      e = NULL;
      return true;
    }

    e->next = f->next;
    f->next->pre = e;
    f = f->next;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  bool deleteLast()
  {
    if (size == 0)
      return false;

    size--;

    if (size == 0)
    {
      f = NULL;
      e = NULL;
      return true;
    }

    e->pre->next = e->next;
    f->pre = e->pre;
    e = e->pre;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront()
  {
    if (size == 0)
      return -1;

    return (f->val);
  }

  /** Get the last item from the deque. */
  int getRear()
  {
    if (size == 0)
      return -1;

    return (e->val);
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty()
  {
    return (size == 0);
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull()
  {
    return (size == max_size);
  }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main(){
  MyCircularDeque *obj = new MyCircularDeque(3);
  bool param_1 = obj->insertFront(34);

  cout << obj->getFront() << endl;

  return 0;
}
