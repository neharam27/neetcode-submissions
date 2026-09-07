class Solution {
public:
    ListNode* mergetwo(ListNode* l1,ListNode* l2) {
        ListNode* dummy= new ListNode(0);
        ListNode* curr= dummy;

        while(l1!=nullptr && l2!=nullptr) {
            if(l1->val<l2->val) {
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }


            if(l1!=nullptr) {
                curr->next=l1;
            }
            else{
                curr->next=l2;
            }
        
        return dummy->next;
    }

   ListNode* mergeKLists(vector<ListNode*>& lists) {

    if(lists.empty())
        return nullptr;

    while(lists.size()>1) {

        vector<ListNode*> merged;

        for(int i=0;i<lists.size();i+=2) {

            ListNode* l1 = lists[i];
            ListNode* l2 = nullptr;

            if(i+1<lists.size())
                l2=lists[i + 1];

            merged.push_back(mergetwo(l1, l2));
        }

        lists=merged;
    }

    return lists[0];
}
};
