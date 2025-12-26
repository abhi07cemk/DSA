class Solution {
    public int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int rem = x % 10;

            // Check for overflow before multiplying
            if (rev > Integer.MAX_VALUE / 10 || rev < Integer.MIN_VALUE / 10) {
                return 0;  // return 0 in case of overflow
            }

            rev = rev * 10 + rem;
            x = x / 10;
        }
        return rev;
    }
}
