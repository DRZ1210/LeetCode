/*************************************************************************
	> File Name: leedcode232.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月28日 星期五 11时01分05秒
 ************************************************************************/
class MyQueue {
private:
    stack<int> s1; // 输入栈
    stack<int> s2;  // 输出栈
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty()) 
        {
            while(!s1.empty()) 
            {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
        }
        int ret = s2.top();
        s2.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        int ret = this->pop();
        s2.push(ret);
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&& s2.empty();
    }
};
