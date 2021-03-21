//编写一个算法来判断一个数 n 是不是快乐数。 
//
// 「快乐数」定义为： 
//
// 
// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。 
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。 
// 如果 可以变为 1，那么这个数就是快乐数。 
// 
//
// 如果 n 是快乐数就返回 true ；不是，则返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：19
//输出：true
//解释：
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1
// 
//
// 示例 2： 
//
// 
//输入：n = 2
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 231 - 1 
// 
// Related Topics 哈希表 数学 
// 👍 555 👎 0

/**
 *   @Author: muzhikid
 *   @CreatedTime: 2021-03-19 09:25:44
 *   @FinishedTime:
 *   @Remarks: ①"快慢指针"的思想,当慢指针结果与快指针结果相等时,判断是否是由1引起的循环.
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
    int cal(int num){
        int sum =0;
        int tempNum = num;
        while (tempNum!=0){
            sum+=(tempNum%10)*(tempNum%10);
            tempNum/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n,fast = n;
        do {
            fast = cal(fast);
            slow = cal(slow);
            fast = cal(fast);
        }while(slow!=fast);
        return slow == 1;
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