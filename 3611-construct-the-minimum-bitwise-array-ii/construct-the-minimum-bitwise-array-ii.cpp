class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int p : nums) {
            // If p is 2 (only even prime), impossible
            if (p == 2) {
                ans.push_back(-1);
                continue;
            }
            
            // Count trailing 1s in p
            int k = 0;
            int temp = p;
            while (temp & 1) {
                k++;
                temp >>= 1;
            }
            
            // Minimum x
            int x = p - (1 << (k - 1));
            ans.push_back(x);
        }
        
        return ans;
    }
};
