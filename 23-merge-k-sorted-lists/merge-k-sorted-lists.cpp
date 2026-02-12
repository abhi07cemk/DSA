class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> values;
        
        // Step 1: Store all values from all linked lists
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            
            while (temp != nullptr) {
                values.push_back(temp->val);
                temp = temp->next;
            }
        }
        
        // If no nodes exist
        if (values.size() == 0) {
            return nullptr;
        }
        
        // Step 2: Sort the values
        sort(values.begin(), values.end());
        
        // Step 3: Create a new sorted linked list
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        
        for (int i = 1; i < values.size(); i++) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        
        return head;
    }
};
