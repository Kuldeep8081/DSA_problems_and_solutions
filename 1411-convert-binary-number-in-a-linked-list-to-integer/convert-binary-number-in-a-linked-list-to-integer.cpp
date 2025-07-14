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
    int getDecimalValue(ListNode* head) {
        
        int len=0;

        auto temp=head;

        while(temp){
            len++;
            temp=temp->next;
        }

        int ans=0;

        while(head){
            ans+=head->val*(pow(2,len-1));
            head=head->next;
            len--;
        }

        return ans;
    }
};