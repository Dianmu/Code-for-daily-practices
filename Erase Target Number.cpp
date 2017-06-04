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

//=====================================================================
void print_vec(const vector<int>&vec){
    for(auto ele:vec){
        cout<<ele<<'\t';
    }
    cout<<endl;
}

int randomfill(){return rand()%5;}

void process_vec(vector<int>&vec){
    vector<int>::iterator it=find(vec.begin(),vec.end(),4);
    while(it!=vec.end()){
        vec.erase(it);
        it=find(vec.begin(),vec.end(),4);
    }
}

//=====================================================================

int main(){
    time_t start=clock();
    srand(time(NULL));
//=====================================================================
    vector<int>vec(10);
    generate(vec.begin(),vec.end(),randomfill);
    print_vec(vec);
    process_vec(vec);
    cout<<endl;
    print_vec(vec);

//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}