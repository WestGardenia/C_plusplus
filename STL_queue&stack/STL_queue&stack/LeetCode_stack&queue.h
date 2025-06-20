#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    // 逆波兰表达式求值/中缀表达式
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto str : tokens)
        {
            // 1、运算操作
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch (str[0])
                {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                }
            }
            // 2、取数入栈
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
    // 验证是否为合法出栈入栈序列对
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pushi = 0;
        int popi = 0;
        while (pushi < pushed.size())
        {
            st.push(pushed[pushi++]);
            while (!st.empty() && st.top() == popped[popi])
            {
                st.pop();
                popi++;
            }
        }

        // 如果上述栈的模拟进出不合法，那么栈里一定还有数据没有出栈
        return st.empty();
    }
    //数组中的第K个最大元素
    //    给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
    //    请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
    //    你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
    int findKthLargest(vector<int>& nums, int k) {
        // 时间复杂度O(NlogN)
        // 空间复杂度O(N)
        // priority_queue<int> pq;
        // for(auto& e : nums)
        // {
        //     pq.push(e);
        // }
        // for(int i = 1;i<k;i++)
        // {
        //     pq.pop();
        // }
        // return pq.top();

        // 时间复杂度O(NlogN)
        // 空间复杂度O(1)
        // sort(nums.begin(),nums.end());   // 快排
        // return nums[nums.size() -k];

        // 建立k个数的小堆
        // 时间复杂度O(NlogK)
        // 空间复杂度O(K)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (size_t i = 0; i < k; i++)
        {
            minHeap.push(nums[i]);
        }
        // 如果遇见了比这k个数据中最小值还大的元素，就将堆顶元素删掉，并将这个数据入堆
        // 这样最后堆中剩下来的一定是nums中的前k个大的数据
        // 那么第k个数据就是堆中最小数据，也就是堆顶元素
        for (size_t i = k; i < nums.size(); i++)
        {
            if (nums[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};

// 最小栈问题
// 请你设计一个最小栈 它提供 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        _st.push(x);
        if (_min_st.empty() || _min_st.top() >= x)
            _min_st.push(x);
    }

    void pop() {
        if (_st.top() == _min_st.top())
            _min_st.pop();
        _st.pop();
    }

    int top() {
        return _st.top();
    }

    int getMin() {
        return _min_st.top();
    }
private:
    stack<int> _st;
    stack<int> _min_st;
};