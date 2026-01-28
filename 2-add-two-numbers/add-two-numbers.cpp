class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (l1 != NULL || l2 != NULL || carry != 0)
        {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode* temp = new ListNode(sum % 10);

            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }

            carry = sum / 10;
        }

        return head;
    }
};
