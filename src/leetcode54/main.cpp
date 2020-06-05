/*
    给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

    示例 1:

    输入:
    [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
    ]
    输出: [1,2,3,6,9,8,7,4,5]
    示例 2:

    输入:
    [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9,10,11,12]
    ]
    输出: [1,2,3,4,8,12,11,10,9,5,6,7]

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/spiral-matrix
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;
        int size = (rowEnd + 1) * (colEnd + 1);
        while (true) {
            if (colBegin <= colEnd) {
                for (auto i = colBegin; i <= colEnd; ++i) {
                    ans.push_back(matrix[rowBegin][i]);
                    --size;
                }
                rowBegin++;
            }

            if (size == 0) {
                break;
            }

            if (rowBegin <= rowEnd) {
                for (auto i = rowBegin; i <= rowEnd; ++i) {
                    ans.push_back(matrix[i][colEnd]);
                    --size;
                }
                colEnd--;
            }

            if (size == 0) {
                break;
            }

            if (colEnd >= colBegin) {
                for (auto i = colEnd; i >= colBegin; --i) {
                    ans.push_back(matrix[rowEnd][i]);
                    --size;
                }
                rowEnd--;
            }

            if (size == 0) {
                break;
            }

            if (rowEnd >= rowBegin) {
                for (auto i = rowEnd; i >= rowBegin; --i) {
                    ans.push_back(matrix[i][colBegin]);
                    --size;
                }
                colBegin++;
            }

            if (size == 0) {
                break;
            }
        }
        
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10,11,12},
        {13,14,15,16}
    };
    auto ans = Solution().spiralOrder(matrix);
    for (auto num: ans) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
