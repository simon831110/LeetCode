#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
using namespace std;

string helper(string str,int left,int right){
    while(left>=0 && right<str.size() && str[right]==str[left]){
        left-=1;
        right+=1;
    }
    return str.substr(left+1,right-left-1);
}
string longestPalindrome(string str){
    string longest="",odd="",even="";
    for(int i=0;i<str.size();i++){
        odd=helper(str,i,i);
        if(odd.size()>longest.size())
            longest=odd;
        even=helper(str,i,i+1);
        if(even.size()>longest.size())
            longest=even;
    }
    return longest;
}


int main(){
    string a="babad";
    cout<<longestPalindrome(a);
}