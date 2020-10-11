#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    int nums_rows=matrix.size();
    int nums_cols=matrix[0].size();
    bool FirstRowZeros=false;
    for(int col=0;col<nums_cols;col++)
        if(matrix[0][col]==0)
            FirstRowZeros=true;
    for(int row=0;row<nums_rows;row++){
        for(int col=0;col<nums_cols;col++){
            if(matrix[row][col]==0){
                matrix[0][col]=0;
                matrix[row][0]=0;
            }
        }
    }
    for(int row=nums_rows-1;row>=1;row--){
        for(int col=nums_cols-1;col>=0;col--){
            if(matrix[0][col]==0 || matrix[row][0]==0){
                matrix[row][col]=0;
            }
        }
    }
    if(FirstRowZeros)
        for(int i=0;i<nums_cols;i++)
            matrix[0][i]=0;
    for(int i=0;i<matrix.size();i++){
        cout<<"{";
        for(int j=0;j<matrix[i].size();j++){
            if(j<matrix[i].size()-1)
                cout <<matrix[i][j]<<",";
            else
                cout <<matrix[i][j];
        }
        cout<<"}";
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
}