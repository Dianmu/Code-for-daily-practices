#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

//This is the Longest Consecutive Subsequence length
int LCS(const vector<int> &arr,unordered_map<int,int> &mymap){
    int tmp_max=INT_MIN;
    for(int i=0;i<arr.size();++i){
        if(mymap[arr[i]])continue;
        else{
            tmp_max=max(tmp_max,mymap[arr[i]]=
                                mymap[arr[i]+mymap[arr[i]+1]]=
                                mymap[arr[i]-mymap[arr[i]-1]]=
                                mymap[arr[i]-1]+mymap[arr[i]+1]+1);
        }
    }
    return tmp_max;
}

int main(){
    const int len=1000;
    vector<int>arr(len,0);
    unordered_map<int,int>mymap;
    srand(time(NULL));
    for(int i=0;i<len;++i){
        arr[i]=rand()%400;
    }
    cout<<"The Longest Consecutive Subsequence Length is : "<<LCS(arr,mymap)<<endl;
    return 0;
}