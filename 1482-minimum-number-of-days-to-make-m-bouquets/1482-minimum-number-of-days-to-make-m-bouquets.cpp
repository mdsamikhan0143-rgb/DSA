class Solution {
public:
    bool possible(vector<int>& arr,int day, int m, int k){
        int n = arr.size();

        int cnt = 0;

        int bouquets = 0;  

    for(int i =0 ; i < n ; i++){
        if(arr[i]<=day){
            cnt++;

        if(cnt == k){
           bouquets++;
           cnt = 0;

        }
      } else{
        cnt = 0 ;
       }
     }
     return bouquets >= m;
    }
    int minDays(vector<int>& arr,int m , int k){
        long long  total = 1ll * k * m ;

        if(total>arr.size()) return -1;

        int mini = *min_element(arr.begin(),arr.end());
        int maxi = *max_element(arr.begin(),arr.end());

        int low = mini;
        int high = maxi;
        int result = -1;

    while(low <= high){
        int mid = (low + high)/2;
    if (possible(arr,mid,m,k)){
            result = mid ;
            high = mid -1;
       }else{
        low= mid+1;
          }   
        }
      return result;     
    }
};