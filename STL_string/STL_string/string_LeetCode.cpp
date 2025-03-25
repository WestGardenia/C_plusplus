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
