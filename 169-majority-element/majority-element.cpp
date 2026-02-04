class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             int count = 0;

//             for (int j = 0; j < n; j++) {
//                 if (nums[i] == nums[j]) {
//                     count++;
//                 }
//             }

//             if (count > n / 2) {
//                 return nums[i];
//             }
//         }
//         return -1; // will never be reached as majority element always exists
//     }
// };
