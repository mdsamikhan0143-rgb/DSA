class Solution {
public:
    int smallestDivisorfind(vector<int>& arr, int div) {
         int sum = 0 ;
         for(int num : arr){
            sum +=  ceil((double)num / div);
         }
         return sum;
    }
     int smallestDivisor(vector<int>& arr,int threshold ){
        if(arr.size() > threshold) return -1 ;

        int low = 1;
        int high = *max_element(arr.begin(),arr.end());

       while(low <= high){
        int mid = (low + high)/2;
         if(smallestDivisorfind( arr, mid ) <= threshold){
            high = mid-1;
         }
         else {
             low = mid+1;
        }

     }
       return low ;

     }
};