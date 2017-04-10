class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1||n==0)
            return 0;
        int i=0,j=nums[i];
        int step=0;
        while(1){
            step++;
            if(j>=n-1)
                break;
            int tem=j;
            for(;i<=tem;i++){
                j=max(j,nums[i]+i);
            }
            
        }
        return step;
    }
};