/*
 * @lc app=leetcode id=927 lang=cpp
 *
 * [927] Three Equal Parts
 *
 * https://leetcode.com/problems/three-equal-parts/description/
 *
 * algorithms
 * Hard (30.87%)
 * Likes:    116
 * Dislikes: 41
 * Total Accepted:    4.9K
 * Total Submissions: 15.6K
 * Testcase Example:  '[1,0,1,0,1]'
 *
 * Given an array A of 0s and 1s, divide the array into 3 non-empty parts such
 * that all of these parts represent the same binary value.
 * 
 * If it is possible, return any [i, j] with i+1 < j, such that:
 * 
 * 
 * A[0], A[1], ..., A[i] is the first part;
 * A[i+1], A[i+2], ..., A[j-1] is the second part, and
 * A[j], A[j+1], ..., A[A.length - 1] is the third part.
 * All three parts have equal binary value.
 * 
 * 
 * If it is not possible, return [-1, -1].
 * 
 * Note that the entire part is used when considering what binary value it
 * represents.  For example, [1,1,0] represents 6 in decimal, not 3.  Also,
 * leading zeros are allowed, so [0,1,1] and [1,1] represent the same
 * value.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,1,0,1]
 * Output: [0,3]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,0,1,1]
 * Output: [-1,-1]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 30000
 * A[i] == 0 or A[i] == 1
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &A)
    {
        int n = A.size();
        int ones = count(begin(A), end(A), 1);
        if (ones == 0)
        {
            return {0, 2};
        }
        if (ones % 3)
        {
            return {-1, -1};
        }
        ones /= 3;
        int count = 0;
        // find index of first 1 of third string
        int index_of_first_1_third = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (A[i])
            {
                ++count;
            }
            if (count == ones)
            {
                index_of_first_1_third = i;
                break;
            }
        }
        int pos1 = findEndIndex(A, 0, index_of_first_1_third);
        if (pos1 < 0)
            return {-1, -1};
        int pos2 = findEndIndex(A, pos1 + 1, index_of_first_1_third);
        if (pos2 < 0)
            return {-1, -1};
        return {pos1, pos2 + 1};
    }

    int findEndIndex(vector<int> &A, int left, int right)
    {
        while (A[left] == 0)
            ++left;
        while (right < A.size())
        {
            if (A[left] != A[right])
                return -1;
            left++;
            right++;
        }
        return left - 1;
    }
};
// @lc code=end
