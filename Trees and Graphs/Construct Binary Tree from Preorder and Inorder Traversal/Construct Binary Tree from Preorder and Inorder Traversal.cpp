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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size()==0 || inorder.size()==0)
        return NULL;
    int node=preorder[0];
    TreeNode *root=new TreeNode(node);
    preorder.erase(preorder.begin());
    int inorder_idx;
    for(int i=0;i<inorder.size();i++)
        if(inorder[i]==node)
            inorder_idx=i;
            
    vector<int> left_inorder,right_inorder;
    for(int i=0;i<inorder.size();i++){
        if(i<inorder_idx)
            left_inorder.push_back(inorder[i]);
        else if(i>inorder_idx)
            right_inorder.push_back(inorder[i]);
    }
    root->left=buildTree(preorder,left_inorder);
    root->right=buildTree(preorder,right_inorder);
    return root;
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<TreeNode*> queue={root};
    vector<int> temp;
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
        ans.push_back(temp);
        temp={};
    }
    return ans;
}
int main(){
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    TreeNode *Tree=buildTree(preorder,inorder);
    vector<vector<int>> ans=zigzagLevelOrder(Tree);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<endl;
    }
}