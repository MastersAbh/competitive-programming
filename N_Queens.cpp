/**
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
**/

class Solution {
public:
    vector<int>queens;
    vector<string> numsToVString(int size){
        vector<string>res(size,"");
        for(int i = 0;i<size;i++){
            res[i].resize(size,'.');
        }
        for(int i = 0;i<size;i++){
            res[i][queens[i]]='Q';
        }
        return res;
    }
    bool safeAt(int row){
        for(int i = 0;i<row;i++){
            int diff = abs(queens[i]-queens[row]);
            if (diff == 0 || diff == row-i)
                return false;
        }
        return true;
    }
    
    void help(int row, int size, vector<vector<string>>&sol){
        if(row == size){
            sol.push_back(numsToVString(size));
            return;
        }
        for(int i = 0;i<size;i++){
            queens[row]=i;
            if(safeAt(row)){
                help(row+1,size,sol);
            }
            queens.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        queens.resize(n,0);
        vector<vector<string>>sol;
        help(0,n,sol);
        return sol;
    }
};