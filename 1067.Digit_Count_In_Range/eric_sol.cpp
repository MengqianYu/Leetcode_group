/*
 * @lc app=leetcode id=1067 lang=cpp
 *
 * [1067] Digit Count in Range
 *
 * https://leetcode.com/problems/digit-count-in-range/description/
 *
 * algorithms
 * Hard (37.86%)
 * Likes:    18
 * Dislikes: 3
 * Total Accepted:    773
 * Total Submissions: 2K
 * Testcase Example:  '1\n1\n13'
 *
 * Given an integer d between 0 and 9, and two positive integers low and high
 * as lower and upper bounds, respectively. Return the number of times that d
 * occurs as a digit in all integers between low and high, including the bounds
 * low and high.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: d = 1, low = 1, high = 13
 * Output: 6
 * Explanation: 
 * The digit d=1 occurs 6 times in 1,10,11,12,13. Note that the digit d=1
 * occurs twice in the number 11.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: d = 3, low = 100, high = 250
 * Output: 35
 * Explanation: 
 * The digit d=3 occurs 35 times in 103,113,123,130,131,...,238,239,243.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= d <= 9
 * 1 <= low <= high <= 2×10^8
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int digitsCount(int d, int low, int high)
    {
        return count(d, high) - count(d, low - 1);
    }
    int count(int d, int n)
    {
        if (n == -1)
            return 0;
        int total = 0;
        if (d)
        {
            for (int num = 1; num <= n; num *= 10)
            {
                int base = num * 10;
                total += (n / base) * num; // q: 1, 10, 100....
                // remainder need to be >= than d * num
                total += min(num, max(n % base - d * num + 1, 0));
            }
        }
        // d == 0
        else
        {
            for (int num = 1; num <= n; num *= 10)
            {
                int base = num * 10;
                total += (n / base) * num;
                if (n / base > 0)
                {
                    total -= num; // delete numbers like 0xxxx 
                    total += min(n % base + 1, num);
                }
            }
        }

        return total;
    }
};
// @lc code=end
