#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *pp=new ListNode(0),*p=pp;
    int c=0;
    while(l1 || l2 || c){
        int l1_temp=l1?l1->val:0;
        int l2_temp=l2?l2->val:0;
        p->next=new ListNode((l1_temp+l2_temp+c)%10);
        c=(l1_temp+l2_temp+c)/10;
        p=p->next;
        l1=l1?l1->next:l1;
        l2=l2?l2->next:l2;
    }
    return pp->next;
}

int main(){
    ListNode *l1=new ListNode(5);
    ListNode *l1_tail=l1;
    for(int i=4;i>0;i--){
        l1_tail->next=new ListNode(i);
        l1_tail=l1_tail->next;
    }
    ListNode *l2=new ListNode(5);
    ListNode *l2_tail=l2;
    for(int i=4;i>0;i--){
        l2_tail->next=new ListNode(i);
        l2_tail=l2_tail->next;
    }
    ListNode *l3=addTwoNumbers(l1,l2);
    while(l3){
        if(l3->next)
            cout<<l3->val<<"->";
        else
            cout<<l3->val;
        l3=l3->next;
    }
}