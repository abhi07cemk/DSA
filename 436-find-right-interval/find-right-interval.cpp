class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {
            int minStart = INT_MAX;
            int index = -1;

            for(int j = 0; j < n; j++) {
                if(intervals[j][0] >= intervals[i][1]) {
                    if(intervals[j][0] < minStart) {
                        minStart = intervals[j][0];
                        index = j;
                    }
                }
            }
            ans[i] = index;
        }
        return ans;
    }
};
