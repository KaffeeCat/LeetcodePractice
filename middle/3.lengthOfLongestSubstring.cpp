#include "../leetcode.h"

///////////////////////////////////////////////////
// 3. 无重复字符的最长子串
// ------------------------------------------------
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// ------------------------------------------------
// 示例：
// 输入: s = "abcabcbb"
// 输出: 3 
// ------------------------------------------------
// 链接：
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-dong-chuang-kou-by-powcai/
///////////////////////////////////////////////////

#include <unordered_set>

int lengthOfLongestSubstring(string s) 
{
    int n = s.size();
    int maxLen = 0;
    int left = 0;

    // 解体思路：滑动窗口
    unordered_set<char> lookup;
    for (int i = 0; i < n; ++i)
    {
        // 是否遇到重复元素？
        while (lookup.find(s[i]) != lookup.end())
        {
            lookup.erase(s[left]);
            left++;
        }

        maxLen = max(maxLen, i-left+1); // 如果没有遇到，则长度+1
        lookup.insert(s[i]);
    }

    return maxLen;
}

int main(int argc, char** argv)
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}