/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void InsertAtTail(Node* &head, Node* &tail, int d)
    {
        Node* newNode = new Node(d);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        
        //Step1 : Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while(temp != NULL)
        {
            InsertAtTail(cloneHead, cloneTail, temp -> val);
            temp = temp -> next;
        }

        //Step2 : Mapping

        unordered_map<Node*, Node*> OldToNewNode;

        Node* OriginalNode = head;
        Node* CloneNode = cloneHead;
        while(OriginalNode != NULL && CloneNode != NULL)
        {
            OldToNewNode[OriginalNode] = CloneNode;
            OriginalNode = OriginalNode -> next;
            CloneNode = CloneNode -> next;
        }

        OriginalNode = head;
        CloneNode = cloneHead;

        while(OriginalNode != NULL)
        {
            CloneNode -> random = OldToNewNode[OriginalNode -> random];
            OriginalNode = OriginalNode -> next;
            CloneNode = CloneNode -> next;

        }
        return cloneHead;
    }
};