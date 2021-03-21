//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1: 
//
// 输入:
//[
//['1','1','1','1','0'],
//['1','1','0','1','0'],
//['1','1','0','0','0'],
//['0','0','0','0','0']
//]
//输出: 1
// 
//
// 示例 2: 
//
// 输入:
//[
//['1','1','0','0','0'],
//['1','1','0','0','0'],
//['0','0','1','0','0'],
//['0','0','0','1','1']
//]
//输出: 3
//解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 761 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-09-11 22:15:14
*/
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int>pa;
    int findFa(int x){
        return x==pa[x]?x:(pa[x]=findFa(pa[x]));
    }
    void merge(int x,int y){
        pa[findFa(x)]=findFa(y);
    }
    void init(int n){
        for(int i= 0;i<n;i++){
            pa[i]=i;
        }
    }
    const string fileName = "/Users/muzhikid/CLionProjects/AlgorithmLeetcode/leetcode/editor/cn/200-input.txt";

    int numIslands(vector<vector<char> >& grid) {
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();
        pa.resize(row*col);
        init(row*col);
        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    if(i-1>=0 and grid[i-1][j]=='1'){
                        merge(row*i+j,row*(i-1)+j);
                    }
                    if(j-1>=0 and grid[i][j-1]=='1'){
                        merge(row*i+j,row*(i)+j-1);
                    }
                    if(i+1<row and grid[i+1][j]=='1'){
                        merge(row*i+j,row*(i+1)+j);
                    }
                    if(j+1<col and grid[i][j+1]=='1'){
                        merge(row*i+j,row*i+j+1);
                    }

                }
            }
        }
        unordered_map<int,int>unique_pa;
        for(int i =0;i<row*col;i++){
            unique_pa[findFa(i)]=1;
        }

        //int pa[row*col];
        return unique_pa.size();

    }
};
//leetcode submit region end(Prohibit modification and deletion)


void split(const string &s,vector<char>& sv,const char delimiter = ' '){
    sv.clear();
    //int lastValidIndex =0 ;
    for(int i =0;i<s.size();i++){
        if(s[i]==delimiter){
            sv.push_back(s[i-1]);
        }
    }
    sv.push_back(s[s.length()-1]);

}
int main(){
    Solution s;
    std::ifstream in(s.fileName,ios::in);
    string query;
    vector<vector<char> >grid;
    if(in.is_open()){
        while (getline(in,query)){
            if(query.empty()){
                break;
            }
            vector<char>temp;
            split(query,temp,',');
            grid.push_back(temp);

        }
        cout<<s.numIslands(grid);
    }else{
        cout<<"Error in read file"<<endl;
    }


    //s.method(params*);
    //cout<<s.method(params*);
    
}