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


// ��֤�����ַ���
//����һ���ַ��� s ����֤ s �Ƿ��� ���Ĵ� ��ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
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
        // ���ַ����е����д�д��ĸת��Сд
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

//�ַ������
//���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺͲ�ͬ�����ַ�����ʽ���ء�
//�㲻��ʹ���κ΃Ƚ������ڴ���������Ŀ⣨���� BigInteger���� Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��

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
            // �ַ��������Ͼ������飬�������ͷ����Ҫ�������е�����Ԫ�ؽ����ƶ�
            // ���Կ��Բ�ȡβ������õĲ������н���ʱ�临�Ӷ�
        }

        reverse(str.begin(), str.end());
        return str;
    }
};

// �ַ������
// �����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
// ע�⣺����ʹ���κ����õ� BigInteger ���ֱ�ӽ�����ת��Ϊ������
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
            // �ַ��������Ͼ������飬�������ͷ����Ҫ�������е�����Ԫ�ؽ����ƶ�
            // ���Կ��Բ�ȡβ������õĲ������н���ʱ�临�Ӷ�
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