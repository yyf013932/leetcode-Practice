class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return calMax(nums,0,nums.size()-1,0)[0];
    }
    
    int* calMax(vector<int> &nums,int startIndex,int endIndex,int type){
        int *re=new int[2];
        if(startIndex==endIndex){
            re[0]=nums[startIndex];
            re[1]=nums[startIndex];
            return re;
        }
        int middle=(startIndex+endIndex)/2;
        int *re1=calMax(nums,startIndex,middle,0);
        int *re2=calMax(nums,middle+1,endIndex,1);
        re[0]=max(max(re1[0],re2[0]),re1[1]+re2[1]);
        re[1]=INT_MIN;
        int tem=0;
        if(type==0){
            for(int i=endIndex;i>=startIndex;i--){
                tem+=nums[i];
                re[1]=(re[1]<tem)?tem:re[1];
            }
        }else{
            for(int i=startIndex;i<=endIndex;i++){
                tem+=nums[i];
                re[1]=(re[1]<tem)?tem:re[1];
            }
        }
        re[0]=max(re[0],re[1]);
        return re;
    }
};