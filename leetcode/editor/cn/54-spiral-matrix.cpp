//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。 
//
// 示例 1: 
//
// 输入:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//输出: [1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2: 
//
// 输入:
//[
//  [1, 2, 3, 4],
//  [5, 6, 7, 8],
//  [9,10,11,12]
//]
//输出: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
// Related Topics 数组 
// 👍 500 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-26 22:25:56
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        if(matrix.empty())
            return ans;
        int row,col;
        enum {JADD=0,IADD,JDE,IDE};
        row = matrix.size();
        col = matrix[0].size();
        vector<bool>visited(col*row,false);
        //memset(visited, false,sizeof(row*col));
        int flag = JADD;
        int i=0,j=0;
        int cntInvalid=0;
        START:
        switch (flag) {
            case JADD:
                if(i>=0 and i<row and j>=0 and j<col and !visited[i*col+j]){
                    visited[i*col+j]=true;
                    ans.emplace_back(matrix[i][j]);
                    //cout<<matrix[i][j]<<endl;
                    j++;
                    cntInvalid=0;
                }else{
                    cntInvalid++;
                    j--;
                    i++;
                    flag=(flag+1)%4;
                }
                break;
            case IADD:
                //cout<<"here is IADD"<<endl;
               // cout<<"i is "<<i<<" and j is "<<j<<endl;
                if(i>=0 and i<row and j>=0 and j<col and !visited[i*col+j]){
                    visited[i*col+j]=true;
                    ans.emplace_back(matrix[i][j]);
                    cout<<matrix[i][j]<<endl;
                    i++;
                    cntInvalid=0;
                }else{

                    cntInvalid++;
                    i--;
                    j--;
                    flag=(flag+1)%4;
                }
                break;
            case JDE:
                if(i>=0 and i<row and j>=0 and j<col and !visited[i*col+j]){
                    visited[i*col+j]=true;
                    ans.emplace_back(matrix[i][j]);
                   // cout<<matrix[i][j]<<endl;
                    j--;
                    cntInvalid=0;
                }else{
                    cntInvalid++;
                    j++;
                    i--;
                    flag=(flag+1)%4;
                }
                break;
            case IDE:
                if(i>=0 and i<row and j>=0 and j<col and !visited[i*col+j]){
                    visited[i*col+j]=true;
                    ans.emplace_back(matrix[i][j]);
                   // cout<<matrix[i][j]<<endl;
                    i--;
                    cntInvalid=0;
                }else{
                    cntInvalid++;
                    i++;
                    j++;
                    flag=(flag+1)%4;
                }
                break;

        }

        if(cntInvalid!=4){
            goto START;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}