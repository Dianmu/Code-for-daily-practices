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

//This is the maximum sum of continuous vectors
int MaximumContinuesS(const vector<int> &a){
    int n=a.size();
    if(!n)return 0;
    int ret_max=INT_MIN;
    int tmp=a[0];
    for(int i=1;i<n;++i){
        //if tmp<0, then discard tmp, and refresh tmp with a[i]
        tmp=max(a[i],tmp+a[i]);
        //for each tmp-change, record the maximum appeared in the process
        ret_max=max(ret_max,tmp);
    }
    return ret_max;
}


int main()
{
    clock_t start,end;
    start=clock();
//=========================================
    const int space=500;
    vector<int>vec(space);
    srand(time(NULL));//only set once in main() to change seed.
    for(int i=0;i<space;++i){
        vec[i]=rand()%2001-1000;
        cout<<vec[i]<<' ';
    }
    cout<<endl;
    cout<<"连续子序列的最大和为： "<<MaximumContinuesS(vec)<<endl;
//=========================================
    end=clock();
    cout<<"Total time: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}