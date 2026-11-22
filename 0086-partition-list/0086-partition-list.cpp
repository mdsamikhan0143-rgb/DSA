class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);

        ListNode* p1 = small;
        ListNode* p2 = large;

        while(head != NULL) {

            if(head->val < x) {
                p1->next = head;
                p1 = p1->next;
            }
            else {
                p2->next = head;
                p2 = p2->next;
            }

            head = head->next;
        }

        // Connect both lists
        p2->next = NULL;
        p1->next = large->next;

        return small->next;
    }
};