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
void clockvise_print(const vector<vector<int> >&vec,FILE*fp){
    int m=vec.size(),n=vec[0].size();
    int loop=min(m,n)/2+1;
    for(int i=0;i<loop;++i){
        for(int j=i;j<n-i;++j){
            cout<<vec[i][j]<<"->";
            fprintf(fp,"%i->",vec[i][j]);
        }
        for(int j=i+1;j<m-i;++j){
            cout<<vec[j][n-1-i]<<"->";
            fprintf(fp,"%i->",vec[j][n-1-i]);
        }
        for(int j=n-2-i;j>=i&&m-1-i!=i;--j){
            cout<<vec[m-1-i][j]<<"->";
            fprintf(fp,"%i->",vec[m-1-i][j]);
        }
        for(int j=m-2-i;j>i&&i!=n-1-i;--j){
            cout<<vec[j][i]<<"->";
            fprintf(fp,"%i->",vec[j][i]);
        }
    }
    cout<<"NULL"<<endl;
}


//=====================================================================

int main(){
    time_t start=clock();
    srand(time(NULL));
//=====================================================================
    
    const int r=3;
    const int c=3;
    FILE*fp;
    fp=fopen("test1.txt","w");
    vector<vector<int> >vec(r,vector<int>(c));
    int ele=0;
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j)
            vec[i][j]=ele++;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j)
            cout<<vec[i][j]<<'\t';
        cout<<endl;
    }
    clockvise_print(vec,fp);
    fclose(fp);

//=====================================================================
    time_t end=clock();
    cout<<'\n'<<"【Running time : ";
    cout<<(double)(end-start)*1000/CLOCKS_PER_SEC<<" ms】\n\n";
    return 0;
}