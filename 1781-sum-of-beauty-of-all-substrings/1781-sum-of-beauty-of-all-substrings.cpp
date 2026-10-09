
class Solution {
public:
    int beautySum(string s) {
       int  n = s.length();
       int ans = 0;

       for(int i = 0; i < n; i++){
        int freq[30]={0};
       for(int j=i;j<n;j++){
        freq[s[j]-'a']++;
        int maxi = 0;
        int mini = INT_MAX;

         for (int k = 0; k < 26; k++) {
                if (freq[k] > 0) {
                    maxi = max(maxi, freq[k]);
                    mini = min(mini, freq[k]);
          }
       }
        ans += maxi - mini;
         }
       }
       return ans;
    }
};
