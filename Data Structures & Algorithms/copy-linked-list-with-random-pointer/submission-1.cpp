class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. Insert copied nodes
        Node* curr = head;

        while (curr) {
            Node* currNext = curr->next;

            curr->next = new Node(curr->val);
            curr->next->next = currNext;

            curr = currNext;
        }

        // 2. Copy random pointers
        curr = head;

        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // 3. Separate the two lists
        Node* newHead = head->next;
        Node* currCopy = newHead;
        curr = head;

        while (curr) {
            curr->next = curr->next->next;

            if (currCopy->next) {
                currCopy->next = currCopy->next->next;
            }

            curr = curr->next;
            currCopy = currCopy->next;
        }

        return newHead;
    }
};