#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool Increasing_Triplet_Subsequence(vector<int> nums){
    int c1=INT_MAX,c2=INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=c1)
            c1=nums[i];
        else if(nums[i]<=c2)
            c2=nums[i];
        else
            return true;
    }
    return false;
}
int main(){
    vector<int> nums={1,2,2,1,1,1};
    cout<<Increasing_Triplet_Subsequence(nums);
}