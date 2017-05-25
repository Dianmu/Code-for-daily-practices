#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

//This is to add two numbers represented by list
/*
 *example:   1->2->3   +  1->8->6    =>   2->0->0->1   ;
 */
class ListNode{
public:
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){}
};

void push_node(ListNode*&head,int val){
    ListNode*tmp=new ListNode(val);
    tmp->next=head;
    head=tmp;
}

ListNode*AddTwoNumbers(const ListNode *l1,const ListNode *l2){
    ListNode*pre_head=new ListNode(0);
    ListNode*p=pre_head;
    int carry=0;
    while(l1||l2||carry){
        int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
        carry=sum/10;
        p->next=new ListNode(sum%10);
        p=p->next;
        l1=l1?l1->next:l1;
        l2=l2?l2->next:l2;
    }
    return pre_head->next;
}

void print_list(const ListNode*l){
    while(l){
        cout<<l->val;
        l=l->next;
    }
}

int main(){
    const int len=7;
    ListNode*head1=NULL;
    ListNode*head2=NULL;
    srand(time(NULL));
    for(int i=0;i<len;++i){
        push_node(head1,rand()%10);
        push_node(head2,rand()%10);
        if(len==99)push_node(head2,rand()%10);
    }
    ListNode*result=AddTwoNumbers(head1,head2);
    print_list(head1);cout<<"+";print_list(head2);cout<<"=";print_list(result);
    cout<<endl;
    return 0;
}