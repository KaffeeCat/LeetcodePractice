#include "../leetcode.h"

///////////////////////////////////////////////////
// 141. 环形链表
// ------------------------------------------------
// 给你一个链表的头节点 head ，判断链表中是否有环。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
// 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
// 注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
// 如果链表中存在环 ，则返回 true 。 否则，返回 false 。
// ------------------------------------------------
// 链接：https://leetcode-cn.com/problems/linked-list-cycle
///////////////////////////////////////////////////

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

// ------------------------------------------------
// 方法一：哈希表
// ------------------------------------------------
// 遍历所有节点，每次遍历到一个节点时，判断该节点此前是否被访问过。
// 时间复杂度：O(N)，其中 NN 是链表中的节点数。最坏情况下我们需要遍历每个节点一次。
// 空间复杂度：O(N)，其中 NN 是链表中的节点数。主要为哈希表的开销，最坏情况下我们需要将每个节点插入到哈希表中一次。
bool hasCycle(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    unordered_set<ListNode*> seen;
    while (head != nullptr)
    {
        if (seen.count(head)) // 是否已经见过该节点？
            return true;

        seen.insert(head);
        head = head->next;
    }
    return false;
}

// ------------------------------------------------
// 方法二：快慢指针
// ------------------------------------------------
// 定义两个指针，一快一满。慢指针每次只移动一步，而快指针每次移动两步。
// 初始时，慢指针在位置 head，而快指针在位置 head.next。
// 这样一来，如果在移动的过程中，快指针反过来追上慢指针，就说明该链表为环形链表。否则快指针将到达链表尾部，该链表不为环形链表。
// 时间复杂度：O(N)，其中 N 是链表中的节点数
// 空间复杂度：O(1)，我们只使用了两个指针的额外空间。
bool hasCycle2(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr) // fast指针遍历到链表末尾，无环
            return false;

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main(int argc, char** argv)
{
    ListNode a(1), b(2), c(3), d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &a;
    cout << hasCycle(&a) << endl;
    return 0;
}