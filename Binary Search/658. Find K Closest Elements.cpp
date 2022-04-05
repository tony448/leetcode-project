class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0,right=arr.size()-1;
        int middle=0,counter=0;
        vector<int> ans;
        if(x>=arr[arr.size()-1]){
            for(int i=0;i<k;i++){
                ans.push_back(arr[arr.size()-k+i]);
            }
            return ans;
        }
        else
            if(x<=arr[0]){
                for(int i=0;i<k;i++)
                ans.push_back(arr[i]);
                return ans;
            }
        else
        while(left+1<right){
            middle=left+(right-left)/2;
            if(arr[middle]==x){
                right=middle;
                left=middle;
                break;
            }
            if(arr[middle]<x){
                left=middle;
            }
            else
                right=middle;
        }
        if(left==right && arr.size()>1){
            if(left-1>0)
                left--;
            else
                right++;
        }
        
        while(counter<k){
            if((left !=-1 && arr[right]-x>=abs(arr[left]-x)) || right==arr.size()){
                ans.push_back(arr[left]);
                if(left>=0)
                left--;
            }
            else
                if(right<arr.size() || left==-1)
            {
                ans.push_back(arr[right]);
                if(right<=arr.size()-1)
                right++;
            }
            counter++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};