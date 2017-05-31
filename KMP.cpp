#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

//This is KMP

//=====================================================================
void NEXT(const string &t,vector<int>&next){
    next[0]=-1;
    int len=t.size();
    int k=-1,j=0;
    while(j<len-1){
        if(k==-1||t[k]==t[j]){
            ++k;
            ++j;
            if(t[k]==t[j])next[j]=next[k];
            else next[j]=k;
        }else{
            k=next[k];
        }
    }
}
int KMP(const string &s,const string &t){
    int m=s.size(),n=t.size();
    int i=0,j=0;
    vector<int>next(t.size());
    NEXT(t,next);
    while(i<m&&j<n){
        if(j==-1||s[i]==t[j]){
            ++i;
            ++j;
        }else{
            j=next[j];
        }
    }
    if(j==t.size())return i-j;
    else return -1;
}

//=====================================================================

int main(){
    time_t start=clock();
    srand(time(NULL));
//=====================================================================
    string s,t;
    const int m=1000,n=2;
    for(int i=0;i<m;++i){
        s+=rand()%26+'a';
        if(i<n)t+=rand()%26+'a';
    }
    //const string s="BBC ABCDAB ABCDABCDABDE";
    //const string t="ABCDABD";
    fprintf(stderr,"KMP优化算法的匹配结果 : Position(%i)",KMP(s,t));

//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}