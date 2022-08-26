#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    vector<vector<int>> board(9,vector<int>(9,0));//following index from 1
	    board[a][b] = 1;
	    if(a>2&&b>=2&&a<7&&b<=7){
            board[a+2][b-1]=2;
            board[a-2][b+1]=2;
        }
	    else if(a==1 && b==1) board[3][2]=2;
        else if(a==8 && b==8) board[6][7]=2;
        else if(a==1 && b==8) board[3][7]=2;
        else if(a==8 && b==1) board[6][2]=2;
        else if(a==1) {board[a+2][b-1]=2;board[a+2][b+1]=2;}
        else if(a==8) {board[a-2][b-1]=2;board[a-2][b+1]=2;}
        else if(b==1) {board[a-1][b+2]=2;board[a+1][b+2]=2;}
        else if(b==8) {board[a-1][b-2]=2;board[a+1][b-2]=2;}
        else if(a==2){
            if(b+1<=8 && b-2>=1){
                board[a+3][b+1]=2;board[a-1][b-2]=2;
            }
            else{
                board[a+3][b-1]=2;board[a-1][b+2]=2;
            }
        }
        else if(a==7){
            if(b+2<=8 && b-1>=1) {
                board[a-3][b-1]=2;board[a+1][b+2]=2;
            }
            else{
                board[a-3][b+1]=2;
                board[a+1][b-2]=2;
            }
        }
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
	}
	return 0;
}