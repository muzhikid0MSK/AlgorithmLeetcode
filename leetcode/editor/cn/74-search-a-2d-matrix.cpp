//编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性： 
//
// 
// 每行中的整数从左到右按升序排列。 
// 每行的第一个整数大于前一行的最后一个整数。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 100 
// -104 <= matrix[i][j], target <= 104 
// 
// Related Topics 数组 二分查找 
// 👍 330 👎 0

/**
 *   @Author: muzhikid
 *   @CreatedTime: 2021-03-14 20:10:34
 *   @FinishedTime: 2021年03月14日20:38:04
 *   @Remarks:执行耗时:8 ms,击败了47.81% 的C++用户
			  内存消耗:9.3 MB,击败了74.30% 的C++用户
 */
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //[low,high)
    int searchRow(vector<vector<int> >&matrix,int low,int high,int target){

        if(low>=high)
            return -1;
//        int mid = (low+high)/2; 注释掉为了刷更少内存...
//        int length = matrix[0].size();
        int midRowLastValue = matrix[(low+high)/2][matrix[0].size()-1];
        int midRowFirstValue = matrix[(low+high)/2][0];
        if(target<=midRowLastValue and target>=midRowFirstValue){
            return (low+high)/2;
        }else if(target<midRowFirstValue){
            return searchRow(matrix,low,(low+high)/2,target);
        }else{
            return searchRow(matrix,(low+high)/2+1,high,target);
        }

    }
    //[low,high)
    int searchInRow(vector<vector<int> >&matrix,int rowIndex,int low,int high,int target){
        if(low>=high){
            //INT_32MIN FOR FALSE
            return INT32_MIN;
        }else{
//            vector<int>temp = matrix[rowIndex];
//            int mid = (low+high)/2; 注释掉为了刷更少内存...
            if(matrix[rowIndex][(low+high)/2] == target){
                return target;
            }else if(target<matrix[rowIndex][(low+high)/2]){
                return searchInRow(matrix,rowIndex,low,(low+high)/2,target);
            }else{
                return searchInRow(matrix,rowIndex,(low+high)/2+1,high,target);
            }
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = searchRow(matrix,0,matrix.size(),target);
        if(row==-1){
            return false;
        }else{
            return searchInRow(matrix,row,0,matrix[0].size(),target)==target;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


//input
void input(){
    string path="";
    ifstream f;
    
    if(f.is_open()){
        //TODO
        
    }else{
        cerr<<"File opened fail"<<endl;
    }
    
}
int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}