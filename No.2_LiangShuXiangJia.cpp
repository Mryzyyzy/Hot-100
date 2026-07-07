#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode*next):val(x), next(next){}
};

ListNode * addSum(ListNode * l1, ListNode *l2){
    ListNode * head = nullptr, *tail;
    int carry = 0;
    while(l1 || l2){
        int n1 = l1? l1->val: 0;
        int n2 = l2? l2->val: 0;
        int sum = n1 + n2 + carry;
        if(!head){
            head = tail = new ListNode(sum%10);
        }else{
            tail->next = new ListNode(sum%10);
            tail = tail->next;
        }
        carry = sum/10;
        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }
    }
    if(carry){
        tail->next = new ListNode(carry);
    }
    return head;
}

int main(){
    ListNode* l1 = nullptr, *l2 = nullptr, *l3;
    for(int i = 0; i < 5; i++){
        if(!l1){
            l1 = l3 = new ListNode(9);
        }else{
            l3->next = new ListNode(9);
            l3 = l3->next;
        }
    }
    for(int i = 0; i < 8; i++){
        if(!l2){
            l2 = l3 = new ListNode(9);
        }else{
            l3->next = new ListNode(9);
            l3 = l3->next;
        }
    }
    l3 = addSum(l1, l2);
    while (l3)
    {
        cout << l3->val;
        l3 = l3->next;
    }
    

}