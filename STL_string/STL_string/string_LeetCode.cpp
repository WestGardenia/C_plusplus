#include<iostream>
using namespace std;


// ����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� -1 ��
class Solution1 {
public:
    int firstUniqChar(string s) {
        // ����һ��ӳ������
        int count[26] = { 0 };
        for (auto ch : s)
        {
            count[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            // �ҵ�ԭ�ַ������ÿ���ַ���Ӧλ�ã�����ӳ���������ҵ������ظ����
            if (count[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

// ��ת�ַ���
// ����һ���ַ��� s ��������������ת�ַ�����
//���з�Ӣ����ĸ������ԭ��λ�á�
//����Ӣ����ĸ��Сд���д��λ�÷�ת��
//���ط�ת���s

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
