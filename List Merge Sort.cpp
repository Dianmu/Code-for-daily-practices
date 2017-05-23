#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//this is to sort list using mergesort method
class ListNode{
public:
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){}
};

void push_ele(ListNode**head,int x){
    ListNode*newnode=new ListNode(x);
    newnode->next=*head;
    *head=newnode;
}

void traversal_list(ListNode*head){
    cout<<"Now the list is : "<<endl;
    ListNode*p=head;
    while(p){
        cout<<p->val<<' ';
        p=p->next;
    }
    cout<<endl;
}

ListNode*mergeSort(ListNode*first,ListNode*second){
    ListNode*pre_head=new ListNode(0),*p=pre_head;
    while(first&&second){
        if(first->val<second->val){
            p->next=first;
            first=first->next;
        }else{
            p->next=second;
            second=second->next;
        }
        p=p->next;
    }
    if(first)p->next=first;
    if(second)p->next=second;
    return pre_head->next;
}

ListNode*sortList(ListNode*head){
    if(!head||!head->next)return head;
    ListNode*slow_rec=NULL,*slow=head,*fast=head;
    while(fast&&fast->next){
        slow_rec=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    slow_rec->next=NULL;
    ListNode*first=sortList(head);
    ListNode*second=sortList(slow);
    return mergeSort(first,second);
}

int main(){
    ListNode*head=new ListNode(-1);
    srand(time(NULL));
    for(int i=0;i<300;++i){
        push_ele(&head,rand()%1000);
    }
    traversal_list(head);
    head=sortList(head);
    cout<<"After Merge Sort"<<endl;
    traversal_list(head);
    return 0;
}