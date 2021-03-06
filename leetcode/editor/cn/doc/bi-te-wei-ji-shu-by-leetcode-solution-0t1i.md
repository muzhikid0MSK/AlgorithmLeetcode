#### 前言

这道题需要计算从 *0* 到 ![\textit{num} ](./p__textit{num}_.png)  的每个数的二进制表示中的 *1* 的数目。最直观的方法是对每个数直接计算二进制表示中的 *1* 的数目，时间复杂度较高。也可以使用动态规划的方法，时间复杂度较低。

为了表述简洁，下文用「一比特数」表示二进制表示中的 *1* 的数目。

#### 方法一：直接计算

最直观的方法是对从 *0* 到 ![\textit{num} ](./p__textit{num}_.png)  的每个数直接计算「一比特数」。

每个 ![\texttt{int} ](./p__texttt{int}_.png)  型的数都可以用 *32* 位二进制数表示，只要遍历其二进制表示的每一位即可得到 *1* 的数目。

利用位运算的技巧，可以在一定程度上提升计算速度。按位与运算（![\& ](./p__&_.png) ）的一个性质是：对于任意整数 *x*，令 ![x=x\&(x-1) ](./p__x=x_&_x-1__.png) ，该运算将 *x* 的二进制表示的最后一个 *1* 变成 *0*。因此，对 *x* 重复该操作，直到 *x* 变成 *0*，则操作次数即为 *x* 的「一比特数」。

另外，部分编程语言有相应的内置函数，例如 ![\texttt{Java} ](./p__texttt{Java}_.png)  的 ![\texttt{Integer.bitCount} ](./p__texttt{Integer.bitCount}_.png) ，![\texttt{C++} ](./p__texttt{C++}_.png)  的 ![\texttt{\_\_builtin\_popcount} ](./p__texttt{__builtin_popcount}_.png) ，![\texttt{Go} ](./p__texttt{Go}_.png)  的 ![\texttt{bits.OnesCount} ](./p__texttt{bits.OnesCount}_.png)  等，读者可以自行尝试。需要注意的是，使用编程语言的内置函数时，不适用本方法的时间复杂度分析。

```Java [sol1-Java]
class Solution {
    public int[] countBits(int num) {
        int[] bits = new int[num + 1];
        for (int i = 0; i <= num; i++) {
            bits[i] = countOnes(i);
        }
        return bits;
    }

    public int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }
}
```

```JavaScript [sol1-JavaScript]
var countBits = function(num) {
    const bits = new Array(num + 1).fill(0);
    for (let i = 0; i <= num; i++) {
        bits[i] = countOnes(i);
    }
    return bits
};

const countOnes = (x) => {
    let ones = 0;
    while (x > 0) {
        x &= (x - 1);
        ones++;
    }
    return ones;
}
```

```go [sol1-Golang]
func onesCount(x int) (ones int) {
    for ; x > 0; x &= x - 1 {
        ones++
    }
    return
}

func countBits(num int) []int {
    bits := make([]int, num+1)
    for i := range bits {
        bits[i] = onesCount(i)
    }
    return bits
}
```

```Python [sol1-Python3]
class Solution:
    def countBits(self, num: int) -> List[int]:
        def countOnes(x: int) -> int:
            ones = 0
            while x > 0:
                x &= (x - 1)
                ones += 1
            return ones
        
        bits = [countOnes(i) for i in range(num + 1)]
        return bits
```

```C++ [sol1-C++]
class Solution {
public:
    int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 0; i <= num; i++) {
            bits[i] = countOnes(i);
        }
        return bits;
    }
};
```

```C [sol1-C]
int countOnes(int x) {
    int ones = 0;
    while (x > 0) {
        x &= (x - 1);
        ones++;
    }
    return ones;
}

int* countBits(int num, int* returnSize) {
    int* bits = malloc(sizeof(int) * (num + 1));
    *returnSize = num + 1;
    for (int i = 0; i <= num; i++) {
        bits[i] = countOnes(i);
    }
    return bits;
}
```

**复杂度分析**

