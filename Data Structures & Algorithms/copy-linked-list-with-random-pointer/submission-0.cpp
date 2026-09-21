class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        unordered_map<Node* , Node*> mp;
        Node* prev = nullptr;
        Node* curr = head;
        Node* newHead = nullptr;

        while(curr){
            Node* temp = new Node(curr->val);
            mp[curr] = temp; // storing

            if(!newHead){
                newHead = temp;
                prev = newHead;
            }else{
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }
        // fill random pointers
        curr = head;
        Node* newCurr = newHead;

        while(curr){
            if(curr -> random == NULL){
                newCurr -> random = NULL;
            }else{
                newCurr -> random = mp[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr -> next;
        }

        return newHead;
    }
};
