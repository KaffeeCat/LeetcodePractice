#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <unordered_set> // http://www.cplusplus.com/reference/unordered_set/unordered_set/count/
#include <algorithm>
#include <math.h>
using namespace std;

// Print vector 
template <typename T>
void display(const vector<T>& vec)
{
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

template <typename T>
void display(const vector<vector<T>>& vec)
{
    for (auto it = vec.cbegin(); it != vec.cend(); ++it)
        display(*it);
}

template <typename T>
void swap(T* a, T* b)
{
    T* c = a;
    a = b;
    b = c;
}

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};
