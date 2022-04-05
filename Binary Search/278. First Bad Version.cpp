// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1,right=n,middle=left+(right-left)/2;
        if(n==1){
            return true;
        }
        else
        {
            while(left<right){
                if(isBadVersion(left)==true && isBadVersion(right)==true)                       return left;
                else
                    if(isBadVersion(middle)==true){
                        right=middle;
                        middle=middle=left+(right-left)/2;
                    }
                else
                    if(isBadVersion(middle)==false && isBadVersion(left)==false){
                        left=middle+1;
                        middle=middle=left+(right-left)/2;
                    }
            }
         }
        return left;
    }
};