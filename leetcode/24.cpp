#include <cstddef>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* swap = head;
        if(swap == NULL || swap->next == NULL) {
            return swap;
        }
        else {
            while(swap != NULL && swap->next != NULL) {
                int temp = swap->next->val;
                swap->next->val = swap->val;
                swap->val = temp;
                swap = swap->next->next;
            }
        }
        return head;
    }
};

int main() {
    Solution s;

    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);

    ListNode* res = s.swapPairs(list);

    while(res != NULL) {
        std::cout<<res->val;
        res = res->next;
    }
    
    return 0;
}