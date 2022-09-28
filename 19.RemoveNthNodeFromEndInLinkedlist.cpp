//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return NULL;
        int size = 0;
        ListNode *curr = head;
        while(curr!=NULL){
            size++;
            curr=curr->next;
        }
        
        int count = size - n;
        int i = 0;
        curr = head;
        if(count==0){
            head = head->next;
            return head;
        }
        while(i<count){
            i++;
            curr=curr->next;
        }
        cout<<curr->val;
        if(curr->next==NULL){
            ListNode *temp = head;
            while(temp->next!=curr)
                temp = temp->next;
                temp->next = curr->next;
        }
        else{
            swap(curr->val, curr->next->val);
            curr->next = curr->next->next;
        }
            

        return head;
        
    }
};