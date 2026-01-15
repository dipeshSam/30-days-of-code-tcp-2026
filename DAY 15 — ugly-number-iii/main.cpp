#include <iostream>

class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);

        long long low = 1, high = 2e9, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            long long count =
                mid / a + mid / b + mid / c
                - mid / ab - mid / ac - mid / bc
                + mid / abc;

            if (count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;

    std::cout << obj.nthUglyNumber(8, 2, 7, 5);


    return 0;
}