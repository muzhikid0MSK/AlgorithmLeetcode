//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。 
//
// 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？ 
//
// 
//
// 示例 1： 
//
// 输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 示例 3： 
//
// 输入：nums1 = [0,0], nums2 = [0,0]
//输出：0.00000
// 
//
// 示例 4： 
//
// 输入：nums1 = [], nums2 = [1]
//输出：1.00000
// 
//
// 示例 5： 
//
// 输入：nums1 = [2], nums2 = []
//输出：2.00000
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -106 <= nums1[i], nums2[i] <= 106 
// 
// Related Topics 数组 二分查找 分治算法 
// 👍 3280 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-10 16:25:28
*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    const double NOT_FOUND=-2001.0;
    double solve(vector<int>X,vector<int>Y,int low, int high , int n){
        if(low>high){
            return NOT_FOUND;
        }
        int k = (low+high)/2;
        if(k==n-1 and X[k]<=Y[0]){
            return X[k];
        }else{
            if(Y[n-k-2]<= X[k] and X[k]<=Y[n-k-1]){
                return X[k];
            }else if(X[k]>Y[n-k-1]){
                return solve(X,Y,low,k-1,n);
            }else if(X[k]<Y[n-k-2]){
                return solve(X,Y,k+1,high,n);
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = solve(nums1,nums2,0,nums1.size()-1,nums1.size());
        if( ans==NOT_FOUND){
            return solve(nums2,nums1,0,nums2.size()-1,nums2.size());
        }else{
            return ans;
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}