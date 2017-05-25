#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

//This is to find certain number in a specific designed 2d matrix.
bool exist_number(const vector<vector<int> >&a,const int t){
    int i=a.size()-1,j=0,n=a.size()-1,m=a[0].size()-1;
    while(i>=0&&i<=m&&j>=0&&j<=m){
        if(t>a[i][j])++j;
        else if(t==a[i][j])return true;
        else --i;
    }
    return false;
}

int main(){
    time_t start=clock();
    srand(time(NULL));
//=====================================================================
    
    const int r=7;
    const int c=10;
    const int start_number=rand()%400;
    vector<vector<int> >a(r,vector<int>(10));
    for(int i=0,j=0;j<c;++j){
        int tmp=rand()%400;
        if(count(a[i].begin(),a[i].end(),tmp)==0)a[i][j]=tmp;
        else --j;
    }
    sort(a[0].begin(),a[0].end());
    for(int i=1;i<r;++i){
        int increment=rand()%20+1;
        for(int j=0;j<c;++j){
            a[i][j]=a[i-1][j]+increment;
        }
    }
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<a[i][j]<<'\t';
        }
        cout<<endl;
    }
    int input=0;
    const int end_sign=4000;
    do{
        cout<<"Input : ";
        cin>>input;
        if(input==end_sign){
            cout<<"END SIGN REACHED\n";
            break;
        }
        cout<<"Result : "<<(exist_number(a,input)?"Exist\n":"NOT Exist\n");
    }while(input!=end_sign);

//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}