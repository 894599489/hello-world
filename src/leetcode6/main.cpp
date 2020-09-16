/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>

using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows < 2) {
            return s;
        }
        int size   = s.size();
        int column = size / (2 * numRows - 2) + 1;
        int width  = 2 * (numRows - 1);
        string ret;
        ret.resize(size);
        int count = 0;

        auto saddFunc = [&count, &ret, s, size](int index) {
            if (index < size) {
                ret[count] = s.at(index);
                count++;
            }
        };
        for (int j = 0; j < column; ++j) {
            saddFunc(j * width);
        }
        for (int i = 1; i < numRows - 1; ++i) {
            for (int j = 0; j < column; ++j) {
                saddFunc(j * width + i);
                saddFunc(j * width + width - i);
            }
        }

        for (int j = 0; j < column; ++j) {
            saddFunc(j * width + (numRows - 1));
        }
        return ret;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    int n    = 3;
    auto ans = Solution().convert(s, n);
    cout << ans << endl;
    return 0;
}