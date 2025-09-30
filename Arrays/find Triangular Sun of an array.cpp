#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for (int level_size = nums.size() - 1; level_size > 0; --level_size) {
            for (int i = 0; i < level_size; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};