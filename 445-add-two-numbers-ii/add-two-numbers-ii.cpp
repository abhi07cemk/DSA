class Solution {
private:

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

    void insertatTail(ListNode* &head, ListNode* &tail, int val)
    {
        ListNode* temp = new ListNode();
        temp->val = val;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    ListNode* add(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while (l1 != NULL && l2 != NULL)
        {
            int sum = carry + l1->val + l2->val;
            insertatTail(ansHead, ansTail, sum % 10);
            carry = sum / 10;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            int sum = carry + l1->val;
            insertatTail(ansHead, ansTail, sum % 10);
            carry = sum / 10;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            int sum = carry + l2->val;
            insertatTail(ansHead, ansTail, sum % 10);
            carry = sum / 10;
            l2 = l2->next;
        }

        while (carry != 0)
        {
            insertatTail(ansHead, ansTail, carry % 10);
            carry /= 10;
        }

        return ansHead;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
    
        if (l1 == NULL && l2 == NULL)
            return new ListNode(0);

        // Step 1: Reverse both lists
        ListNode* first = reverse(l1);
        ListNode* second = reverse(l2);

        // Step 2: Add reversed lists
        ListNode* ans = add(first, second);

        // Step 3: Reverse result
        return reverse(ans);
    }
};
