//给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。 
//
// 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。 
//
// 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。 
//
// 文本的最后一行应为左对齐，且单词之间不插入额外的空格。 
//
// 说明: 
//
// 
// 单词是指由非空格字符组成的字符序列。 
// 每个单词的长度大于 0，小于等于 maxWidth。 
// 输入单词数组 words 至少包含一个单词。 
// 
//
// 示例: 
//
// 输入:
//words = ["This", "is", "an", "example", "of", "text", "justification."]
//maxWidth = 16
//输出:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//]
// 
//
// 示例 2: 
//
// 输入:
//words = ["What","must","be","acknowledgment","shall","be"]
//maxWidth = 16
//输出:
//[
//  "What   must   be",
//  "acknowledgment  ",
//  "shall be        "
//]
//解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
//     因为最后一行应为左对齐，而不是左右两端对齐。       
//     第二行同样为左对齐，这是因为这行只包含一个单词。
// 
//
// 示例 3: 
//
// 输入:
//words = ["Science","is","what","we","understand","well","enough","to","explain
//",
//         "to","a","computer.","Art","is","everything","else","we","do"]
//maxWidth = 20
//输出:
//[
//  "Science  is  what we",
//  "understand      well",
//  "enough to explain to",
//  "a  computer.  Art is",
//  "everything  else  we",
//  "do                  "
//]
// 
// Related Topics 字符串 
// 👍 102 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-06 08:08:45
*/

#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string spaces(int n){
        string r;
        for(int i =0;i<n;i++){
            r+=' ';
        }
        return r;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curLength=0,curWords=0;
        int lastBeginIndex=0;
        vector<string>ans;
        for(int i =0;i<words.size();i++){
            curLength+=words[i].length();
            curWords++;
            if(curLength+(curWords-1)>maxWidth ){    //curWords-1 为至少需要的空格数
                curLength-=words[i].length();
                curWords--;
                int spaceCnt=maxWidth-curLength;
                if(curWords==1){
                    ans.push_back(words[lastBeginIndex]+spaces(spaceCnt));
                }else{
                    string row;
                   if(spaceCnt%(curWords-1)){//不能均匀分配

                       row+=words[lastBeginIndex];
                       int tmp=spaceCnt/(curWords-1);
                       int jj = i-1;

                       while(spaceCnt%(curWords-1)){    //spaceCnt不能被空位置整除
                           words[jj]=spaces(tmp)+words[jj];
                           spaceCnt-=tmp;
                           jj--;
                           curWords--;
                       }
                       tmp = spaceCnt/(curWords-1);
                       for(int j=lastBeginIndex+1;j<=jj;j++){
                           row+=spaces(tmp);
                           row+=words[j];
                       }
                       for(int j =jj+1;j<i;j++){
                           row+=words[j];
                       }
                   }else{
                       int tmp=spaceCnt/(curWords-1);
                       row+=words[lastBeginIndex];
                       for(int j =lastBeginIndex+1;j<i;j++){
                           row+=spaces(tmp);
                           row+=words[j];
                       }
                   }
                   ans.push_back(row);

                }
                lastBeginIndex=i;
                curWords=0;
                curLength=0;
                i--;
            }
        }
        string lastRow;
        for(int i =lastBeginIndex;i<words.size()-1;i++){
            lastRow+=words[i];
            lastRow+=' ';
        }
       lastRow+=words[words.size()-1];
       lastRow+=spaces(maxWidth-curLength-(curWords-1));
        ans.push_back(lastRow);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(){
    Solution s;
    //s.method(params*);
    //cout<<s.method(params*);
    
}