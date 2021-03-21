//判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
// 
//
// 
//
// 上图是一个部分填充的有效的数独。 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 示例 1: 
//
// 输入:
//[
//  ["5","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//[
//  ["8","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: false
//解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
//     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。 
//
// 说明: 
//
// 
// 一个有效的数独（部分已被填充）不一定是可解的。 
// 只需要根据以上规则，验证已经填入的数字是否有效即可。 
// 给定数独序列只包含数字 1-9 和字符 '.' 。 
// 给定数独永远是 9x9 形式的。 
// 
// Related Topics 哈希表 
// 👍 406 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-29 16:49:22
*/

#include <vector>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //unordered_map<>
    bool rows[9][9];            //第i行的第j个数字是否出现
    bool cols[9][9];
    void init(){
        for(int i =0;i<9;i++){
            for(int j = 0 ;j<9;j++){
                rows[i][j]=false;
                cols[i][j]=false;
            }
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        //按九宫格遍历

        int rowBegin = 0;
        int colBegin = -3;
        for(int cnt=0;cnt<9;cnt++){

            if(colBegin + 3 < 9){
                colBegin+=3;
            }else{
                rowBegin+=3;
                colBegin = 0;
            }
            bool isAppeared[9];  //记录该九宫格出现的数字
           memset(isAppeared, false,sizeof(isAppeared));

            for(int row = rowBegin;row<rowBegin+3;row++){
                for(int col = colBegin;col<colBegin+3;col++){
                    char curNum = board[row][col];
                    if(isdigit(curNum)){
                        if(isAppeared[curNum-'0'-1]||rows[row][curNum-'0'-1]||cols[col][curNum-'0'-1]){
                            return false;
                        }else{
                            isAppeared[curNum-'0'-1]=true;
                            rows[row][curNum-'0'-1]=true;
                            cols[col][curNum-'0'-1]=true;
                        }
                    }

                }
            }

        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}