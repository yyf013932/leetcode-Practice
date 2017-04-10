class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        int length = nums.size();
        vector<vector<vector<int>>> info(length);
        for (int i = 0; i < length; i++) {
            if (i == 0) {
                vector<vector<int>> v;
                vector<int> v1;
                v1.push_back(nums[i]);
                v.push_back(v1);
                info[i]=v;
            } else {
                for(auto v1:info[i-1]){
                    for(int j=0;j<=i;j++){
                        vector<int> tem=v1;
                        tem.insert(tem.begin()+j,nums[i]);
                        info[i].push_back(tem);
                    }
                }

            }
        }
        return info[length-1];
    }
};
