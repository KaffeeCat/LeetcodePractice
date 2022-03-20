#include "../leetcode.h"

///////////////////////////////////////////////////
// 223. 矩形面积
// ------------------------------------------------
// 给你 二维 平面上两个 由直线构成且边与坐标轴平行/垂直 的矩形，请你计算并返回两个矩形覆盖的总面积。
// 每个矩形由其 左下 顶点和 右上 顶点坐标表示：
// - 第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
// - 第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。
// ------------------------------------------------
// 链接：https://leetcode-cn.com/problems/rectangle-area
///////////////////////////////////////////////////

int computeArea(int ax1, int ay1, int ax2, int ay2,
                int bx1, int by1, int bx2, int by2)
{
    int area_a = (ax2-ax1) * (ay2-ay1);
    int area_b = (bx2-bx1) * (by2-by1);

    int cx1 = max(ax1, bx1);
    int cy1 = max(ay1, by1);
    int cx2 = min(ax2, bx2);
    int cy2 = min(ay2, by2);

    int area_c = 0;
    if (cx1 < cx2 && cy1 < cy2)
    {
        area_c = (cx2-cx1) * (cy2-cy1);
    }

    return area_a + area_b - area_c;
}

int main(int argc, char** argv)
{
    cout << computeArea(-3,0,3,4,0,-1,9,2) << endl;
    cout << computeArea(-2,-2,2,2,-2,-2,2,2) << endl;
    return 0;
}