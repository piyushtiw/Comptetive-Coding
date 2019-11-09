#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int substring(string s, int K)
{
  int left = 0, right = 0;
  map <char, int> numCount;
  int distinct = 0;
  int result = 0;
  int prefix = 0;
  string A = s;
  while (right < A.length())
  {
    if (numCount[A[right]])
      numCount[A[right]]++;
    else
    {
      distinct++;
      numCount[A[right]] = 1;
    }

    if (distinct > K)
    {
      numCount[A[left]]--;
      prefix = 0;
      distinct--;
      left++;
    }
    while (numCount[A[left]] > 1)
    {
      numCount[A[left]]--;
      left++;
      prefix++;
    }
    if (distinct == K)
      result += 1 + prefix;

    right++;
  }
  return result;
}

int main()
{
  string s = "pqpqs";
  int k = 2;

  cout << substring("aabab", 3);
  return 0;
}
