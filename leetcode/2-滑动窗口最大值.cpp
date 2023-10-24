#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/* 单调队列的实现 */
class MonotonicQueue {
    deque<int> maxq;
public:
    void push(int n) {
        // 将小于 n 的元素全部删除
        while (!maxq.empty() && maxq.back() < n) {
            maxq.pop_back();
        }
        // 然后将 n 加入尾部
        maxq.push_back(n);
    }
    
    int max() {
        return maxq.front();
    }
    
    void pop(int n) {
        if (n == maxq.front()) {
            maxq.pop_front();
        }
    }
};

/* 解题函数的实现 */
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    vector<int> res;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) {
            //先填满窗口的前 k - 1
            window.push(nums[i]);
        } else {
            // 窗口向前滑动，加入新数字
            window.push(nums[i]);
            // 记录当前窗口的最大值
            res.push_back(window.max());
            // 移出旧数字
            window.pop(nums[i - k + 1]);
        }
    }
    return res;
}
