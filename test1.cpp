#include<iostream>
#include<stack>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

//1
void selectsort(int*a,int n){
    for(int i=0;i<n;++i){
        int min=INT_MAX;
        int index=-1;
        for(int j=i;j<n;++j){
            if(a[j]<min){
                min=a[j];
                index=j;
            }
        }
        if(index!=-1)swap(a[i],a[index]);
    }
}
//2
void bubblesort(int*a,int n){
    for(int i=0;i<n;++i)
        for(int j=0;j<n-1-i;++j)
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
}
//3
void insertsort(int*a,int n){
    for(int i=1;i<n;++i)
        for(int j=i-1;j>=0&&a[j]>a[j+1];--j)
            swap(a[j],a[j+1]);
}
//4
void shellsort(int*a,int n){
    for(int gap=n/2;gap>0;gap/=2)
        for(int i=gap;i<n;++i)
            for(int j=i-gap;j>=0&&a[j]>a[j+gap];j-=gap)
                swap(a[j],a[j+gap]);
}
//5
void qsort(int*a,int low,int high){
    if(low>=high)return;
    int first=low,last=high,key=a[first];
    while(first<last){
        while(first<last&&a[last]>=key)--last;
        a[first]=a[last];
        while(first<last&&a[first]<=key)++first;
        a[last]=a[first];
    }
    a[first]=key;
    qsort(a,low,first-1);
    qsort(a,first+1,high);
}
//6
void mhelper(int*a,int low,int mid,int high,int*p){
    int i=low,m=mid,j=mid+1,n=high,k=0;
    while(i<=m&&j<=n){
        p[k++]=(a[i]<a[j])?a[i++]:a[j++];
    }
    while(i<=m)p[k++]=a[i++];
    while(j<=n)p[k++]=a[j++];
    for(int i=0;i<n;++i)
        a[low+i]=p[i];
}
void mergesort(int*a,int low,int high,int*p){
    if(low<high){
        int mid=low+(high-low)/2;
        mergesort(a,low,mid,p);
        mergesort(a,mid+1,high,p);
        mhelper(a,low,mid,high,p);
    }
}
//7
void hhelper(int*a,int parent,int n){
    int child;
    for(;2*parent+1<n;parent=child){
        child=2*parent+1;
        if(child+1<n&&a[child]<a[child+1])++child;
        if(a[parent]<a[child])swap(a[parent],a[child]);
    }
}
void heapsort(int*a,int n){
    for(int i=n/2-1;i>=0;--i)
        hhelper(a,i,n);
    for(int i=n-1;i>0;--i){
        swap(a[i],a[0]);
        hhelper(a,0,i);
    }
}
//8
int LCS(const string &s,const string &t){
    int m=s.size(),n=t.size(),dp[m+1][n+1];
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            dp[i][j]=(i==0||j==0)?0:
            ((s[i-1]==t[j-1])?dp[i-1][j-1]+1:
            max(dp[i-1][j],dp[i][j-1]));
        }
    }
}

int main()
{
    string s="((BC3)3ADQ3)PPT5";
    cout<<"Listing: "<<p(s)<<endl;
    return 0;
}