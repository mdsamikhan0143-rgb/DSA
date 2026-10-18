
class Solution {
public:
    char kthCharacter(int k) {
        int cnt = 0;
        
        while (k > 1) {
            int p = 1;
            while (p * 2 < k)
                p *= 2;
            
            k = k - p;
            cnt++;
        }
        
        return 'a' + cnt;
    }
};
