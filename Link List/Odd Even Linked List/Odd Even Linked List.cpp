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
ListNode *oddEvenList(ListNode* head) {
    ListNode *odd=new ListNode(0);
    ListNode *even=new ListNode(0);
    ListNode *odd_Head=odd;
    ListNode *even_Head=even;
    int t=1;
    while(head){
        if(t%2==1){
            odd->next=head;
            odd=odd->next;
        }
        else{
            even->next=head;
            even=even->next;
        }
        t+=1;
        head=head->next;
    }
    even->next=NULL;
    odd->next=even_Head->next;
    return odd_Head->next;
}
int main(){
    ListNode *l1=new ListNode(5);
    ListNode *l1_Head=l1;
    for(int i=0;i<5;i++){
        l1->next=new ListNode(i);
        l1=l1->next;
    }
    ListNode *l2=oddEvenList(l1_Head);
    while(l2){
        if(l2->next)
            cout<<l2->val<<"->";
        else
            cout<<l2->val;
        l2=l2->next;
    }
}