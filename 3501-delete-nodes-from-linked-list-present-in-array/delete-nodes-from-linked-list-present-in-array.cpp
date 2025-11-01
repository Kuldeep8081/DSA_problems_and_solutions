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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool>mp;

        for(int val : nums){
            mp[val]=true;
        }

        ListNode*prev=nullptr;
        ListNode*curr=head;

        while(curr){
            if(mp[curr->val]){
                if(prev==nullptr){
                ListNode*temp=curr->next;
                curr->next=nullptr;
                curr=temp;
                head=curr;
                }
                else{
                    ListNode*temp=curr->next;
                    curr->next=nullptr;
                    curr=temp;
                    prev->next=curr;
                }
            }else{
                prev=curr;
                curr=curr->next;
            }

        }

        return head;
    }
};