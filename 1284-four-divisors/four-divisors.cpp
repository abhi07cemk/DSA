class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int n : nums) {
            int cnt = 0;
            int sum = 0;

            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    cnt++;
                    sum += i;

                    if (i != n / i) {
                        cnt++;
                        sum += n / i;
                    }
                }
                if (cnt > 4) break;
            }

            if (cnt == 4)
                totalSum += sum;
        }
        return totalSum;
    }
};
