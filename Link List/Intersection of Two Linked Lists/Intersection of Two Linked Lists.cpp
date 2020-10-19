#include <vector>
#include <string>
#include <stdarg.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode *pa=headA;
    ListNode *pb=headB;
    while(pa->val!=pb->val){
        if(pa->next!=NULL)
            pa=pa->next;
        else
            pa=headB;
        if(pb->next!=NULL)
            pb=pb->next;
        else
            pb=headA;
    }
    return pa;
}
int main(){
    ListNode *headA=new ListNode(5);
    ListNode *pa=headA;
    for(int i=0;i<10;i++){
        pa->next=new ListNode(i);
        pa=pa->next;
    }

    ListNode *headB=new ListNode(0);
    ListNode *pb=headB;
    for(int i=7;i<10;i++){
        pb->next=new ListNode(i);
        pb=pb->next;
    }
    ListNode *headC=getIntersectionNode(headA,headB);
    cout<<headC->val;
}