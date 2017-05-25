#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

//This is to merge k sorted lists
//ListNode class
class ListNode{
public:
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(NULL){}
};
//creating a list node
void push_node(ListNode*&head,int val){
    ListNode*tmp=new ListNode(val);
    tmp->next=head;
    head=tmp;
}
//print lists
void print_lists(const vector<ListNode*> &vec){
    for(int i=0;i<vec.size();++i){
        cout<<"List "<<i+1<<" : ";
        ListNode*tmp=vec[i];
        while(tmp){
            cout<<tmp->val<<(tmp->next?"->":" ");
            tmp=tmp->next;
        }
        cout<<endl;
    }
}
//reload, print a list
void print_lists(const ListNode*result){
    while(result){
        cout<<result->val<<(result->next?"->":" ");
        result=result->next;
    }
    cout<<endl;
}
//claim, merge two sorted lists, the result is put in first-parameter
void sort_merge_helper(ListNode*&first,ListNode*second);
//merge k lists
ListNode* merge_lists(vector<ListNode*> &vec){
    cout<<endl<<"【Merging...】"<<endl<<endl;
    if(vec.empty())return NULL;
    while(vec.size()>1){
        sort_merge_helper(vec[0],vec[1]);
        vec.push_back(vec[0]);
        vec.erase(vec.begin());
        vec.erase(vec.begin());
    }
    return vec.back();
}
//implementation, merge two sorted lists, iterative method, which is better than recursive one
void sort_merge_helper(ListNode*&first,ListNode*second){
    ListNode*pre_head=new ListNode(-1);
    ListNode*p=pre_head;
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
    first=pre_head->next;
}
//implementing merge sort, including front-back-splitting and merging
void sort_helper(ListNode*&head){
    if(!head||!head->next)return;
    ListNode*slow=head;
    ListNode*fast=head;
    ListNode*slow_rec=NULL;
    if(fast&&fast->next){
        slow_rec=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    slow_rec->next=NULL;
    sort_helper(head);
    sort_helper(slow);
    sort_merge_helper(head,slow);
}
//pre-function
void sort_lists(vector<ListNode*> &vec){
    cout<<endl<<"【Sorting...】"<<endl<<endl;
    for(int i=0;i<vec.size();++i)
        sort_helper(vec[i]);
}

int main(){
    time_t start=clock();
//=====================================================================
    const int len=20;
    const int space=5;
    vector<ListNode*>vec(space,NULL);
    srand(time(NULL));
    for(int i=0;i<space;++i){
        for(int j=0;j<len;++j){
            push_node(vec[i],rand()%300);
        }
    }
    print_lists(vec);
    sort_lists(vec);
    print_lists(vec);
    ListNode*result=merge_lists(vec);
    print_lists(result);
//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}