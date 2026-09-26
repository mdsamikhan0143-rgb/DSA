class Solution {
public:
    int countsubarrys(vector<int>& nums, int k){
        int subarrys = 1 ;
        long long currentSum = 0;
    for(int num : nums){
        if (currentSum + num > k){
            subarrys++;
            currentSum = num; 
        }else{
            currentSum += num;
      }
    }
    return subarrys;
  }

  int splitArray(vector<int>& nums, int k){
    int low = *max_element(nums.begin(), nums.end());
    int  high = 0 ;

    for(int num : nums ){
         high += num;
    }
    while (low <= high){
        long  long mid = (high + low)/2;
       if (countsubarrys( nums, mid)<= k){
            high = mid -1 ;
       }
       else {
            low = mid  +1 ;
       }
    }
    return low ;
  }
};