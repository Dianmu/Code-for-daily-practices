#include<iostream>
#include<ctime>
#include<stack>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

//This is the Longest Common Subsequences number
int LCS(const string &s,const string &t){
    int m=s.size();
    int n=t.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;++i){
        for(int j=0;j<=n;++j){
            dp[i][j]=(i==0||j==0)?0:
            (s[i-1]==t[j-1])?dp[i-1][j-1]+1:
            max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    clock_t start,end;
    start=clock();
    const string s="niafbwefudgyaujaueigdajdbkwah78176213gdjasbdkadhbdajkdbajkdbjwabdjbwadlwlixiangyuhdulh33uiye231li298371hxiangdauidhqwyjdbqwuhjbsajhbdajshbdhasjbdwjhd";
    const string t="jgug1g27y37183jabdashgiqnadhwudgkawldgweugwaejdsdjkahdwuhwduagbambwkbdajblidwxhaiangdbkayjwbduasbdmlixianwnbdgyhajuvsagcwandvabhajwdwa";
    cout<<"The Longest Common Subsequences number is : "<<LCS(s,t)<<endl;
    end=clock();
    cout<<"Total time: "<<(double)(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}