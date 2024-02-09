#include <vector>
using namespace std;
// 输入序列单调，可用相向双指针

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator head = numbers.begin();
        vector<int>::iterator tail = numbers.end() -1;
        while (*head + *tail != target) {
            if (*head + *tail > target) {
                tail--;
            } else if (*head + *tail < target) {
                head++;
            }
        }
        vector<int> res;
        res.push_back(head-numbers.begin()+1);
        res.push_back(tail-numbers.begin()+1);
        return res;
    }
};