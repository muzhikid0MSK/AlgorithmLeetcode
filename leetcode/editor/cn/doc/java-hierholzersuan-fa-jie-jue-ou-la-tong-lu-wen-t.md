### 解题思路
此题 为典型的 “欧拉通路” 问题
正如**官方题解**所讲那样，我们可以采用 **Hierholzer 算法**
主要思想 如下：
> 1. 从起点出发，进行深度优先搜索
> 2. 每次沿着某条边从某个顶点移动到另外一个顶点的时候，都需要删除这条边。
> 3.如果没有可移动的路径，则将所在节点加入到栈中，并返回。

### 运行结果
![image.png](https://pic.leetcode-cn.com/1598498390-RjMqdm-image.png)

### 代码

```java
class Solution {
    Map<String, PriorityQueue<String>> map
            = new HashMap<String, PriorityQueue<String>>(); // 以 当前地点 为 键，能去的地点 为值
    List<String> itinerary
            = new LinkedList<String>(); // 存储结果

    public List<String> findItinerary(List<List<String>> tickets) {
        if (tickets == null || tickets.size() <= 0) {
            return null;
        }

        String src = null; // 出发地
        String target = null; // 目的地
        for (List<String> ticket : tickets) {
            src = ticket.get(0);
            target = ticket.get(1);

            if (!map.containsKey(src)) {
                map.put(src, new PriorityQueue<String>());
            }
            map.get(src).offer(target);
        }
        dfs("JFK"); // 题目规定 JFK 为 起点
        Collections.reverse(itinerary); // 由于dfs存储itinerary是从目的地向出发地开始推算的，所以我们需要逆置
        return itinerary;
    }

    private void dfs(String cur) {
        /*
            递归结束 条件：
            当 cur 不是任何一张票的 起点，
            或者 目的地在之前都去过了 (ticket用过了)
         */
        while (map.containsKey(cur) && map.get(cur).size() > 0) {
            String tmp = map.get(cur).poll();
            dfs(tmp);
        }
        itinerary.add(cur); // 将 只能作为 “最终目的地” 的地点先录入(由此得到的 itinerary 是由 终点 指向 起点 的)
    }
}
```
打卡第39天，加油！！！