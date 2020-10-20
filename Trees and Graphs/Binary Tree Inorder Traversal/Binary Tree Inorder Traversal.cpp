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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    vector<TreeNode*> stack;
    while(true){
        while(root){
            stack.push_back(root);
            root=root->left;
        }
        if(stack.size()==0)
            return ans;
        root=stack.back();
        stack.pop_back();
        ans.push_back(root->val);
        root=root->right;
    }
}

int main(){
    TreeNode *six=new TreeNode(4);
    TreeNode *seven=new TreeNode(5);
    TreeNode *four=new TreeNode(2,six,nullptr);
    TreeNode *five=new TreeNode(3,nullptr,seven);
    TreeNode *two=new TreeNode(1,four,five);
    TreeNode *three=new TreeNode(6);
    TreeNode *one=new TreeNode(222,two,three);
    vector<int> ans=inorderTraversal(one);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
}