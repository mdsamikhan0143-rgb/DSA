class Solution {
public:
    int maxProduct(vector<int>&arr){
        int pre =1 ; 
        int suff = 1;
         int ANS = arr[0];
         int n = arr.size();
        for(int i  =0;i<n;i++){
            if(pre==0) pre =1;
            if(suff==0) suff=1;
        pre = pre * arr[i];
        suff = suff*arr[n-1-i];
        ANS = max(ANS,max(pre,suff));
        }
        return ANS;

    }
};