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

//This is to try file manipulations

//=====================================================================
void reverse_word(string &str){
    for(int i=0;i<str.size()/2;++i)
        swap(str[i],str[str.size()-1-i]);
    int i=0;
    while(i<str.size()){
        while(i<str.size()&&str[i]==' ')++i;
        int start=i;
        while(i<str.size()&&str[i]!=' ')++i;
        int end=i-1;
        for(;start<end;++start,--end)
            swap(str[start],str[end]);
    }
}
//=====================================================================

int main(){
    time_t start=clock();
    srand(time(NULL));
//=====================================================================
    
    string str;
    cout<<"Input a string to be reversed : ";
    getline(cin,str);
    FILE*fp;
    fp=fopen("test1.txt","w");
    fprintf(fp,"%s\n",str.c_str());
    cout<<str<<endl;
    reverse_word(str);
    cout<<str<<endl;
    fprintf(fp,"%s\n",str.c_str());
    fclose(fp);

//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}