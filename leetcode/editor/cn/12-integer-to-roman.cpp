//罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。 
//
// 字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000 
//
// 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做 XXVII, 即为 XX + V + I
//I 。 
//
// 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5
// 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况： 
//
// 
// I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。 
// X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
// C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。 
// 
//
// 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。 
//
// 示例 1: 
//
// 输入: 3
//输出: "III" 
//
// 示例 2: 
//
// 输入: 4
//输出: "IV" 
//
// 示例 3: 
//
// 输入: 9
//输出: "IX" 
//
// 示例 4: 
//
// 输入: 58
//输出: "LVIII"
//解释: L = 50, V = 5, III = 3.
// 
//
// 示例 5: 
//
// 输入: 1994
//输出: "MCMXCIV"
//解释: M = 1000, CM = 900, XC = 90, IV = 4. 
// Related Topics 数学 字符串 
// 👍 420 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-05 22:43:26
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct romaNum{
        string character;
        int16_t value;
    };
    void init(vector<struct romaNum>&initial ){
        initial.push_back({"I",1});
        initial.push_back({"IV",4});
        initial.push_back({"V",5});
        initial.push_back({"IX",9});
        initial.push_back({"X",10});
        initial.push_back({"XL",40});
        initial.push_back({"L",50});
        initial.push_back({"XC",90});
        initial.push_back({"C",100});
        initial.push_back({"CD",400});
        initial.push_back({"D",500});
        initial.push_back({"CM",900});
        initial.push_back({"M",1000});
    }
    string intToRoman(int num) {
        vector<struct romaNum>initial;
        init(initial);
        string ans;
        for(int i =initial.size()-1;i>=0;i--){
            if(num>=initial[i].value){
                num-=initial[i].value;
                ans+=initial[i].character;
                i++;
            }
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