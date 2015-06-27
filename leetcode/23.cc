#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL)  {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  void listHeap(vector<ListNode*>& heap)
  {
    int n = heap.size();
    for (int i = 0; i < n; ++ i)
      cout << heap[i]->val << ' ';
    cout << endl;
  }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> heap;
        int n = lists.size();
        for (int i = 0; i < n; ++ i)
        {
            if (lists[i])   heap.push_back(lists[i]);
        }
        if (heap.empty())   return NULL;
        int heapsize = heap.size();
        for (int i = (heapsize - 1) / 2; i >= 0; -- i)
        {
            int ptr = i;
            while (ptr * 2 + 1 < heapsize)
            {
                int sw = ptr;
                int child = ptr * 2 + 1;
                if (child < heapsize && heap[child]->val < heap[sw]->val)
                    sw = child;
                ++ child;
                if (child < heapsize && heap[child]->val < heap[sw]->val)
                    sw = child;
                if (sw == ptr)
                    break;
                swap(heap[sw], heap[ptr]);
                ptr = sw;
            }
        }


        ListNode *ret = NULL, *tail = NULL;
        while (!heap.empty())
        {
          listHeap(heap);
            if (ret == NULL)
                ret = heap[0];
            if (tail) 
                tail->next = heap[0];
            tail = heap[0];
            heap[0] = heap[heapsize - 1];
            heap.pop_back();
            heapsize = heap.size();
            int ptr = 0;
            while (ptr * 2 + 1 < heapsize)
            {
                int sw = ptr;
                int child = ptr * 2 + 1;
                if (child < heapsize && heap[child]->val < heap[sw]->val)
                    sw = child;
                ++ child;
                if (child < heapsize && heap[child]->val < heap[sw]->val)
                    sw = child;
                if (sw != ptr)
                {
                    swap(heap[sw], heap[ptr]);
                    ptr = sw;
                }
                else
                  break;
            }
            if (tail->next)
            {
                heap.push_back(tail->next);
                heapsize = heap.size();
                int ptr = heapsize - 1;
                while (ptr > 0)
                {
                    int fa = (ptr - 1) / 2;
                    if (heap[ptr]->val < heap[fa]->val)
                    {
                        swap(heap[ptr], heap[fa]);
                        ptr = fa;
                    }
                    else
                        break;
                }
            }
        }
        return ret;
    }
};

int main()
{
  vector<ListNode*> lists;

  int n;
  cin >> n;
  for (int i = 0; i < n; ++ i)
  {
    int l;
    cin >> l;
    ListNode *head = NULL;
    ListNode *ptr = NULL;
    for (int j = 0; j < l; j ++)
    {
      int num;
      cin >> num;
      if (head == NULL)
      {
        head = new ListNode(num);
        ptr = head;
        continue;
      }
      ptr->next = new ListNode(num);
      ptr = ptr->next;
    }
    lists.push_back(head);
  }
  ListNode* ret = Solution().mergeKLists(lists);
  while (ret)
  {
    cout << ret->val << ' ';
    ret = ret->next;
  }
  return 0;
}

