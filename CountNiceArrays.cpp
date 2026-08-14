#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += (nums[right] % 2);

            while (sum > k) {
                sum -= (nums[left] % 2);
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 2, 1, 1};
    int goal = 3;

    cout << sol.numSubarraysWithSum(nums, goal) << endl;

    return 0;
}