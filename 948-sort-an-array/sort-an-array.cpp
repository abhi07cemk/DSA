class Solution {
public:
    void quickSort(vector<int>& nums, int low, int high)
    {
        if (low >= high) return;

        int pivot = nums[low + rand() % (high - low + 1)];
        int lt = low, gt = high, i = low;

        while (i <= gt)
        {
            if (nums[i] < pivot)
                swap(nums[i++], nums[lt++]);
            else if (nums[i] > pivot)
                swap(nums[i], nums[gt--]);
            else
                i++;
        }

        quickSort(nums, low, lt - 1);
        quickSort(nums, gt + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
