#include<iostream>
#include<ctime>
#include<stack>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

//This is the practice of permutation
void Permutations(string s,int start,int end){
    if(start==end){
        for(auto ele:s)cout<<ele<<' ';
        cout<<endl;
    }
    for(int i=start;i<=end;++i){
        swap(s[i],s[start]);
        Permutations(s,start+1,end);
        swap(s[i],s[start]);
    }
}

int main()
{
    clock_t start,end;
    start=clock();
    const string s="abcd";
    cout<<"The Permutations : ";
    Permutations(s,0,s.size()-1);
    end=clock();
    cout<<"Total time: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}