- 时间复杂度：![O(k\times\textit{num}) ](./p__O_k_times_textit{num}__.png) ，其中 *k* 是 ![\texttt{int} ](./p__texttt{int}_.png)  型的二进制位数，*k=32*。需要对从 *0* 到 ![\textit{num} ](./p__textit{num}_.png)  的每个数使用 *O(k)* 的时间计算「一比特数」，因此时间复杂度是 ![O(k\times\textit{num}) ](./p__O_k_times_textit{num}__.png) 。

- 空间复杂度：*O(1)*。除了返回的数组以外，空间复杂度为常数。

#### 方法二：动态规划——最高有效位

方法一需要对每个数遍历其二进制表示的每一位。可以换一个思路，当计算 *i* 的「一比特数」时，如果存在 ![0\lej<i ](./p__0_le_j_i_.png) ，*j* 的「一比特数」已知，且 *i* 和 *j* 相比，*i* 的二进制表示只多了一个 *1*，则可以快速得到 *i* 的「一比特数」。

令 ![\textit{bits}\[i\] ](./p__textit{bits}_i__.png)  表示 *i* 的「一比特数」，则上述关系可以表示成：![\textit{bits}\[i\]=\textit{bits}\[j\]+1 ](./p__textit{bits}_i_=_textit{bits}_j_+1_.png) 。

对于正整数 *x*，如果可以知道最大的正整数 *y*，使得 ![y\lex ](./p__y_le_x_.png)  且 *y* 是 *2* 的整数次幂，则 *y* 的二进制表示中只有最高位是 *1*，其余都是 *0*，此时称 *y* 为 *x* 的「最高有效位」。令 *z=x-y*，显然 ![0\lez<x ](./p__0_le_z_x_.png) ，则 ![\textit{bits}\[x\]=\textit{bits}\[z\]+1 ](./p__textit{bits}_x_=textit{bits}_z_+1_.png) 。

为了判断一个正整数是不是 *2* 的整数次幂，可以利用方法一中提到的按位与运算的性质。如果正整数 *y* 是 *2* 的整数次幂，则 *y* 的二进制表示中只有最高位是 *1*，其余都是 *0*，因此 ![y\&(y-1)=0 ](./p__y_&_y-1_=0_.png) 。由此可见，正整数 *y* 是 *2* 的整数次幂，当且仅当 ![y\&(y-1)=0 ](./p__y_&_y-1_=0_.png) 。

显然，*0* 的「一比特数」为 *0*。使用 ![\textit{highBit} ](./p__textit{highBit}_.png)  表示当前的最高有效位，遍历从 *1* 到 ![\textit{num} ](./p__textit{num}_.png)  的每个正整数 *i*，进行如下操作。

- 如果 ![i\&(i-1)=0 ](./p__i_&_i-1_=0_.png) ，则令 ![\textit{highBit}=i ](./p__textit{highBit}=i_.png) ，更新当前的最高有效位。

- *i* 比 ![i-\textit{highBit} ](./p__i-textit{highBit}_.png)  的「一比特数」多 *1*，由于是从小到大遍历每个数，因此遍历到 *i* 时，![i-\textit{highBit} ](./p__i-textit{highBit}_.png)  的「一比特数」已知，令 ![\textit{bits}\[i\]=\textit{bits}\[i-\textit{highBit}\]+1 ](./p__textit{bits}_i_=textit{bits}_i-textit{highBit}_+1_.png) 。

最终得到的数组 ![\textit{bits} ](./p__textit{bits}_.png)  即为答案。

```Java [sol2-Java]
class Solution {
    public int[] countBits(int num) {
        int[] bits = new int[num + 1];
        int highBit = 0;
        for (int i = 1; i <= num; i++) {
            if ((i & (i - 1)) == 0) {
                highBit = i;
            }
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
}
```

```JavaScript [sol2-JavaScript]
var countBits = function(num) {
    const bits = new Array(num + 1).fill(0);
    let highBit = 0;
    for (let i = 1; i <= num; i++) {
        if ((i & (i - 1)) == 0) {
            highBit = i;
        }
        bits[i] = bits[i - highBit] + 1;
    }
    return bits;
};
```

