#include<iostream>
using namespace std;

class LRUCache{
public:

    class ListNode
    {
    public:
        int key, val;
        ListNode *pre, *next;
        ListNode():pre(NULL),next(NULL)   {};
        ListNode(int k, int v):key(k), val(v), pre(NULL), next(NULL)   {};
    };

    ListNode    *head, *tail;
    int cnt, cap;

    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        cnt = 0;
        cap = capacity;
    }
    
    ListNode* getptr(int key) {
        ListNode* ptr = head;
        while (ptr)
        {
            if (ptr->key == key)    break;
            ptr = ptr->next;
        }
        if (ptr && ptr != tail)
        {
            if (ptr == head)  head = ptr->next;
            if (ptr->pre)   ptr->pre->next = ptr->next;
            if (ptr->next)  ptr->next->pre = ptr->pre;
            ptr->pre = tail;
            ptr->next = NULL;
            tail->next = ptr;
            tail = ptr;
        }
        return ptr;
    }
    
    int get(int key)    {
        ListNode* ret = getptr(key);
        if (ret)    return ret->val;    else    return -1;
    }
    
    void set(int key, int value) {
        cout << "set " << key << endl;
        cout << get(2) << endl;
        if (head) cout << head->key << endl;
        if (tail) cout << tail->key << endl;

        if (cap == 0)  return;
        
        ListNode*   node = getptr(key);
        if (node)
        {
            node->val = value;
            return;
        }

        node = new ListNode(key, value);
        if (cnt == cap)
        {
            if (head == tail)
            {
                head = NULL; tail = NULL;
            }
            else
            {
                ListNode* tmp = head;
                head = head->next;
                head->pre == NULL;
                delete tmp;
            }
        }
        else
            cnt ++;
        if (tail)
        {
            tail->next = node;
            node->pre = tail;
            tail = node;
        }
        else
        {
            tail = node;
            head = node;
        }

    }
};

int main()
{
  LRUCache cache(2);

  cache.set(2, 1);
  cache.set(1, 1);
  cout << cache.get(2) << endl;
  cout << cache.get(2) << endl;
  cache.set(4, 1);
  cout << cache.get(2) << endl;
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;
  return 0;
}
