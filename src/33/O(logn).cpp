class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        if(nums.size()==0){
            return -1;
        }
        return search(nums,target,low,high);
    }
    int search(vector<int>& nums,int target,int low,int high){
        if(nums[low]==target){
            return low;
        }
        if(nums[high]==target){
            return high;
        }
        if(low==high||low==high-1){
            return -1;
        }
        int middle=(low+high)/2;
        if(target==nums[middle]){
            return middle;
        }
        if(target<nums[middle]){
            if(nums[middle]>nums[high]&&target<nums[high]){
                return search(nums,target,middle,high);
            }else{
                return search(nums,target,low,middle);
            }
        }else{
            if(nums[low]>nums[middle]&&target>nums[low]){
                return search(nums,target,low,middle);
            }else{
                return search(nums,target,middle,high);
            }
        }
    }
};