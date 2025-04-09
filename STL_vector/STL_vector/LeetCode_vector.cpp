#include<iostream>
#include<vector>
using namespace std;

// ֻ����һ�ε�����
class Solution {
public:
    //����һ�� �ǿ� �������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
    //�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨����������⣬�Ҹ��㷨ֻʹ�ó�������ռ䡣
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for (auto e : nums)
        {
            // �κ���ȵ������������������0
            // 0���κ����������������� 
            val ^= e;
        }
        return val;
    }
    //����һ���������� nums ����ĳ��Ԫ�ؽ����� һ�� �⣬����ÿ��Ԫ�ض�ǡ���� ���� �������ҳ��������Ǹ�ֻ������һ�ε�Ԫ�ء�
    //�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨��ʹ�ó������ռ�����������⡣
    int singleNumber2(vector<int>& nums) {
        // ˼·��ͳ�Ƴ�32��λ��ÿ��λ�ϼ�����1���ֵĴ���
        //      1 �ĸ���Ҫô��3n����˵�����λ��ֻ����3����ͬ��Ԫ�ص�λ�ϵ�1
        //             Ҫô��3n+1����˵�����λ�����Ǹ�ֻ����һ�ε���
        int tmp[32] = { 0 };
        for (auto e : nums)
        {
            // ͳ�Ƴ���nums�е��������ݵ�32λ��1�ĸ���
            for (size_t i = 0; i < 32; i++)
            {
                int val = 1;
                if (e & (val << i))
                {
                    tmp[i]++;
                }
            }
        }
        // �ҳ�3n+1��λ���������ǻ�ԭ����
        int value = 0;
        for (size_t i = 0; i < 32; i++)
        {
            if (tmp[i] % 3 == 1)
            {
                value = (1 << i) | value;
            }

        }
        return value;
    }

    // ʵ��һ���������
    // ����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows);
        for (size_t i = 0; i < numRows; i++)
        {
            vv[i].resize(i + 1);
            vv[i][0] = 1;
            vv[i][i] = 1;
        }
        for (size_t i = 0; i < numRows; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (vv[i][j] != 1)
                {
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
                }
            }
        }
        return vv;
    }
};

//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�����԰� ����˳�� ���ش𰸡�
//�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨�ҽ�ʹ�ó�������ռ�����������⡣
vector<int> singleNumber(vector<int>& nums) {
    int val = 0;
    for (auto e : nums)
    {
        val ^= e;
    }
    // ˼·��
    // ������������
    // �������val�Ķ�����λ���в��
    // �������������ĳһλ����1
    // ��ô��˵��������ֻ����һ�ε�����λ�����������˷���
    // ���ǿ��Խ�����һλ���Ƿ�Ϊ1��nums�ֳ�����
    // �����ͽ�����ת����ֻ��һ�����ݳ���һ��
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        if (val & (1 << i))
            break;
    }

    int num1 = 0, num2 = 0;
    for (auto e : nums)
    {
        if (e & (1 << i))
        {
            num1 ^= e;
        }
        else
        {
            num2 ^= e;
        }
    }


    vector<int> res;
    res.push_back(num1);
    res.push_back(num2);


    return res;
}


