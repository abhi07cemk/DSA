class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int prod = 1;

        while(n!=0)
        {
            int digits = n%10;
            prod = prod * digits;
            sum = sum + digits;

            n /= 10;

        }
        int answer = prod  - sum;
        return answer;
    }
};