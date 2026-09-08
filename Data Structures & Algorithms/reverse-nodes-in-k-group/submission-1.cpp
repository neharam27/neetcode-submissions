class Solution {
public:

    ListNode* reverse(ListNode* head, int k) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(k--) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;

            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;

        for(int i = 0; i < k; i++) {

            if(temp == nullptr) {
                return head;
            }

            temp = temp->next;
        }

        ListNode* newHead = reverse(head, k);

        head->next = reverseKGroup(temp, k);

        return newHead;
    }
};