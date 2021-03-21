//在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。 
//
// 移动顺序由字符串表示。字符 move[i] 表示其第 i 次移动。机器人的有效动作有 R（右），L（左），U（上）和 D（下）。如果机器人在完成所有动作后
//返回原点，则返回 true。否则，返回 false。 
//
// 注意：机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。 
//
// 
//
// 示例 1: 
//
// 输入: "UD"
//输出: true
//解释：机器人向上移动一次，然后向下移动一次。所有动作都具有相同的幅度，因此它最终回到它开始的原点。因此，我们返回 true。 
//
// 示例 2: 
//
// 输入: "LL"
//输出: false
//解释：机器人向左移动两次。它最终位于原点的左侧，距原点有两次 “移动” 的距离。我们返回 false，因为它在移动结束时没有返回原点。 
// Related Topics 字符串 
// 👍 134 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-28 00:24:15
*/
#include <iostream>
//#include <map>
//#include <queue>
//#include <vector>
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    map<char,int> cnt;
//    bool judgeCircle(string moves) {
//        cnt['U']=0;
//        cnt['L']=0;
//        cnt['R']=0;
//        cnt['D']=0;
//        for(int i =0;i<moves.length();i++){
//            cnt[moves[i]]++;
//        }
//        return cnt['U']==cnt['D']&&cnt['L']==cnt['R'];
//    }

/**
 * 两种方法核心差不多，下面一种节约空间一丢丢，不使用map速度也会稍微快一点
 * 2020年08月28日00:50:43
 */
    short judge[2];
    bool judgeCircle(string moves){
        judge[0]=0;
        judge[1]=0;
        for(char move : moves){
            switch (move) {
                case 'L':judge[0]--;break;
                case 'R':judge[0]++;break;
                case 'U':judge[1]--;break;
                case 'D':judge[1]++;break;
                default: break;
            }
//            if(move=='L'){
//                judge[0]--;
//            }else if(move=='R'){
//                judge[0]++;
//            }else if(move=='U'){
//                judge[1]++;
//            }else{
//                judge[1]--;
//            }
        }
        return !judge[0]&&!judge[1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}