class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length=nums.size();
        int endIndex=-1;
        for(int j=length-1;j>0;j--){
            if(nums[j]>nums[j-1]){
                endIndex=j-1;
                break;
            }
        }
        if(endIndex>=0){
            for(int j=length-1;j>endIndex;j--){
                if(nums[j]>nums[endIndex]){
                    swap(nums[j],nums[endIndex]);
                    break;
                }
            }
        }
        endIndex++;
        int j=length-1;
        while(endIndex<j){
            swap(nums[j],nums[endIndex]);
            endIndex++;
            j--;
        }
        
    }
};