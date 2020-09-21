/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <string_view>

using namespace std;
class Solution {
    bool isPalindrome(const string_view &s) {
        if (s.empty()) {
            return true;
        }
        size_t i = 0;
        size_t j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string_view sv(s);
        int moveSize = sv.size();
        while (moveSize >= 0) {
            for (int i = 0, j = sv.size() - moveSize; i <= j; ++i) {
                auto subSv = sv.substr(i, moveSize);
                bool b = isPalindrome(subSv);
                if (b) {
                    return s.substr(i, moveSize);
                }
            }
            --moveSize;
        }
        return string();
    }
};

int main()
{
    auto ans = Solution().longestPalindrome("");
    cout << ans << endl;
    return 0;
}