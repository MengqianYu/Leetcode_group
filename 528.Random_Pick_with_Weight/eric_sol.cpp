/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 *
 * https://leetcode.com/problems/random-pick-with-weight/description/
 *
 * algorithms
 * Medium (42.94%)
 * Likes:    365
 * Dislikes: 676
 * Total Accepted:    39K
 * Total Submissions: 90.7K
 * Testcase Example:  '["Solution", "pickIndex"]\n[[[1]], []]'
 *
 * Given an array w of positive integers, where w[i] describes the weight of
 * index i, write a function pickIndex which randomly picks an index in
 * proportion to its weight.
 * 
 * Note:
 * 
 * 
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex will be called at most 10000 times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output: [null,0]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * Output: [null,0,1,1,1,0]
 * 
 * 
 * Explanation of Input Syntax:
 * 
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has one argument, the array w. pickIndex has no
 * arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 * 
 */

// @lc code=start
class Solution
{
public:
    Solution(vector<int> &w)
    {
        partial_sum(begin(w), end(w), back_inserter(weights));
    }

    int pickIndex()
    {
        // lower_bound or uppper
        return upper_bound(begin(weights), end(weights), rand() % weights.back()) - begin(weights);
    }

private:
    vector<int> weights;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
