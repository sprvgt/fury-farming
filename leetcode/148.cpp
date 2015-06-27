#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getHalf(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* ret = slow->next;
        slow->next = NULL;
        return ret;
    }
    
    ListNode *mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode *head, *tail;
        cout << l1->val << "vs" << l2->val << endl;
        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        tail = head;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        
        tail = head;
        while (tail)
        {
          cout << tail->val << ',';
          tail = tail->next;
        }
        cout << endl;

        cout << "Head = " << head->val << endl;
        return head;
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL)   return NULL;
        if (head->next == NULL) return head;
        
        ListNode *half = getHalf(head);

        cout << '(' << head->val << ',' << half->val << ')' << endl;

        sortList(head);
        sortList(half);
        
        return mergeList(head, half);
    }
};

int main()
{
  ListNode *a, *b, *c;
  a = new ListNode(3);
  b = new ListNode(2);
  c = new ListNode(4);
  a->next = b; b->next = c;
  ListNode* head = Solution().sortList(a);
  while (head)
  {
    cout << head->val << endl;
    head = head->next;
  }
  return 0;
}
