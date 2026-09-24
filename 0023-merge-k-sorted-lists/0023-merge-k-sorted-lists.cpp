class Solution {
public:
    ListNode* mergeTwo(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return nullptr;

        while (k > 1) {
            int write = 0;

            for (int i = 0; i < k; i += 2) {
                ListNode* a = lists[i];
                ListNode* b = (i + 1 < k) ? lists[i + 1] : nullptr;

                lists[write++] = mergeTwo(a, b);
            }

            k = write;
        }

        return lists[0];
    }
};