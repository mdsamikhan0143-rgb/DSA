class Solution {
public:
    long long calculateTotalHours(vector<int>& piles, int speed) {
        long long  total = 0 ;
        for (int bananas:piles){
            total += (bananas + (long long )speed -1)/speed ;
        }
        return total ;
    }
    int minEatingSpeed (vector<int>&piles,int h){
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while (low<=high){
            int mid = low + (high - low)/2 ;
            long long totalhours = calculateTotalHours(piles,mid);
        if(totalhours <= h){
                high = mid -1;
        }else{
            low = mid + 1 ;
          }
       }
       return low ;

      }
};