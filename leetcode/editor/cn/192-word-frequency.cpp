//写一个 bash 脚本以统计一个文本文件 words.txt 中每个单词出现的频率。 
//
// 为了简单起见，你可以假设： 
//
// 
// words.txt只包括小写字母和 ' ' 。 
// 每个单词只由小写字母组成。 
// 单词间由一个或多个空格字符分隔。 
// 
//
// 示例: 
//
// 假设 words.txt 内容如下： 
//
// the day is sunny the the
//the sunny is is
// 
//
// 你的脚本应当输出（以词频降序排列）： 
//
// the 4
//is 3
//sunny 2
//day 1
// 
//
// 说明: 
//
// 
// 不要担心词频相同的单词的排序问题，每个单词出现的频率都是唯一的。 
// 你可以使用一行 Unix pipes 实现吗？ 
// 
// 👍 132 👎 0

/**
 *   @Author: muzhikid
 *   @CreatedTime: 2021-03-19 09:25:14
 *   @FinishedTime:
 *   @Remarks:
 */
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>


using namespace std;

//There is no code of C++ type for this problem

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