#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

//This is Longest Increasing subsequence length.
int LIS(const vector<int> &vec,vector<int> &res){
    for(int i=0;i<vec.size();++i){
        vector<int>::iterator it=lower_bound(res.begin(),res.end(),vec[i]);
        if(it==res.end())res.push_back(vec[i]);
        else *it=vec[i];
    }
    return res.size();
}

int main(){
    const int space=10000;
    vector<int>arr;
    vector<int>lis;
    srand(time(NULL));
    for(int i=0;i<space;++i)
        arr.push_back(rand()%20001-10000);
    cout<<"Longest Increasing Subsequence Length is : ";
    cout<<LIS(arr,lis)<<endl;
    cout<<"One of the LIS sequence is : ";
    for(int i=0;i<lis.size();++i)
        cout<<lis[i]<<' ';
    cout<<endl;
    return 0;
}