class Solution {
public:
    bool isIncreasing(vector<int>& nums, int l, int r) {
        for (int i = l; i < r; i++) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }

    bool isDecreasing(vector<int>& nums, int l, int r) {
        for (int i = l; i < r; i++) {
            if (nums[i] <= nums[i + 1])
                return false;
        }
        return true;
    }

    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        // try all p and q
        for (int p = 1; p <= n - 3; p++) {
            for (int q = p + 1; q <= n - 2; q++) {
                if (isIncreasing(nums, 0, p) &&
                    isDecreasing(nums, p, q) &&
                    isIncreasing(nums, q, n - 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
