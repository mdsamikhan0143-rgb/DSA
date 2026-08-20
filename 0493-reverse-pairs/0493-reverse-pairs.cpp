class Solution {
public:
void merge(vector<int>&arr,int low ,int mid,int high){
        vector<int>temp;
        int left = low ;
        int  right = mid+1;
        while(left <=mid&& right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }

        }
        while(left<= mid){
        temp.push_back(arr[left]);
        left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i= low ; i<=high;i++){
            arr[i] = temp[i-low];        
        }
    
    }
     int countpairs(vector<int>&arr,int low,int mid , int high){
        int cnt = 0;
        int right = mid + 1;
        for (int i = low ;i<=mid;i++){ 
            while(right<=high&&arr[i]>2LL*arr[right]){
                right++;
            }
                cnt += right-(mid+1);
        }
        return cnt;
    }
    int Reversepairs(vector<int>&arr,int low, int high){
        if (low>=high){
            return 0;
        }
        int mid =(low + high)/2;
        int cnt=0;
        cnt+=Reversepairs(arr,low, mid);
        cnt+=Reversepairs(arr,mid+1,high);
        cnt+=countpairs(arr,low,mid,high);
        merge(arr,low,mid,high);
        return cnt;
        }
        int reversePairs(vector<int>& nums) {
         return Reversepairs(nums, 0, nums.size() - 1);
    
        }
};
