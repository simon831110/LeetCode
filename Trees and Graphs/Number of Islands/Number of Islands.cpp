#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
using namespace std;

int len_r,len_c;

void helper(vector<vector<char>>& grid,int i,int j){
    if(i>=0 && i<len_r && j>=0 && j<len_c && grid[i][j]=='1'){
        grid[i][j]='0';
        helper(grid,i+1,j);
        helper(grid,i-1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int sum=0;
    len_r=grid.size();
    len_c=grid[0].size();
    for(int i=0;i<len_r;i++){
        for(int j=0;j<len_c;j++){
            if(grid[i][j]=='1'){
                sum+=1;
                helper(grid,i,j);
            }
        }
    }
    return sum;
}

int main(){
    vector<vector<char>> grid
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout<<numIslands(grid);
    
}