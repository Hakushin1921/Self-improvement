# Leetcode 541 反转字符串 II
https://leetcode.cn/problems/reverse-string-ii

## 方法一 按题意暴力解
按题意解，最后一部分单独判断
### 易错点
用单指针时，两指针之和等于(4 * i + 1) * k - 1
### 代码
```c
# include<cstring>

char* reverseStr(char* s, int k) {
    int t = strlen(s) / (k * 2);
    for (int i = 0; i < t; i++)
    {
        for (int j = 2 * k * i; j < (4 * i + 1) * k / 2; j++)
        {
            char tmp = s[j];
            s[j] = s[(4 * i + 1) * k - 1 - j];
            s[(4 * i + 1) * k - 1 - j] = tmp;
        }
    }
    if (strlen(s) % (2 * k) < k)
    {
        int left = 2 * k * t, right = strlen(s) - 1;
        while (left < right)
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
    else
    {
        for (int j = 2 * k * t; j < (4 * t + 1) * k / 2; j++)
        {
            char tmp = s[j];
            s[j] = s[(4 * t + 1) * k - 1 - j];
            s[(4 * t + 1) * k - 1 - j] = tmp;
        }
    }
    return s;
}
```

## 方法二 拆分区间
将原字符串按k拆分为多个区间，对每个区间遍历，在每个区间内实现反转操作。灵茶山大佬的解法。
### 易错点
最好将反转的功能拆分封装，最后一个区间右端点记得比较一下大小
### 代码
```c
#define MIN(a, b) (a < b ? a : b)
#include <concepts>
#include <cstring>

void swap(char* s, int left, int right)
{
    while (left < right)
    {
        char t = s[left];
        s[left++] = s[right];
        s[right--] = t;
    }
}

char* reverseStr(char* s, int k)
{
    int len = strlen(s);
    for (int i = 0; i < len; i += 2 * k)
    {
        swap(s, i, MIN(i + k, len) - 1);
    }
    return s;
}


```
