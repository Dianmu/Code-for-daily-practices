#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

//This is Word Search from leetcode
bool isFound(vector<vector<char> >&board,const char*w,int x,int y){
    int m=board.size();
    int n=board[0].size();
    if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
        return false;//end condition1
    if(*(w+1)=='\0')return true;//end condition2
    char tmp=board[x][y];
    board[x][y]='\0';
    if(isFound(board,w+1,x+1,y)||
        isFound(board,w+1,x-1,y)||
        isFound(board,w+1,x,y+1)||
        isFound(board,w+1,x,y-1)){
        board[x][y]=tmp;//do not change board
        return true;
    }
    board[x][y]=tmp;//do not change board
    return false;
}

bool exist(vector<vector<char> >&board,string word){
    int m=board.size();
    int n=board[0].size();
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            if(isFound(board,word.c_str(),i,j))return true;
    return false;
}

void print_board(const vector<vector<char> > &board){
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board[i].size();++j)
            cout<<board[i][j]<<' ';
        cout<<endl;
    }
}

int main(){
    const int m=9;
    const int n=10;
    vector<vector<char> >board(m,vector<char>(n));
    //srand(time(NULL));
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            board[i][j]=rand()%26+'A';
    print_board(board);
    const string str[3]={"XYQVMQFRCPLRTYDRWDLPSFVK",
                    "AUTOCAD",
                    "TCPIPPROTOCAL"};
    for(int i=0;i<3;++i){
        cout<<str[i]<<" : "<<(exist(board,str[i])?"TRUE":"FALSE")<<endl;
        print_board(board);
    }
    return 0;
}