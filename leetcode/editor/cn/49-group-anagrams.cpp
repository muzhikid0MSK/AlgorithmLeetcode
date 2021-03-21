//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 
//
// 示例: 
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//] 
//
// 说明： 
//
// 
// 所有输入均为小写字母。 
// 不考虑答案输出的顺序。 
// 
// Related Topics 哈希表 字符串 
// 👍 669 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2021-03-03 19:09:30
*   @FinishedTime: 2021年03月08日14:22:21
*   @Remarks:  			执行耗时:64 ms,击败了65.72% 的C++用户
			            内存消耗:23 MB,击败了7.56% 的C++用户

*/
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string returnKey(string a){
        string tempKey;
        vector<int>cnt(26,0);
        for(int i =0;i<a.length();i++){
            cnt[a[i]-'a']++;
        }
        for(int i =0;i<26;i++){
            if(cnt[i]){
                tempKey+=(i+'a');
                tempKey+=to_string(cnt[i]);
            }
        }
        return tempKey;
    }
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string,vector<string> >record;
        for(auto &item:strs){
            record[returnKey(item)].emplace_back(item);
        }
        vector<vector<string> >ans;

        for(auto &item:record){
//            vector<string>temp;
//            for(string s:item.second){
//                temp.emplace_back(s);
//            }
            ans.push_back(item.second);
        }
        return ans;
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
    cout<<s.returnKey("eat")<<endl;
    cout<<s.returnKey("ate")<<endl;
    //s.method(params*);
    //cout<<s.method(params*);
    
}