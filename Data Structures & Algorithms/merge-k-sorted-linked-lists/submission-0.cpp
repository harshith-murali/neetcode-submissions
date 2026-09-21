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

class Solution {
public:
    ListNode* merge2SortedLists(ListNode* l1 , ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val <= l2->val){
            l1->next = merge2SortedLists(l1->next, l2);
            return l1;
        }else{
            l2->next = merge2SortedLists(l1, l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partitionAndMerge(vector<ListNode*>& lists, int s , int e){
        if(s == e) return lists[s];
        if(s > e){
            return nullptr;
        }
        int mid = s + (e-s)/2;
       ListNode* L1 = partitionAndMerge(lists, s , mid);
       ListNode* L2 = partitionAndMerge(lists, mid+1, e);
       return merge2SortedLists(L1, L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if(k == 0) return nullptr;

        return partitionAndMerge(lists, 0 , lists.size() - 1);
    }
};
