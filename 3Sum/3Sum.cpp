#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i]==nums[i-1])
            continue;
        int target=-nums[i];
        int s=i+1,e=nums.size()-1;
        while(s<e){
            if(nums[s]+nums[e]==target){
                vector<int> v(3);
                v[0]=nums[i],v[1]=nums[s],v[2]=nums[e];
                result.push_back(v);
                s+=1;
                while(s<e && nums[s]==nums[s-1])
                    s+=1;
            }
            else if(nums[s]+nums[e]<target)
                s+=1;
            else
                e-=1;
        }
    }
    return result;
}
int main(){
    vector<int> v(6);
    int v_org[]={0,0,0,0,0,0};
    for(int i=0;i<6;i++){
        v[i]=v_org[i];
    }
    vector<vector<int>> v_after=threeSum(v);
    for(int i=0;i<v_after.size();i++){
        cout<<"{";
        for(int j=0;j<v_after[i].size();j++){
            if(j<v_after[i].size()-1)
                cout <<v_after[i][j]<<",";
            else
                cout <<v_after[i][j];
        }
        cout<<"}";
        cout<<endl;
    }
}