```go [sol2-Golang]
func countBits(num int) []int {
    bits := make([]int, num+1)
    highBit := 0
    for i := 1; i <= num; i++ {
        if i&(i-1) == 0 {
            highBit = i
        }
        bits[i] = bits[i-highBit] + 1
    }
    return bits
}
```

```Python [sol2-Python3]
class Solution:
    def countBits(self, num: int) -> List[int]:
        bits = [0]
        highBit = 0
        for i in range(1, num + 1):
            if i & (i - 1) == 0:
                highBit = i
            bits.append(bits[i - highBit] + 1)
        return bits
```

```C++ [sol2-C++]
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        int highBit = 0;
        for (int i = 1; i <= num; i++) {
            if ((i & (i - 1)) == 0) {
                highBit = i;
            }
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
};
```

```C [sol2-C]
int* countBits(int num, int* returnSize) {
    int* bits = malloc(sizeof(int) * (num + 1));
    *returnSize = num + 1;
    bits[0] = 0;
    int highBit = 0;
    for (int i = 1; i <= num; i++) {
        if ((i & (i - 1)) == 0) {
            highBit = i;
        }
        bits[i] = bits[i - highBit] + 1;
    }
    return bits;
}
```

**复杂度分析**

- 时间复杂度：![O(\textit{num}) ](./p__O_textit{num}__.png) 。对于每个数，只需要 *O(1)* 的时间计算「一比特数」。

- 空间复杂度：*O(1)*。除了返回的数组以外，空间复杂度为常数。

#### 方法三：动态规划——最低有效位

方法二需要实时维护最高有效位，当遍历到的数是 *2* 的整数次幂时，需要更新最高有效位。如果再换一个思路，可以使用「最低有效位」计算「一比特数」。

对于正整数 *x*，将其二进制表示右移一位，等价于将其二进制表示的最低位去掉，得到的数是 ![\lfloor\frac{x}{2}\rfloor ](./p__lfloor_frac{x}{2}_rfloor_.png) 。如果 ![\textit{bits}\big\[\lfloor\frac{x}{2}\rfloor\big\] ](./p__textit{bits}big_lfloor_frac{x}{2}_rfloorbig__.png)  的值已知，则可以得到 ![\textit{bits}\[x\] ](./p__textit{bits}_x__.png)  的值：

- 如果 *x* 是偶数，则 ![\textit{bits}\[x\]=\textit{bits}\big\[\lfloor\frac{x}{2}\rfloor\big\] ](./p__textit{bits}_x_=textit{bits}big_lfloor_frac{x}{2}_rfloorbig__.png) ；

- 如果 *x* 是奇数，则 ![\textit{bits}\[x\]=\textit{bits}\big\[\lfloor\frac{x}{2}\rfloor\big\]+1 ](./p__textit{bits}_x_=textit{bits}big_lfloor_frac{x}{2}_rfloorbig_+1_.png) 。

上述两种情况可以合并成：![\textit{bits}\[x\] ](./p__textit{bits}_x__.png)  的值等于 ![\textit{bits}\big\[\lfloor\frac{x}{2}\rfloor\big\] ](./p__textit{bits}big_lfloor_frac{x}{2}_rfloorbig__.png)  的值加上 *x* 除以 *2* 的余数。

由于 ![\lfloor\frac{x}{2}\rfloor ](./p__lfloor_frac{x}{2}_rfloor_.png)  可以通过 *x >> 1* 得到，*x* 除以 *2* 的余数可以通过 ![x\&1 ](./p__x_&_1_.png)  得到，因此有：![\textit{bits}\[x\]=\textit{bits}\[x>>1\]+(x\&1) ](./p__textit{bits}_x_=textit{bits}_x__1_+_x_&_1__.png) 。

遍历从 *1* 到 ![\textit{num} ](./p__textit{num}_.png)  的每个正整数 *i*，计算 ![\textit{bits} ](./p__textit{bits}_.png)  的值。最终得到的数组 ![\textit{bits} ](./p__textit{bits}_.png)  即为答案。

```Java [sol3-Java]
class Solution {
    public int[] countBits(int num) {
        int[] bits = new int[num + 1];
        for (int i = 1; i <= num; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
}
```

