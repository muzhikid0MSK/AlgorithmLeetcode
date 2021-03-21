//编写一个 SQL 查询，来删除 Person 表中所有重复的电子邮箱，重复的邮箱里只保留 Id 最小 的那个。 
//
// +----+------------------+
//| Id | Email            |
//+----+------------------+
//| 1  | john@example.com |
//| 2  | bob@example.com  |
//| 3  | john@example.com |
//+----+------------------+
//Id 是这个表的主键。
// 
//
// 例如，在运行你的查询语句之后，上面的 Person 表应返回以下几行: 
//
// +----+------------------+
//| Id | Email            |
//+----+------------------+
//| 1  | john@example.com |
//| 2  | bob@example.com  |
//+----+------------------+
// 
//
// 
//
// 提示： 
//
// 
// 执行 SQL 之后，输出是整个 Person 表。 
// 使用 delete 语句。 
// 
// 👍 348 👎 0

/**
 *   @Author: muzhikid
 *   @CreatedTime: 2021-03-19 09:25:25
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