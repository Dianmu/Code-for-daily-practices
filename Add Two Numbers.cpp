#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

//This is to add two number
int add_two(const int&a,const int&b){
    int sum=a^b;
    int carry=(a&b)<<1;
    while(carry){
        int aa=sum;
        int bb=carry;
        sum=aa^bb;
        carry=(aa&bb)<<1;
    }
    return sum;
}

int main(){
    time_t start=clock();
    srand(time(NULL));
//=====================================================================
    
    const int loop=200;
    for(int i=0;i<loop;++i){
        int a=rand()%1000;
        int b=rand()%783;
        cout<<a<<" + "<<b<<" = "<<add_two(a,b)<<endl;
    }

//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}