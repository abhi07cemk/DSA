class Solution {
private:
    ListNode* getMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: find middle
        ListNode* middle = getMid(head);

        // Step 2: reverse second half
        middle->next = reverse(middle->next);

        // Step 3: compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle->next;

        while (head2 != NULL)
        {
            if (head1->val != head2->val)
                return false;

            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4: restore list
        middle->next = reverse(middle->next);

        return true;
    }
};
