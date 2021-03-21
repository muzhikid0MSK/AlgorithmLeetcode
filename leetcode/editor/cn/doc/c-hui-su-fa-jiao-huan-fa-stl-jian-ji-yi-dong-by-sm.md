# 解题思路
法一：回溯
法二：交换法（更快！！）
法三：stl中的next_permutation（*来搞笑的hhh*）

# 代码
### **法一：回溯**
路径：记录在current数组中，记录已经做出的选择
选择列表：用`vector<bool> nums1`来实现，取值为true的可以选择
结束条件：当`current.size()==nums.size()`
**TIPS:**
1. 这种用`vector<bool> nums1`来实现选择列表的方法，比调用find函数在current中查找是否已经有该数字的方法要快得多！！**（使用前者大概8ms，后者要24ms）**。
2. 同样的回溯思路，如果使用`list`来实现，时间可降到0ms！！

![微信图片_20200416183553.png](https://pic.leetcode-cn.com/4ac1efd6270444fcc240ae010e7da73249a15ba3d3f6f21a5ec16bef1786d1f6-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200416183553.png)


```cpp
    vector<vector<int> > result;
void func(vector<int> &nums,vector<int> &current, vector<bool>&nums1)
{
	if (current.size() == nums1.size())
		result.push_back(current);
	else
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums1[i])
			{
				current.push_back(nums[i]);
				nums1[i] = false;
				func(nums, current, nums1);
				nums1[i] = true;
				current.pop_back();
			}
		}
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	if (nums.size() == 0)
		return {};
	else if (nums.size() == 1)
		return { {nums[0]} };
	else
	{
		vector<bool> nums1(nums.size(),true);
		vector<int> current;
		func(nums, current, nums1);
		return result;
	}
}
};
```

### 法二：交换法
此法，通过交换元素来实现全排列。即对于`[start,end]`中的元素，for循环遍历每个元素分别成为第一个元素，然后再对`[start+1,end]`递归调用排列函数，直到`start==end`递归终止。
**TIPS**：
1. 通过交换元素实现，时间复杂度降低！
2. **交换法得到的序列并不是从小到大的！！**

![微信图片_20200416183553.png](https://pic.leetcode-cn.com/41fa75e5782d37189380f021ffdd35b22aa930c536076868129fe15b375bbca5-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200416183553.png)


```cpp
vector<vector<int> > result;
void func(vector<int> &nums, int start, int end)
{
	if (start == end)
		result.push_back(nums);
	else
	{
		for (int i = start; i <= end; i++)
		{
			swap(nums[i], nums[start]);
			func(nums, start + 1, end);
			swap(nums[i], nums[start]);
		}
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	if (nums.size() == 0)
		return {};
	else if (nums.size() == 1)
		return { {nums[0]} };
	else
	{
		func(nums, 0, nums.size()-1);
		return result;
	}
}
```

### 法三：stl中的next_permutation
*来搞笑的hhhh 考试这样应该会被挂hhh*
```cpp
vector<vector<int>> permute(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());
    do {
        result.push_back(nums);
    }while (next_permutation(nums.begin(), nums.end()));

    return result;
    }

```
如果题解对你有启发或者帮助的话，不妨点个赞~
Thanks for your reading!!
