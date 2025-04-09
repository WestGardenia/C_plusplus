#include<iostream>
#include<vector>
using namespace std;

// 只出现一次的数字
class Solution {
public:
    //给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
    //你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for (auto e : nums)
        {
            // 任何相等的两个数据相异或结果是0
            // 0和任何数异或都是这个数本身 
            val ^= e;
        }
        return val;
    }
    //给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
    //你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。
    int singleNumber2(vector<int>& nums) {
        // 思路：统计出32个位，每个位合计起来1出现的次数
        //      1 的个数要么是3n——说明这个位上只有那3个相同的元素的位上的1
        //             要么是3n+1——说明这个位上有那个只出现一次的数
        int tmp[32] = { 0 };
        for (auto e : nums)
        {
            // 统计出了nums中的所有数据的32位上1的个数
            for (size_t i = 0; i < 32; i++)
            {
                int val = 1;
                if (e & (val << i))
                {
                    tmp[i]++;
                }
            }
        }
        // 找出3n+1的位，并把他们还原出来
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

    // 实现一个杨辉三角
    // 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
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

//给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
vector<int> singleNumber(vector<int>& nums) {
    int val = 0;
    for (auto e : nums)
    {
        val ^= e;
    }
    // 思路：
    // 构造两个数组
    // 将上面的val的二进制位进行拆分
    // 如果二进制数的某一位上是1
    // 那么就说明那两个只出现一次的数的位在这上面有了分歧
    // 我们可以将在这一位上是否为1将nums分成两份
    // 这样就将问题转化成只有一个数据出现一次
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


