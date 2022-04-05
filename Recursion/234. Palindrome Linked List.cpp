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
    bool isPalindrome(ListNode* head) {
        int counter = 0;
        stack<int> check;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            counter++;
        }
        temp = head;
        cout<<counter;
        for(int i=0;i<counter;i++){
            if(i<counter/2)
                check.push(temp->val);
            else
                if(i==counter/2 && counter%2==1){
                    temp = temp->next;
                    continue;
                }
            else
                if(check.top()==temp->val){
                    check.pop();
                }
            temp = temp->next;
        }
        return check.empty();   
    }
};