//给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。 
//
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。 
//
// 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,0,2,1,1,0]
//输出：[0,0,1,1,2,2]
// 
//
// 示例 2： 
//
// 
//输入：nums = [2,0,1]
//输出：[0,1,2]
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：[0]
// 
//
// 示例 4： 
//
// 
//输入：nums = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// n == nums.length 
// 1 <= n <= 300 
// nums[i] 为 0、1 或 2 
// 
//
// 
//
// 进阶： 
//
// 
// 你可以不使用代码库中的排序函数来解决这道题吗？ 
// 你能想出一个仅使用常数空间的一趟扫描算法吗？ 
// 
// Related Topics 排序 数组 双指针 
// 👍 811 👎 0

/**
 *   @Author: muzhikid
 *   @CreatedTime: 2021-03-15 14:00:50
 *   @FinishedTime: 2021年03月15日14:50:04
 *   @Remarks:
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l,r;
        l = 0;
        r = nums.size()-1;
        while (true){
            while (l<nums.size() and nums[l]==0){
                l++;
            }
            while (r>=0 and nums[r]==2){
                r--;
            }
            if(l>=r){
                break;
            }
            if(nums[l]==2 and nums[r]==0){
                swap(nums[l],nums[r]);
                l++;
                r--;
            }else if(nums[l]==1 and nums[r]==0){
                swap(nums[l],nums[r]);
                l++;
            }else if(nums[l]==2 and nums[r]==1){
                swap(nums[l],nums[r]);
                r--;
            }else{
                int tempPointer = l+1;
                bool hasOperated = false;
                while(tempPointer<r){
                    if(nums[tempPointer]==0){
                        swap(nums[tempPointer],nums[l]);
                        l++;
                        hasOperated= true;
                        break;
                    }else if(nums[tempPointer]==2){
                        swap(nums[tempPointer],nums[r]);
                        hasOperated = true;
                        r--;
                        break;
                    }
                    tempPointer++;
                }
                if(!hasOperated){
                    return ;
                }
            }
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
    vector<int>test{1,0,1};
    s.sortColors(test);
    //s.method(params*);
    //cout<<s.method(params*);
    
}