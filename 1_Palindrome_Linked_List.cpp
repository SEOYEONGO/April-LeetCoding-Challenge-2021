#include <iostream>
#include <deque>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    int getCnt(ListNode* head) {
        int cnt = 0;
        ListNode* p = head;
        for (; p != nullptr; p = p->next) {
            cnt++;
        }
        return cnt;
    }

    int getStop(int cnt) {
        if (cnt % 2 == 0) {
            return (cnt / 2);
        }
        else {
            return ((cnt-1)/ 2);
        }
    }
    bool isPalindrome(ListNode* head) {
        int len = getCnt(head);
        int stop = getStop(len);
        
        deque<int> deque;
        ListNode* tmp = head;

        int cnt = 0;
        while (cnt < stop) {
            deque.push_front(tmp->val);
            tmp = tmp->next;
            cnt++;
        }   // 덱에 요소 넣은거야. (원본 head부터)
        // tmp는 중간 시작점이 될 것임.
        if (len % 2 != 0) {
            tmp = tmp->next;
        }
        
        for (auto i = deque.begin(); i != deque.end(); i++) {
            if (*i != tmp->val) {
               // cout << *i << " != " << tmp->val << '\n';
                return false;
            }
            //else {
            //   // cout << *i << " == " << tmp->val << '\n';
            //}
            tmp = tmp->next;
        }
        return true;
    }
};

ListNode* insert_first(ListNode* head, int val) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->val = val;
    p->next = head;
    head = p;
    return head;

}
void print_list(ListNode* head) {
    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p->val << "->";
    }
    cout << "NULL\n";
}
int main() {
    Solution a;
    ListNode* head = nullptr;
    head = insert_first(head, 10);
    head = insert_first(head, 20);
    head = insert_first(head, 10);
    head = insert_first(head, 10);
    print_list(head);
    
    cout << a.isPalindrome(head) << '\n';
    
    return 0;
}

