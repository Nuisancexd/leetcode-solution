#include <iostream>
//Given the head of a linked list, remove the nth node from the end of the list and return its head.

 struct ListNode
 {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* sz = head;
        int size = 0;
        while (sz != NULL)
        {
            size++;
            sz = sz->next;
        }
        if (size == 1)
        {
            return head = NULL;
        }
        if (size == n)
        {
            head = head->next;
            return head;
        }
        int i = 1;
        while (temp && i <= size - n)
        {
            i++;
            prev = temp;
            temp = temp->next;
        }
        if (prev)
        {
            prev->next = temp->next;
        }
        delete(temp);
        return head;
    }
};