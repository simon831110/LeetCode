#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<TreeNode*> queue={root};
    vector<int> temp;
    int flag=1;
    vector<vector<int>> ans={};
    while(queue.size()>0){
        int t=queue.size();
        for(int i=0;i<t;i++){
            TreeNode *node=queue[0];
            queue.erase(queue.begin());
            temp.push_back(node->val);
            if(node->left)
                queue.push_back(node->left);
            if(node->right)
                queue.push_back(node->right);
        }
        if(flag==1)
            ans.push_back(temp);
        else{
            vector<int> temp_reverse;
            for(int i=temp.size()-1;i>=0;i--)
                temp_reverse.push_back(temp[i]);
            ans.push_back(temp_reverse);
        }
        temp={};
        flag*=-1;
    }
    return ans;
}
int main(){
    TreeNode *six=new TreeNode(4);
    TreeNode *seven=new TreeNode(5);
    TreeNode *four=new TreeNode(2,six,nullptr);
    TreeNode *five=new TreeNode(3,nullptr,seven);
    TreeNode *two=new TreeNode(1,four,five);
    TreeNode *three=new TreeNode(6);
    TreeNode *one=new TreeNode(222,two,three);

    vector<vector<int>> ans;
    ans=zigzagLevelOrder(one);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<endl;
    }
}