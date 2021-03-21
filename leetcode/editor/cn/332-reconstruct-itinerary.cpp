//给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 
//JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。 
//
// 说明: 
//
// 
// 如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排
//序更靠前 
// 所有的机场都用三个大写字母表示（机场代码）。 
// 假定所有机票至少存在一种合理的行程。 
// 
//
// 示例 1: 
//
// 输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]
// 
//
// 示例 2: 
//
// 输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
//解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。 
// Related Topics 深度优先搜索 图 
// 👍 202 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-08-27 11:59:32
*/
#include <iostream>
#include <cstring>

#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 上当了
 * 需要走完所有点
 * 欧拉通路问题
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string> > localTickets;
    vector<string>ans;
    bool visited[101];          //没说明长度
    void dfs(int from_index){
        int loc =from_index;
        string to = "ZZZ";
        for(int i =0;i<localTickets.size();i++){
            if(!visited[i]&&localTickets[i][0]==localTickets[from_index][1]){
                if(my_strcmp(localTickets[i][1],to)<=0){
                    loc = i;
                    to = localTickets[i][1];
                }
            }
        }
        if(my_strcmp(to,"ZZZ")!=0){
            visited[loc] = true;
            ans.push_back(localTickets[loc][0]);
            dfs(loc);                               //芜湖塔台允许起飞~
        }else{
            ans.push_back(localTickets[loc][1]);
            return;
        }
    }
    void init(){
        for(int i =0;i<101;i++){
            visited[i]= false;
        }
    }
    int my_strcmp(string a, string b){
        int len=3;
        //a.length()>b.length()?len=b.length():len = a.length();
        for(int i =0;i<len;i++){
            if(a[i]<b[i]){
                return -1;
            }else if(a[i]>b[i]){
                return 1;
            }else{
                ;
            }
        }
        return 0;

    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        init();
        localTickets = tickets;
        string to = "ZZZ";
        int loc = 0;
        for(int i =0;i<localTickets.size();i++){
            if(localTickets[i][0] =="JFK"){
                if(my_strcmp(localTickets[i][1], to) <= 0){
                    to = localTickets[i][1];
                    loc = i;
                }
            }
        }
        visited[loc]=true;
        ans.push_back(localTickets[loc][0]);
        dfs(loc);          //从(按字典序)第一个JFK的目的地作为起点
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
void create_test(vector<vector<string>> &test,string a,string b){
    vector<string>temp;
    temp.push_back(a);
    temp.push_back(b);
    test.push_back(temp);
}
int main(){
    Solution s;
    vector<vector<string> >test;
    create_test(test,"MUC","LHR");
    create_test(test,"JFK","MUC");
    create_test(test,"SFO","SJC");
    create_test(test,"LHR","SFO");
    s.findItinerary(test);
    //cout<<s.my_strcmp("BAC","BBB")<<endl;
    //s.method(params*);
    //cout<<s.method(params*);
    
}