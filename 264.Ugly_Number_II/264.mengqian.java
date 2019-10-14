/*Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.*/

class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++){
            int min = Math.min(dp[p2]*2, dp[p3]*3);
            min = Math.min(min, dp[p5]*5);
            if (min == dp[p2]*2){
                p2++;
            }
            if (min == dp[p3]*3){
                p3++;
            }
            if (min == dp[p5]*5){
                p5++;
            }
            dp[i] = min;
        }
        return dp[n-1];
    }
}