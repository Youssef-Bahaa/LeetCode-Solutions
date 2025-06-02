class Solution {
public:
    bool distinct(vector<int>& nums , int idx){
        for(int i = idx ; i < nums.size(); i++){ 
            for(int j = i + 1 ; j < nums.size(); j++)
            if(nums[i] == nums[j])return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int idx = 0;
        int times = 0 ;
        while(idx < nums.size()){
            if(distinct(nums , idx))break;
            idx +=3;
            times++;
        }
        return times;
    }
};