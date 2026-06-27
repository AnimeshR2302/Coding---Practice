class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bitset<9>> mCol(9);
        vector<bitset<9>> mBox(9);

        for(int i=0;i<9;i++) {
            bitset<9> mRow(0);

            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') continue;
                int cur = board[i][j] - '1';
                int box = (i / 3) * 3 + (j / 3);

                if (mRow.test(cur)) return false;
                mRow.set(cur);

                if (mCol[j].test(cur)) return false;
                mCol[j].set(cur);

                if (mBox[box].test(cur)) return false;
                mBox[box].set(cur);
            }
        }

        return true;
    }
};