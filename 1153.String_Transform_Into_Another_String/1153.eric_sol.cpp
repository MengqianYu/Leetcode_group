/*
 * @lc app=leetcode id=1153 lang=cpp
 *
 * [1153] String Transforms Into Another String
 *
 * https://leetcode.com/problems/string-transforms-into-another-string/description/
 *
 * algorithms
 * Hard (31.36%)
 * Likes:    66
 * Dislikes: 10
 * Total Accepted:    2.6K
 * Total Submissions: 7.8K
 * Testcase Example:  '"aabcc"\n"ccdee"'
 *
 * Given two strings str1 and str2 of the same length, determine whether you
 * can transform str1 into str2 by doing zero or more conversions.
 * 
 * In one conversion you can convert all occurrences of one character in str1
 * to any other lowercase English character.
 * 
 * Return true if and only if you can transform str1 into str2.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "aabcc", str2 = "ccdee"
 * Output: true
 * Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that
 * the order of conversions matter.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str1 = "leetcode", str2 = "codeleet"
 * Output: false
 * Explanation: There is no way to transform str1 to str2.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= str1.length == str2.length <= 10^4
 * Both str1 and str2 contain only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool canConvert(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;
        unordered_map<char, char> mp;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (mp.find(s1[i]) != mp.end() && mp[s1[i]] != s2[i])
                return false;
            mp[s1[i]] = s2[i];
        }
        return set(s2.begin(), s2.end()).size() < 26;
    }
};
// @lc code=end