```JavaScript [sol3-JavaScript]
var countBits = function(num) {
    const bits = new Array(num + 1).fill(0);
    for (let i = 1; i <= num; i++) {
        bits[i] = bits[i >> 1] + (i & 1);
    }
    return bits;
};
```

```go [sol3-Golang]
func countBits(num int) []int {
    bits := make([]int, num+1)
    for i := 1; i <= num; i++ {
        bits[i] = bits[i>>1] + i&1
    }
    return bits
}
```

```Python [sol3-Python3]
class Solution:
    def countBits(self, num: int) -> List[int]:
        bits = [0]
        for i in range(1, num + 1):
            bits.append(bits[i >> 1] + (i & 1))
        return bits
```

```C++ [sol3-C++]
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 1; i <= num; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};
```

```C [sol3-C]
int* countBits(int num, int* returnSize) {
    int* bits = malloc(sizeof(int) * (num + 1));
    *returnSize = num + 1;
    bits[0] = 0;
    for (int i = 1; i <= num; i++) {
        bits[i] = bits[i >> 1] + (i & 1);
    }
    return bits;
}
```

**复杂度分析**

- 时间复杂度：![O(\textit{num}) ](./p__O_textit{num}__.png) 。对于每个数，只需要 *O(1)* 的时间计算「一比特数」。

- 空间复杂度：*O(1)*。除了返回的数组以外，空间复杂度为常数。

#### 方法四：动态规划——最低设置位

定义正整数 *x* 的「最低设置位」为 *x* 的二进制表示中的最低的 *1* 所在位。例如，*10* 的二进制表示是 *1010_{(2)}*，其最低设置位为 *2*，对应的二进制表示是 *10_{(2)}*。

令 ![y=x\&(x-1) ](./p__y=x_&_x-1__.png) ，则 *y* 为将 *x* 的最低设置位从 *1* 变成 *0* 之后的数，显然 ![0\ley<x ](./p__0_le_y_x_.png) ，![\textit{bits}\[x\]=\textit{bits}\[y\]+1 ](./p__textit{bits}_x_=textit{bits}_y_+1_.png) 。因此对任意正整数 *x*，都有 ![\textit{bits}\[x\]=\textit{bits}\[x\&(x-1)\]+1 ](./p__textit{bits}_x_=textit{bits}_x_&_x-1__+1_.png) 。

遍历从 *1* 到 ![\textit{num} ](./p__textit{num}_.png)  的每个正整数 *i*，计算 ![\textit{bits} ](./p__textit{bits}_.png)  的值。最终得到的数组 ![\textit{bits} ](./p__textit{bits}_.png)  即为答案。

```Java [sol4-Java]
class Solution {
    public int[] countBits(int num) {
        int[] bits = new int[num + 1];
        for (int i = 1; i <= num; i++) {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        return bits;
    }
}
```

```JavaScript [sol4-JavaScript]
var countBits = function(num) {
    const bits = new Array(num + 1).fill(0);
    for (let i = 1; i <= num; i++) {
        bits[i] = bits[i & (i - 1)] + 1;
    }
    return bits;
};
```

```go [sol4-Golang]
func countBits(num int) []int {
    bits := make([]int, num+1)
    for i := 1; i <= num; i++ {
        bits[i] = bits[i&(i-1)] + 1
    }
    return bits
}
```

```Python [sol4-Python3]
class Solution:
    def countBits(self, num: int) -> List[int]:
        bits = [0]
        for i in range(1, num + 1):
            bits.append(bits[i & (i - 1)] + 1)
        return bits
```

```C++ [sol4-C++]
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        for (int i = 1; i <= num; i++) {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        return bits;
    }
};
```

```C [sol4-C]
int* countBits(int num, int* returnSize) {
    int* bits = malloc(sizeof(int) * (num + 1));
    *returnSize = num + 1;
    bits[0] = 0;
    for (int i = 1; i <= num; i++) {
        bits[i] = bits[i & (i - 1)] + 1;
    }
    return bits;
}
```

**复杂度分析**

- 时间复杂度：![O(\textit{num}) ](./p__O_textit{num}__.png) 。对于每个数，只需要 *O(1)* 的时间计算「一比特数」。

- 空间复杂度：*O(1)*。除了返回的数组以外，空间复杂度为常数。