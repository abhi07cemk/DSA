/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

void reverse(ListNode* &head, ListNode* curr, ListNode* prev)
{
    //baseCase
    if(curr == NULL)
    {
        head = prev;
        return;
    }

    ListNode* forward = curr -> next;
    reverse(head, forward, curr);
    curr -> next = prev;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head,curr,prev);
        return head;

        /*if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        ListNode* Prev = NULL;
        ListNode* Curr = head;
        ListNode* forward = NULL;
        while(Curr != NULL)
        {
            forward = Curr -> next;
            Curr -> next = Prev;
            Prev = Curr;
            Curr = forward;
        }
        return Prev;*/
    }
};