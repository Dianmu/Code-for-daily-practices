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
void sign_print(const char &ch, FILE*fp,int line){
    switch(ch){
        case '+':
            if(0==line)fprintf(fp,"   *   ");
            if(1==line)fprintf(fp,"   *   ");
            if(2==line)fprintf(fp," ***** ");
            if(3==line)fprintf(fp,"   *   ");
            if(4==line)fprintf(fp,"   *   ");
            break;
        case '-':
            if(0==line)fprintf(fp,"       ");
            if(1==line)fprintf(fp,"       ");
            if(2==line)fprintf(fp," ***** ");
            if(3==line)fprintf(fp,"       ");
            if(4==line)fprintf(fp,"       ");
            break;
        case '*':
            if(0==line)fprintf(fp," *   * ");
            if(1==line)fprintf(fp,"  * *  ");
            if(2==line)fprintf(fp,"   *   ");
            if(3==line)fprintf(fp,"  * *  ");
            if(4==line)fprintf(fp," *   * ");
            break;
        case '/':
            if(0==line)fprintf(fp,"     * ");
            if(1==line)fprintf(fp,"    *  ");
            if(2==line)fprintf(fp,"   *   ");
            if(3==line)fprintf(fp,"  *    ");
            if(4==line)fprintf(fp," *     ");
            break;
        case '0':
            if(0==line)fprintf(fp," ***** ");
            if(1==line)fprintf(fp," *   * ");
            if(2==line)fprintf(fp," *   * ");
            if(3==line)fprintf(fp," *   * ");
            if(4==line)fprintf(fp," ***** ");
            break;
        case '1':
            if(0==line)fprintf(fp,"   *   ");
            if(1==line)fprintf(fp," * *   ");
            if(2==line)fprintf(fp,"   *   ");
            if(3==line)fprintf(fp,"   *   ");
            if(4==line)fprintf(fp," ***** ");
            break;
        case '2':
            if(0==line)fprintf(fp," ***** ");
            if(1==line)fprintf(fp,"     * ");
            if(2==line)fprintf(fp," ***** ");
            if(3==line)fprintf(fp," *     ");
            if(4==line)fprintf(fp," ***** ");
            break;
        case '3':
            if(0==line)fprintf(fp," ***** ");
            if(1==line)fprintf(fp,"     * ");
            if(2==line)fprintf(fp," ***** ");
            if(3==line)fprintf(fp,"     * ");
            if(4==line)fprintf(fp," ***** ");
            break;
        case '4':
            if(0==line)fprintf(fp,"   *   ");
            if(1==line)fprintf(fp,"  **   ");
            if(2==line)fprintf(fp," ***** ");
            if(3==line)fprintf(fp,"   *   ");
            if(4==line)fprintf(fp,"   *   ");
            break;
        case '5':
            if(0==line)fprintf(fp," ***** ");
            if(1==line)fprintf(fp," *     ");
            if(2==line)fprintf(fp," ***** ");
            if(3==line)fprintf(fp,"     * ");
            if(4==line)fprintf(fp," ***** ");
            break;
        case '6':
            if(0==line)fprintf(fp," ***** ");
            if(1==line)fprintf(fp," *     ");
            if(2==line)fprintf(fp," ***** ");
            if(3==line)fprintf(fp," *   * ");
            if(4==line)fprintf(fp," ***** ");
            break;
        case '7':
            if(0==line)fprintf(fp," ***** ");
            if(1==line)fprintf(fp,"    *  ");
            if(2==line)fprintf(fp,"   *   ");
            if(3==line)fprintf(fp,"  *    ");
            if(4==line)fprintf(fp," *     ");
            break;
        case '8':
            if(0==line)fprintf(fp," ***** ");
            if(1==line)fprintf(fp," *   * ");
            if(2==line)fprintf(fp," ***** ");
            if(3==line)fprintf(fp," *   * ");
            if(4==line)fprintf(fp," ***** ");
            break;
        case '9':
            if(0==line)fprintf(fp," ***** ");
            if(1==line)fprintf(fp," *   * ");
            if(2==line)fprintf(fp," ***** ");
            if(3==line)fprintf(fp,"     * ");
            if(4==line)fprintf(fp," ***** ");
            break;
        case '=':
            if(0==line)fprintf(fp,"       ");
            if(1==line)fprintf(fp," ***** ");
            if(2==line)fprintf(fp,"       ");
            if(3==line)fprintf(fp," ***** ");
            if(4==line)fprintf(fp,"       ");
            break;
    }
}
//=====================================================================

int main(){
    time_t start=clock();
    srand(time(NULL));
//=====================================================================
    
    int first,second,result;
    char op;
    cout<<"Input first number : ";
    cin>>first;
    cout<<"Input Operator : ";
    cin>>op;
    cout<<"Input second number : ";
    cin>>second;
    string str=to_string(first)+op+to_string(second)+"=";
    if(op=='+')result=first+second;
    else if(op=='-')result=first-second;
    else if(op=='*')result=first*second;
    else if(op=='-')result=first/(second?second:1);
    str+=to_string(result);
    FILE*fp;
    fp=fopen("test1.txt","wb");
    for(int i=0;i<5;++i){
        if(i!=0)fprintf(fp,"\n");
        for(int j=0;j<str.size();++j){
            sign_print(str[j],fp,i);
        }
    }   
    fclose(fp);
//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}