class Solution{
    public:
     int daysNeeded(vector<int>& weights, int capacity) {
        int days = 1 ;
        int currnentload = 0;
     for(int w : weights){
         if(currnentload + w > capacity){
            days ++;
            currnentload = w ;
         }else{
            currnentload += w ;
         }
     }
     return days;
  }

  int shipWithinDays(vector<int>& weights, int days) {
     int low = *max_element(weights.begin(),weights.end());
     int high =  0;
     for( int w : weights){
        high += w ;
     }
     while(low<=high){
        int mid = (  high + low) / 2 ;

        if(daysNeeded(weights,mid) <= days){
                high = mid -1 ;
        }else{
            low= mid +1;
        }
     }
     return low ;
  }
};