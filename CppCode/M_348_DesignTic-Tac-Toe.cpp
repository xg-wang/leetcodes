#include "lc_header.h"
using namespace std;

class TicTacToe {
public:
    vector<int> p1, p2;
    int n;

    /** Initialize your data structure here. */
    TicTacToe(int n) {
        p1.resize(2*n + 2);
        p2.resize(2*n + 2);
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1) {
            return update(row, col, p1) ? 1 : 0;
        }
        if (player == 2) {
            return update(row, col, p2) ? 2 : 0;
        }
        return 0;
    }
    bool update(int row, int col, vector<int>& p) {
        if (++p[row]>=n) return true;
        if (++p[n+col]>=n) return true;
        if (row==col && ++p[2*n]>=n) return true;
        if (row==n-col-1 && ++p[2*n+1]>=n) return true;
        return false;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */