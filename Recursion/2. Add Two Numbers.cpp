class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result=new ListNode();
        ListNode *temp1=new ListNode();
        ListNode *temp2=new ListNode();
        ListNode *temp3=new ListNode();
        int digit=0;
        temp3=result;
        temp1=l1;
        temp2=l2;
        if(temp1->next==0 && temp1->val==0)
            if(temp2->next==0 && temp2->val==0)
                return l1;
        
        while(temp1!=0 || temp2!=0){
            ListNode *add=new ListNode();
            if(temp1!=0 && temp2!=0)
            add->val=temp1->val+temp2->val+digit;
            else
                if(temp1!=0)
                    add->val=temp1->val+digit;
            else
                if(temp2!=0)
                    add->val=temp2->val+digit;
            digit=0;
            if(add->val>=10){
                add->val-=10;
                digit=1;
            }
            temp3->next=add;
            temp3=temp3->next;
            if(temp1!=0)
            temp1=temp1->next;
            if(temp2!=0)
            temp2=temp2->next;
        } 
        if(temp3->val==0 || (temp1==0 && temp2==0 && digit==1)){
            ListNode *add=new ListNode();
            add->next=NULL;
            add->val=1;
            temp3->next=add;
        }
            
        return result->next;   
    }
};