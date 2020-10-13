/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 

限制：

0 <= 链表长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x), next(nullptr)
    {
    }
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> ret;
        if (head == nullptr) {
            return ret;
        }
        while (head != nullptr) {
            ret.push_back(head->val);
            head = head->next;
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    vector<int> nums{ 2, 3, 1, 0, 2, 5, 3 };
    ListNode *node = nullptr;
    ListNode *head = nullptr;
    for (auto num : nums) {
        if (head == nullptr) {
            head = node = new ListNode(num);
        }
        else {
            auto t     = new ListNode(num);
            node->next = t;
            node       = t;
        }
    }

    auto ans = Solution().reversePrint(head);
    std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, ", "));
    return 0;
}