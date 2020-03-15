#include <cstddef>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL, *iter = NULL;
        int rep = 0;
        
        while(l1 || l2 || rep) {
            if(l1) {
                rep += l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                rep += l2->val;
                l2 = l2->next;
            }

            ListNode* newNode = new ListNode(rep%10);
            rep /= 10;

            if(!res) res = newNode;
            else iter->next = newNode;
            iter = newNode;
        }
        
        return res;
    }
};

int main() {
    Solution s;
    
    ListNode* list = new ListNode(2);
    list->next = new ListNode(4);
    list->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);
    
    ListNode* l3  = new ListNode(5);
    ListNode* l4  = new ListNode(5);

    ListNode* res = s.addTwoNumbers(list, list2);

    while(res != NULL) {
        std::cout<<res->val;
        res = res->next;
    }
    return 0;
}