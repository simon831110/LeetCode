#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    Node *next=root->left;
    Node *cur=root;
    while(cur->left){
        cur->left->next=cur->right;
        if(cur->next){
            cur->right->next=cur->next->left;
            cur=cur->next;
        }
        else{
            cur=next;
            next=cur->left;
        }
    }
    return root;
}

int main(){
    Node *Tree_four=new Node(4);
    Node *Tree_five=new Node(5);
    Node *Tree_six=new Node(6);
    Node *Tree_seven=new Node(7);
    Node *Tree_two=new Node(2,Tree_four,Tree_five,NULL);
    Node *Tree_three=new Node(3,Tree_six,Tree_seven,NULL);
    Node *Tree_one=new Node(1,Tree_two,Tree_three,NULL);

    Node *Tree=connect(Tree_one);
    vector<vector<int>> ans={};
    while(Tree){
        vector<int> temp;
        Node *next=Tree->left;
        while(Tree){
            temp.push_back(Tree->val);
            Tree=Tree->next;
        }
        ans.push_back(temp);
        temp={};
        Tree=next;
    }
    for(int i=0;i<ans.size();i++){
        cout<<"{";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<"}"<<endl;
    }
}