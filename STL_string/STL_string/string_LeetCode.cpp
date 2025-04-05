#include<iostream>
using namespace std;


// 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
class Solution1 {
public:
    int firstUniqChar(string s) {
        // 构建一个映射数组
        int count[26] = { 0 };
        for (auto ch : s)
        {
            count[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            // 找到原字符串里的每个字符对应位置，并从映射数组中找到它的重复情况
            if (count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

// 反转字符串
// 给你一个字符串 s ，根据下述规则反转字符串：
//所有非英文字母保留在原有位置。
//所有英文字母（小写或大写）位置反转。
//返回反转后的s

class Solution2 {
public:
    bool IsChar(char s)
    {
        if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string reverseOnlyLetters(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !IsChar(s[begin]))
            {
                ++begin;
            }
            while (begin < end && !IsChar(s[end]))
            {
                --end;
            }
            swap(s[begin++], s[end--]);
        }
        return s;
    }
};


// 验证回文字符串
//给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。
class Solution3 {
public:
    bool IsCharOrNumber(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return true;
        else
            return false;
    }
    bool isPalindrome(string s) {
        // 将字符窗中的所有大写字母转成小写
        for (auto& ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')
                ch += 32;
        }
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && !IsCharOrNumber(s[begin]))
            {
                begin++;
            }
            while (begin < end && !IsCharOrNumber(s[end]))
            {
                end--;
            }
            if (s[begin] == s[end])
            {
                begin++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
};

//字符串相加
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

class Solution4 {
public:
    string addStrings(string num1, string num2) {
        string str;
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int next = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = 0, val2 = 0;
            if (end1 >= 0)
                val1 = num1[end1] - '0';
            if (end2 >= 0)
                val2 = num2[end2] - '0';

            int ret = val1 + val2 + next;
            if (ret > 9)
            {
                ret -= 10;
                next = 1;
            }
            else
            {
                next = 0;
            }
            str += (ret + '0');

            //str.insert(str.begin(),ret+'0');

            end1--;
            end2--;
        }
        if (next == 1)
        {
            str += '1';
            //str.insert(str.begin(),'1');
            // 字符串本质上就是数组，而数组的头插需要将数组中的所有元素进行移动
            // 所以可以采取尾插加逆置的操作进行降低时间复杂度
        }

        reverse(str.begin(), str.end());
        return str;
    }
};

// 字符串相乘
// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
class Solution5 {
public:
    string addStrings(string num1, string num2) {
        string str;
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int next = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = 0, val2 = 0;
            if (end1 >= 0)
                val1 = num1[end1] - '0';
            if (end2 >= 0)
                val2 = num2[end2] - '0';

            int ret = val1 + val2 + next;
            if (ret > 9)
            {
                ret -= 10;
                next = 1;
            }
            else
            {
                next = 0;
            }
            str += (ret + '0');

            //str.insert(str.begin(),ret+'0');

            end1--;
            end2--;
        }
        if (next == 1)
        {
            str += '1';
            //str.insert(str.begin(),'1');
            // 字符串本质上就是数组，而数组的头插需要将数组中的所有元素进行移动
            // 所以可以采取尾插加逆置的操作进行降低时间复杂度
        }

        reverse(str.begin(), str.end());
        return str;
    }
    string multiply(string num1, string num2) {
        string count("0");
        string one("1");
        string ret("0");
        while (count != num2)
        {
            count = addStrings(count, one);
            ret = addStrings(ret, num1);
        }
        return ret;
    }
};