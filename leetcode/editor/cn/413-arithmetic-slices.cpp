//如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。 
//
// 例如，以下数列为等差数列: 
//
// 
//1, 3, 5, 7, 9
//7, 7, 7, 7
//3, -1, -5, -9 
//
// 以下数列不是等差数列。 
//
// 
//1, 1, 2, 5, 7 
//
// 
//
// 数组 A 包含 N 个数，且索引从0开始。数组 A 的一个子数组划分为数组 (P, Q)，P 与 Q 是整数且满足 0<=P<Q<N 。 
//
// 如果满足以下条件，则称子数组(P, Q)为等差数组： 
//
// 元素 A[P], A[p + 1], ..., A[Q - 1], A[Q] 是等差的。并且 P + 1 < Q 。 
//
// 函数要返回数组 A 中所有为等差数组的子数组个数。 
//
// 
//
// 示例: 
//
// 
//A = [1, 2, 3, 4]
//
//返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。
// 
// Related Topics 数学 动态规划 
// 👍 166 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-09 09:44:24
*/
#include <iostream>

#include <vector>


using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& A) {
        int ans =0 ;
        int offset =2;
        for(int i =0;i+2<A.size();i++){
            int d =0;
            for(;i+offset<A.size();offset++){
                if(offset == 2){
                    if(A[i+1]-A[i] == A[i+2]-A[i+1]){
                        d = A[i+1]-A[i];
                        ans++;
                    }else{
                        break;
                    }
                }else{
                    if(A[i+offset]-A[i+offset-1] == d ){
                        ans++;
                    }else{
                        break;
                    }
                }
            }
            offset=2;
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    vector<int>test{1,2,3,4};
    cout<<s.numberOfArithmeticSlices(test);
    //s.method(params*);
    //cout<<s.method(params*);
    
}