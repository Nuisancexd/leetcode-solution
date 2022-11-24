#include <iostream>

using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    //ListNode(int x) : val(x), next(nullptr) {}
    //ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* head;
    int size;
public:
    Solution()
    {
        head = NULL;
        size = 0;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    void insert(ListNode** node, int val)
    {
        ListNode* new_node = new ListNode;
        new_node->val = val;
        new_node->next = (*node);
        (*node) = new_node;
    }

    void printList(ListNode* node)
    {
        ListNode* curr = new ListNode;
        curr = node;
        while (curr != NULL)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
};

int main()
{
    Solution sl;

    ListNode* ans = NULL;
    ListNode* node1 = NULL;
    ListNode* node2 = NULL;

    sl.insert(&node1, 7);
    sl.insert(&node1, 4);
    sl.insert(&node1, 2);

    sl.insert(&node2, 8);
    sl.insert(&node2, 3);
    sl.insert(&node2, 3);

    ans = sl.mergeTwoLists(node1, node2);
    sl.printList(ans);

    return 0;
}