//给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。 
//
// 示例: 
//
// 输入: 3
//输出:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//] 
// Related Topics 数组 
// 👍 243 👎 0

/**
*   @Author: muzhikid
*   @CreatedTime: 2020-10-04 16:09:03
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans;
        vector<bool>visited(n*n,false);
        //init
        for(int i =0;i<n;i++){
            vector<int>initV;
            initV.resize(n);
            ans.push_back(initV);
        }
        enum {JADD=0,IADD,JDE,IDE};
        int flag = JADD;
        int i=0,j=0;
        int cntInvalid=0;
        int num=1;
        START:
        switch (flag) {
            case JADD:
                if(i>=0 and i<n and j>=0 and j<n and !visited[i*n+j]){
                    visited[i*n+j]=true;
                    ans[i][j]=(num++);
                    //cout<<matrix[i][j]<<endl;
                    j++;
                    cntInvalid=0;
                }else{
                    cntInvalid++;
                    j--;
                    i++;
                    flag=(flag+1)%4;
                }
                break;
            case IADD:
                //cout<<"here is IADD"<<endl;
                // cout<<"i is "<<i<<" and j is "<<j<<endl;
                if(i>=0 and i<n and j>=0 and j<n and !visited[i*n+j]){
                    visited[i*n+j]=true;
                    ans[i][j]=(num++);

                    i++;
                    cntInvalid=0;
                }else{

                    cntInvalid++;
                    i--;
                    j--;
                    flag=(flag+1)%4;
                }
                break;
            case JDE:
                if(i>=0 and i<n and j>=0 and j<n and !visited[i*n+j]){
                    visited[i*n+j]=true;
                    ans[i][j]=(num++);
                    // cout<<matrix[i][j]<<endl;
                    j--;
                    cntInvalid=0;
                }else{
                    cntInvalid++;
                    j++;
                    i--;
                    flag=(flag+1)%4;
                }
                break;
            case IDE:
                if(i>=0 and i<n and j>=0 and j<n and !visited[i*n+j]){
                    visited[i*n+j]=true;
                    ans[i][j]=(num++);
                    // cout<<matrix[i][j]<<endl;
                    i--;
                    cntInvalid=0;
                }else{
                    cntInvalid++;
                    i++;
                    j++;
                    flag=(flag+1)%4;
                }
                break;

        }

        if(cntInvalid!=4){
            goto START;
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