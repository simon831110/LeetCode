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
int global_k;
int res;
void helper(TreeNode* node){
    if(!node)
        return;
    helper(node->left);
    global_k-=1;
    if(global_k==0){
        res=node->val;
        return;
    }
    helper(node->right);
}
int kthSmallest(TreeNode* root, int k) {
    global_k=k;
    helper(root);
    return res;
}

int main(){
    TreeNode *Tree_four=new TreeNode(1);
    TreeNode *Tree_five=new TreeNode(3);
    TreeNode *Tree_six=new TreeNode(5);
    TreeNode *Tree_seven=new TreeNode(7);
    TreeNode *Tree_two=new TreeNode(2,Tree_four,Tree_five);
    TreeNode *Tree_three=new TreeNode(6,Tree_six,Tree_seven);
    TreeNode *Tree_one=new TreeNode(4,Tree_two,Tree_three);

    int ans=kthSmallest(Tree_one,0);
    cout<<ans;
}