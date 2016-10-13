class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> re;
        int length=nums.size();
        for(int i=0;i<length-3;i++){
            while(i>0&&nums[i]==nums[i-1]){
                i++;
            }
            int nt=target-nums[i];
            for(int j=i+1;j<length-2;j++){
                while(j>i+1&&nums[j]==nums[j-1]){
                    j++;
                }
                int nt1=nt-nums[j];
                int si=j+1,ei=length-1;
                while(si<ei){
                    int tem=nt1-nums[si]-nums[ei];
                    if(tem==0){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[si]);
                        v.push_back(nums[ei]);
                        re.push_back(v);
                        int k=si+1;
                        while(k<ei&&nums[k]==nums[k-1]){
                            k++;
                        }
                        si=k;
                        k=ei-1;
                        while(k>si&&nums[k]==nums[k+1]){
                            k--;
                        }
                        ei=k;
                    }else if(tem>0){
                        si++;
                    }else{
                        ei--;
                    }
                }
            }
        }
        return re;
    }
};