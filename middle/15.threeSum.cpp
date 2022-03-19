#include "../leetcode.h"

///////////////////////////////////////////////////
// 15. 三数之和
// ------------------------------------------------
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
// 请你找出所有和为 0 且不重复的三元组。
// ------------------------------------------------
// 示例：
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// ------------------------------------------------
// 链接：https://leetcode-cn.com/problems/3sum
///////////////////////////////////////////////////

vector<vector<int>> threeSum(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    // 对数组进行排序
    sort(nums.begin(), nums.end());

    // 游标游走，固定i，寻找 a+b+c=n[i]+n[j]+n[k]=0
    //    ij ►          k
    //    ▼▼            ▼
    // ┗┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┻┛
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i-1]) // ignore repeating elements
            continue;

        int k = n-1;
        int target = -nums[i];    // target = -n[i] = n[j] + n[k]

        for (int j = i+1; j < n; ++j)
        {
            if (j > i+1 && nums[j] == nums[j-1])// ignore repeating elements
                continue;

            while (j < k && nums[j] + nums[k] > target) // 游标k向左游走查值
                --k;

            if (j == k) // 游标jk相遇，没有发现，则继续下一个j的寻找
                break;

            if (nums[j] + nums[k] == target)
                ans.push_back({nums[i], nums[j], nums[k]});
        }
    }

    return ans;
}

int main(int argc, char** argv)
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    display(ans);
    return 0;
}