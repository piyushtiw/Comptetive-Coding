#include <iostream>
#include <stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
private:
  int quick_fun(vector<int> &nums, int s, int e, int k)
  {
    int j = nums[e];
    int t = s - 1;

    for (int i = s; i < e; i++)
    {
      if (nums[i] > j)
      {
        t++;
        swap(nums[i], nums[t]);
      }
    }
    t++;

    swap(nums[t], nums[e]);

    if (t == k)
      return nums[t];
    else if (t > k)
    {
      return quick_fun(nums, s, t - 1, k);
    }
    else
    {
      return quick_fun(nums, t + 1, e, k);
    }
  }

public:
  int findKthLargest(vector<int> &nums, int k)
  {
    priority_queue<int, vector<int>, greater<int>> q;

    for (auto i : nums)
    {
      q.push(i);
      if (q.size() > k)
        q.pop();
    }

    return q.top();
  }
};

class KthLargest
{
public:
  KthLargest(int k, vector<int> &nums)
  {
    m = k;

    for (int i = 0; i < min(m,nums.size()); i++)
    {
      arr.push_back(nums[i]);
    }

    heapify();
    
    if(nums.size() > m){
        for(int i = m; i<nums.size(); i++){
          insert_into_heap(nums[i]);
        }
    }
  }

  int add(int val)
  {
    insert_into_heap(val);
    return (arr[0]);
  }

private:
  int m;
  vector<int> arr;

  void insert_into_heap(int val){
    if (arr.size() < m)
      arr.insert(arr.begin(), val);
    else if (arr[0] < val)
      arr[0] = val;

    MinHeapify(0);
  }

  int min(int a, int b){
    if(a>b)return b;
    return a;
  }
  
  void heapify()
  {
    int i = (arr.size() - 1)/2; 
    while (i >= 0) 
    { 
        MinHeapify(i); 
        i--; 
    }
  }

  int left(int i){
    return (2*i + 1);
  }

  int right(int i){
    return (2 * i + 2);
  }

  void swap(int *a, int *b){
    int k = *b;
    *b = *a;
    *a = k;
  }

  void MinHeapify(int i)
  {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < min(m, arr.size()) && arr[l] < arr[i])
      smallest = l;
    if (r < min(m, arr.size()) && arr[r] < arr[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(&arr[i], &arr[smallest]);
      MinHeapify(smallest);
    }
  }
};

int main()
{
  int k = 2;
  vector< int > nums;

  nums.push_back(0);

  KthLargest *obj = new KthLargest(k, nums);
  int param_1 = obj->add(-1);
  cout << param_1 << endl;
  return 0;
}
