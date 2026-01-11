class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int total = 0;

        for (int i = 0; i < s.length(); i++) {
            int curr = mp[s[i]];

            if (i < s.length() - 1 && curr < mp[s[i + 1]]) {
                total -= curr;
            } else {
                total += curr;
            }
        }

        return total;
    }
};
