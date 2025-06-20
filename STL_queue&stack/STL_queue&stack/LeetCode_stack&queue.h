#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    // �沨�����ʽ��ֵ/��׺���ʽ
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto str : tokens)
        {
            // 1���������
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
            // 2��ȡ����ջ
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
    // ��֤�Ƿ�Ϊ�Ϸ���ջ��ջ���ж�
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

        // �������ջ��ģ��������Ϸ�����ôջ��һ����������û�г�ջ
        return st.empty();
    }
    //�����еĵ�K�����Ԫ��
    //    ������������ nums ������ k���뷵�������е� k ������Ԫ�ء�
    //    ��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
    //    �������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣
    int findKthLargest(vector<int>& nums, int k) {
        // ʱ�临�Ӷ�O(NlogN)
        // �ռ临�Ӷ�O(N)
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

        // ʱ�临�Ӷ�O(NlogN)
        // �ռ临�Ӷ�O(1)
        // sort(nums.begin(),nums.end());   // ����
        // return nums[nums.size() -k];

        // ����k������С��
        // ʱ�临�Ӷ�O(NlogK)
        // �ռ临�Ӷ�O(K)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (size_t i = 0; i < k; i++)
        {
            minHeap.push(nums[i]);
        }
        // ��������˱���k����������Сֵ�����Ԫ�أ��ͽ��Ѷ�Ԫ��ɾ������������������
        // ����������ʣ������һ����nums�е�ǰk���������
        // ��ô��k�����ݾ��Ƕ�����С���ݣ�Ҳ���ǶѶ�Ԫ��
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

// ��Сջ����
// �������һ����Сջ ���ṩ push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
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