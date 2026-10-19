class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
          vector<int>temp;
        solve(0,nums,temp,ans);
        return ans;
    }
    void solve(int index, vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve(index+1,nums,temp,ans);

        temp.pop_back();
        solve(index+1,nums,temp,ans);


    }
};