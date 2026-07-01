#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool safe(vector<vector<char>>& b, int r, int c, int x){
        for(int i=0;i<9;++i){
            if(b[r][i] == (char)(x+'0')) return false; // horizaontal
            if(b[i][c] == (char)(x+'0')) return false; // vertical
        }
        int nr = (r/3)*3;
        int nc = (c/3)*3;

        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                if(b[nr+i][nc+j] == (char)(x+'0')) return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& b, int r, int c){
        if(c == 9){
            r = r+1;
            c = 0;
        }
        if(r == 9) return true;
        if(b[r][c] != '.'){
            if(solve(b, r, c+1)) return true;
        }else{
            for(int i=1;i<=9;++i){
                if(safe(b, r, c, i)){
                    b[r][c] = (char)(i+'0');
                    if(solve(b, r, c+1)){
                        return true;
                    }else{
                        b[r][c] = '.';
                    }
                }
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};