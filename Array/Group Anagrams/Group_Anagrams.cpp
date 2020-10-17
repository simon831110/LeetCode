#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string t = s; 
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    vector<vector<string>> anagrams;
    for (auto p : mp) { 
        anagrams.push_back(p.second);
    }
    return anagrams;
}

int main(){
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>v_after= groupAnagrams(strs);
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