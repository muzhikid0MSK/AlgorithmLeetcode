### 解题思路
![image.png](https://pic.leetcode-cn.com/1598237185-HxqjpB-image.png)
1、看图，由于每一行只能出现一次，总共九行，也就是需要每行都要判断一次，因此会想到列表的形式，但是怎么能够知道每行出现一次呢？这时会想到字典，因为字典有key和value，key可以表示数字，value可以表示次数，所以这样就可以写成列表加字典的形式，一个列表中包含九个字典，一个字典代表一行
row = [{} for _ in range(9)]
2、同理，列也是如此，一个数字在同一列只能出现一次，和行一样，所以也是采用列表加字典的形式
col = [{} for _ in range(9)]
3、还要求以粗线分隔的3*3宫格只能出现一次，，刚好是九个宫格，所以也是采用列表加字典的形式
box = [{} for _ in range(9)]

然后就是对整个表格进行遍历，对有数字的格子进行操作
1）行操作：得到这个数字在本行中出现的次数
2）列操作：得到这个数字在本列中出现的次数
3）宫格操作：得到这个数字在宫格中的次数
因为行和列都是按顺序添加的，与列表中的i与j的下标进行对应，但宫格和列表中的i和j下标不对应，所以要找到当前数字所在的宫格的下标
能够观察得到，是以3为分隔的，所以每次不管i增加3还是j增加3，下标都要进行变化，总结下规律是
box_index = i // 3 * 3 + j / 3
最后判断只要行或列或宫格一个数字的次数大于一就返回false，否则循环结束是true
时间复杂度为O(1)（只有81个）,空间为O(1)（指定大小）

### 代码

```python
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        row = [{} for _ in range(9)]
        col = [{} for _ in range(9)]
        box = [{} for _ in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    num = int(board[i][j])
                    box_index = i // 3 * 3 + j / 3

                    row[i][num] = row[i].get(num, 0) + 1
                    col[j][num] = col[j].get(num, 0) + 1
                    box[box_index][num] = box[box_index].get(num, 0) + 1
                    if row[i][num] > 1 or col[j][num] > 1 or box[box_index][num] > 1:
                        return False
        return True
```