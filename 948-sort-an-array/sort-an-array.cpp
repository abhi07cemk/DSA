class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low - 1, j = high + 1;

        while (true) {
            do { i++; } while (nums[i] < pivot);
            do { j--; } while (nums[j] > pivot);

            if (i >= j) return j;
            swap(nums[i], nums[j]);
        }
    }

    void quickSort(vector<int>& nums, int low, int high) {
        while (low < high) {
            int p = partition(nums, low, high);
            quickSort(nums, low, p);
            low = p + 1; 
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
