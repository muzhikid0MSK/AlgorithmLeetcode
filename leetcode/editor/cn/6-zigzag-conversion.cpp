//将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。 
//
// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下： 
//
// L   C   I   R
//E T O E S I I G
//E   D   H   N
// 
//
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。 
//
// 请你实现这个将字符串进行指定行数变换的函数： 
//
// string convert(string s, int numRows); 
//
// 示例 1: 
//
// 输入: s = "LEETCODEISHIRING", numRows = 3
//输出: "LCIRETOESIIGEDHN"
// 
//
// 示例 2: 
//
// 输入: s = "LEETCODEISHIRING", numRows = 4
//输出: "LDREOEIIECIHNTSG"
//解释:
//
//L     D     R
//E   O E   I I
//E C   I H   N
//T     S     G 
// Related Topics 字符串 
// 👍 806 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-27 16:12:07
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
    string convert(string s, int numRows) {
        if(s.empty())
            return "";
        if(numRows==1)
            return s;
        string ans;
        //int firstRowIndexes[(s.length()-1)/(2*numRows-2)+1];
        vector<int>firstRowIndexes;

        for(int i =0;i<numRows;i++){
            if(i==0){
                int tempI = 1;
                while ((tempI-1)*(2*numRows-2)<s.length()){
                    int index = (tempI-1)*(2*numRows-2);
                    ans+=s[index];
                    firstRowIndexes.push_back(index);
                    tempI++;
                }

            }else if(i == numRows-1){
                for(int j = 0;j<firstRowIndexes.size();j++){
                    int tempIndex1 = firstRowIndexes[j]+numRows-1;
                    if(tempIndex1<s.length())
                        ans+=s[tempIndex1];
                }
            }else{
                for(int j =0; j < firstRowIndexes.size(); j++){
                    int tempIndex1 = firstRowIndexes[j]+i;
                    if(tempIndex1<s.length())
                        ans+=s[tempIndex1];
                    else
                        break;
                    tempIndex1=firstRowIndexes[j]+(2*numRows-2-i);
                    if(tempIndex1<s.length())
                        ans+=s[tempIndex1];
                    else
                        break;
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    cout<<s.convert("PAYPALISHIRING",4);
    //s.method(params*);
    //cout<<s.method(params*);
    
}