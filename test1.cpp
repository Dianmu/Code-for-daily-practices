#include <iostream>
#include <ctime>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

//=====================================================================
void print_vec(const vector<int>&vec){
    for(auto ele:vec){
        cout<<ele<<' ';
    }
    cout<<endl;
}

void print_vec(const vector<pair<int,int>>&vec){
    for(auto ele:vec){
        cout<<'('<<ele.first<<','<<ele.second<<')'<<' ';
    }
    cout<<endl;
}

int randomfill(){return rand()%100;}

bool comp(const pair<int,int>&a,const pair<int,int>&b){
    return (a.first>b.first||(a.first==b.first&&a.second<b.second));
}
bool comp1(const int&a,const int&b){
    return a<b;
}

//=====================================================================

int main(){
    time_t start=clock();
    srand(time(NULL));
//=====================================================================
    vector<int>vec(50);
    generate(vec.begin(),vec.end(),randomfill);
    cout<<"Is heap ? "<<(is_heap(vec.begin(),vec.end())?"YES":"NO")<<endl;

    
//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}