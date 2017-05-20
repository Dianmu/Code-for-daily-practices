#include<iostream>
#include<ctime>
#include<stack>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

//This is the summary of 7 sorts algorithms
void select_sort(int*a,int n){
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
void bubble_sort(int*a,int n){
    for(int i=0;i<n;++i)
        for(int j=0;j<n-1-i;++j)
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
}
void insert_sort(int*a,int n){
    for(int i=1;i<n;++i)
        for(int j=i-1;j>=0&&a[j]>a[j+1];--j)
            swap(a[j],a[j+1]);
}
void shell_sort(int*a,int n){
    for(int gap=n/2;gap>0;gap/=2)
        for(int i=gap;i<n;++i)
            for(int j=i-gap;j>=0&&a[j]>a[j+gap];j-=gap)
                swap(a[j],a[j+gap]);
}
void quick_sort(int*a,int low,int high){
    if(low>=high)return;
    int first=low,last=high,key=a[first];
    while(first<last){
        while(first<last&&a[last]>=key)--last;
        a[first]=a[last];
        while(first<last&&a[first]<=key)++first;
        a[last]=a[first];
    }
    a[first]=key;
    quick_sort(a,low,first-1);
    quick_sort(a,first+1,high);
}
void merge_helper(int*a,int low,int mid,int high,int*p){
    int i=low,m=mid,j=mid+1,n=high;
    int k=0;
    while(i<=m&&j<=n)p[k++]=(a[i]<a[j])?a[i++]:a[j++];
    while(i<=m)p[k++]=a[i++];
    while(j<=n)p[k++]=a[j++];
    for(int i=0;i<k;++i)
        a[low+i]=p[i];
}
void merge_sort(int*a,int low,int high,int*p){
    if(low<high){
        int mid=low+(high-low)/2;
        merge_sort(a,low,mid,p);
        merge_sort(a,mid+1,high,p);
        merge_helper(a,low,mid,high,p);
    }
}
void heap_helper(int*a,int parent,int n){
    int child;
    for(;2*parent+1<n;parent=child){
        child=2*parent+1;
        if(child+1<n&&a[child]<a[child+1])++child;
        if(a[parent]<a[child])swap(a[parent],a[child]);
    }
}
void heap_sort(int*a,int n){
    for(int i=n/2-1;i>=0;--i)
        heap_helper(a,i,n);
    for(int i=n-1;i>0;--i){
        swap(a[i],a[0]);
        heap_helper(a,0,i);
    }
}
void create_sort(int*a,const int &space){
    for(int i=0;i<space;++i)
        a[i]=rand()%(10*space);
}

void print_sort(const int*a,const int &space){
    for(int i=0;i<space;++i)
        cout<<a[i]<<' ';
    cout<<endl;
}

int main()
{
    clock_t start,end;
    start=clock();
    const int space=10;
    int a[space];
    int merge_a[space];
    cout<<"1、Select sort: ";create_sort(a,space);select_sort(a,space);print_sort(a,space);
    cout<<"2、Bubble sort: ";create_sort(a,space);bubble_sort(a,space);print_sort(a,space);
    cout<<"3、Insert sort: ";create_sort(a,space);insert_sort(a,space);print_sort(a,space);
    cout<<"4、Shell sort: ";create_sort(a,space);shell_sort(a,space);print_sort(a,space);
    cout<<"5、Quick sort: ";create_sort(a,space);quick_sort(a,0,space-1);print_sort(a,space);
    cout<<"6、Merge sort: ";create_sort(a,space);merge_sort(a,0,space-1,merge_a);print_sort(a,space);
    cout<<"7、Heap sort: ";create_sort(a,space);heap_sort(a,space);print_sort(a,space);
    end=clock();
    cout<<"Total time: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}