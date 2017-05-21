#include<iostream>
#include<ctime>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

//This is to delete a node in a list
class ListNode{
public:
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* create_list(int n){
    ListNode*head=NULL;
    for(int i=0;i<n;++i){
        ListNode*tmp=new ListNode(rand()%100);
        tmp->next=head;
        head=tmp;
    }
    return head;
}

void delete_list_node(ListNode*node){
    if(node->next){
        ListNode*tmp=node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete tmp;
    }else{
        assert(node->next);
    }
}

ListNode*steps(ListNode*head,int step){
    ListNode*tmp=head;
    for(int i=0;i<step;++i)
        tmp=tmp->next;
    return tmp;
}

void print_list(ListNode*head){
    ListNode*tmp=head;
    while(tmp){
        cout<<tmp->val;
        if(tmp->next)cout<<"->";
        tmp=tmp->next;
    }
    cout<<endl;
}

int main()
{
    clock_t start,end;
    start=clock();
//=========================================
    ListNode*head=create_list(30);
    cout<<"Before Delete: ";
    print_list(head);
    ListNode*to_be_deleted=steps(head,28);
    delete_list_node(to_be_deleted);
    cout<<"After Delete : ";
    print_list(head);
//=========================================
    end=clock();
    cout<<"Total time: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}