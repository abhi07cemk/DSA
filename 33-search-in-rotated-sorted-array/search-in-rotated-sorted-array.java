class Solution {
    public int search(int[] nums, int target) {
        int pivot = findPivot(nums);

        // If no pivot, do normal binary search
        if (pivot == -1) {
            return BinarySearch(nums, target, 0, nums.length - 1);
        }

        // If pivot itself is the target
        if (nums[pivot] == target) {
            return pivot;
        }

        // If target lies in left part
        if (target >= nums[0]) {
            return BinarySearch(nums, target, 0, pivot - 1);
        }

        // Else target lies in right part
        return BinarySearch(nums, target, pivot + 1, nums.length - 1);
    }

    int findPivot(int[] arr) {
        int start = 0, end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid < end && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (mid > start && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            }
            if (arr[mid] <= arr[start]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

    int BinarySearch(int[] arr, int key, int start, int end) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (key < arr[mid]) {
                end = mid - 1;
            } else if (key > arr[mid]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
