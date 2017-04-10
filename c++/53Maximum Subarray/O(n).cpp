class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN,tem=0,tag=0;
        for(auto num:nums){
            tem+=num;
            tag=1;
            maxSum=(maxSum<tem)?tem:maxSum;
            if(tem<0){
                tem=0;
                tag=0;
            }
        }
        maxSum=(tag&&maxSum<tem)?tem:maxSum;
        return maxSum;
    }
};