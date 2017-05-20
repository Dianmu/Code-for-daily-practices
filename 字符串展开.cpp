#include<iostream>
#include<stack>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

//This is to expand the string with single-number and "()"

string helper(const string &s){
    int n=s.size();
    string ret;
    for(int i=n-1;i>=0;--i){
        if(s[i]>='0'&&s[i]<='9'){
            int dup=s[i]-'0';
            string substr;
            for(int j=0;j<dup;++j)
                substr+=s[i-1];
            --i;
            ret=substr+ret;
        }else{
            ret=s[i]+ret;
        }
    }
    return ret;
}

string exp(const string &s){
    stack<char>stk;
    int n=s.size();
    string ret;
    for(int i=0;i<n;++i){
        if(s[i]!=')')stk.push(s[i]);
        else{
            int dup=1;
            char _next=(i+1<n)?s[i+1]:0;
            if(_next>='0'&&_next<='9')dup=s[++i]-'0';
            string substr;
            while(!stk.empty()&&stk.top()!='('){
                substr=stk.top()+substr;
                stk.pop();
            }
            stk.pop();
            substr=helper(substr);
            string tmp;
            for(int j=0;j<dup;++j)
                tmp=tmp+substr;
            substr=tmp;
            for(int j=0;j<substr.size();++j)
                stk.push(substr[j]);
        }
    }
    while(!stk.empty()){
        ret=stk.top()+ret;
        stk.pop();
    }
    return helper(ret);
}

int main()
{
    string s="((BC3)3ADQ3)PPT5";
    cout<<"Expanding string: "<<exp(s)<<endl;
    return 0;
}