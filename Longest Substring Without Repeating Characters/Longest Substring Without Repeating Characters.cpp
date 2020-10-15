#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int left=0,right=0,longest=0;
    while(left<s.size() && right<s.size()){
        if(set.find(s[right])==set.end()){      //集合中沒有字元
            set.insert(s[right++]);
            longest=max(longest,right-left);
        }
        else{
            set.erase(s[left]);
            left++;
        }
    }
    return longest;
}
int main(){
    cout<<lengthOfLongestSubstring(" ");
}