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

## 方法二 双指针
