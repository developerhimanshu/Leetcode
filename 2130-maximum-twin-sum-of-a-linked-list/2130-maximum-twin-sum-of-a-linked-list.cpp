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
    int pairSum(ListNode* head) {
        stack<int>st;
        int maxSum = 0;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            temp = temp->next;
            n++;
        }
        temp = head;
        for(int i = 0; i<n; i++){
            if(i<n/2){
                st.push(temp->val);
            }
            else{
                maxSum = max(maxSum, st.top()+temp->val);
                st.pop();
            }
            temp = temp->next;
        }
        return maxSum;
    }
};