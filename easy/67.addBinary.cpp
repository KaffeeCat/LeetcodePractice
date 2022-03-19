#include "../leetcode.h"

///////////////////////////////////////////////////
// 73. 矩阵置零
// ------------------------------------------------
// 给你两个二进制字符串，返回它们的和（用二进制表示）。
// 输入为 非空 字符串且只包含数字 1 和 0。
// ------------------------------------------------
// 示例：
// 输入: a = "11", b = "1"
// 输出: "100"
// 输入：输入: a = "1010", b = "1011"
// 输出: "10101"
// ------------------------------------------------
// 链接：https://leetcode-cn.com/problems/add-binary/
///////////////////////////////////////////////////

string addBinary(string a, string b)
{
    string ans;

    // 对字符串进行反转，使运算位对齐
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int n = max(a.size(), b.size());
    int carry = 0; // 进位器

    for (size_t i = 0; i < n; ++i)
    {
        // 同位相加（包含进位）
        carry += i < a.size() ? (a.at(i)=='1') : 0;
        carry += i < b.size() ? (b.at(i)=='1') : 0;

        // 对2取余，赋值与进位
        ans.push_back((carry % 2) ? '1' : '0');
        carry /= 2; // 除掉基本的01状态后，多余部分进位
    }

    if (carry) // 如果还需要进位
        ans.push_back('1');

    // 将结果反转恢复顺序
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(int argc, char** argv)
{
    cout << addBinary("1010", "1011") << endl;
    return 0;
}