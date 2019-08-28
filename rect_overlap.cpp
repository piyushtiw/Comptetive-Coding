#include <stdio.h> 
#include <stdlib.h> 
#include<iostream>
#include<vector>

using namespace std;
  
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[2]<=rec2[0] || rec1[0] >= rec2[2])return false;
        if(rec1[1]>=rec2[3] || rec1[3] <= rec2[1])return false;
        return true;
    }
};
  
int main() 
{ 
    vector <int> l1;
    l1.push_back(0);
    l1.push_back(0); 
    l1.push_back(1); 
    l1.push_back(1); 
    vector <int> l2;
    l2.push_back(1);
    l2.push_back(0);
    l2.push_back(2);
    l2.push_back(1);

    Solution obj;
    bool k = obj.isRectangleOverlap(l1, l2); 
    if (k)
        printf("Rectangles Overlap"); 
    else
        printf("Rectangles Don't Overlap"); 
    
    return 0; 
}
