/*
解法：
暴力解法：分别对每一行、每一列和每一个独立的模块进行检索，三种情况进行综合;
一遍遍历：对每一个元素的位置进行归类，行列和模块，在每一类中用数值进行重复性检查;
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool test_row[9][9] = {false};
        bool test_volumn[9][9] = {false};
        bool test_block[9][9] = {false};
        int index(0), index_block(0);

        for (int i(0); i < 9; ++i) {
            for (int j(0); j < 9; ++j) {
                if (board[i][j] != '.') {
                     index = board[i][j] - 49;
                     index_block = i / 3 * 3 + j / 3;
                    if (test_row[i][index] || 
                        test_volumn[j][index] ||
                        test_block[index_block][index]) {
                        return false;
                    } else {
                        test_row[i][index] = true; 
                        test_volumn[j][index] = true;
                        test_block[index_block][index] = true;
                    }
                }
            }
        }
        return true;
    }
};

