#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//This is transfer sorted array to binary search tree.
class TreeNode{
public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode*helper(vector<int>&vec,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        TreeNode*root=new TreeNode(vec[mid]);
        root->left=helper(vec,low,mid-1);
        root->right=helper(vec,mid+1,high);
        return root;
    }else if(low>high){
        return NULL;
    }else{
        return new TreeNode(vec[low]);
    }
}

TreeNode*convert_to_binary_tree(vector<int>&vec){
    return helper(vec,0,vec.size()-1);
}

void Inorder_traversal(TreeNode*root){
    if(!root)return;
    if(root->left)Inorder_traversal(root->left);
    cout<<root->val<<'\t';
    if(root->right)Inorder_traversal(root->right);
    
}

int main(){
    const int len=10;
    set<int>uni;
    vector<int>arr(len);
    srand(time(NULL));
    for(int i=0;i<len;++i){
        int ele=rand()%100-50;
        if(!uni.count(ele)){
            uni.insert(ele);
            arr[i]=ele;
        }else{
            --i;
        }
    }
    cout<<"Arr print : "<<endl;
    for(int i=0;i<len;++i)cout<<arr[i]<<'\t';
    cout<<endl;
    sort(arr.begin(),arr.end());
//====================================
    TreeNode*root=convert_to_binary_tree(arr);
    cout<<"Inorder traversal : "<<endl;
    Inorder_traversal(root);
    cout<<endl;
//====================================
    cout<<"Sorted Arr print : "<<endl;
    for(int i=0;i<len;++i)cout<<arr[i]<<'\t';
    cout<<endl;
    return 0;
}