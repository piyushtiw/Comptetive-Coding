#include<iostream>
#include<cstdio>

using namespace std;

float binary_search(int n){
  int start = 0;
  int end = n;
  int mid;
  float ans;

  while(start < end){
    mid = (end + start)/2;

    int mid_square = mid * mid;

    if(mid_square == n){
      ans = mid;
      break;
    }

    if (mid_square > n){
      end = mid - 1;
    }
    else if (mid_square < n){
      start = mid + 1;
      ans = mid;
    }
  }

  float increment = 0.1;
  int precision = 2;
  for (int i = 0; i < precision; i++)
  {
    while (ans * ans <= n)
    {
      ans += increment;
    }

    ans = ans - increment;
    increment = increment / 10;
  }

  return ans;
}

int pow (int x, int n)
{
  double ans = 1.0;
  if (n < 0)
  {
      x = 1 / x;
      n = abs(n);
  }
  while (n)
  {
      if (n %2 == 1){
        ans *= x;
        cout << ans << endl;
      }
      x *= x;
      n /= 2;
  }
  return ans;                                                   
}

int main(){
  cout << pow(12, 6) << endl;
  return 0;
}
