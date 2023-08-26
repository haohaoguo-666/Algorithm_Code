//https://leetcode.cn/problems/summary-ranges/description/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        if(nums.size() == 0)
            return ans;
        //queue
        queue<int> qu;
        
        
        int sub = 1;    
        for(int i = 0;i < nums.size();i++)
        {
            if(qu.empty())
            {
                qu.push(nums[i]);
            }
            else
            {
                if(qu.back() + 1 == nums[i])
                {
                    qu.push(nums[i]);
                }
                else
                {
                    if(qu.size() == 1)
                    {
                        ans.push_back(to_string(qu.front()));
                        
                    }
                    else
                    {
                        ans.push_back(to_string(qu.front()) + "->" + to_string(qu.back()));
                    }
                    qu = queue<int>();
                    qu.push(nums[i]);
                }
            }
                
        }
        if(qu.size() == 1)
        {
            ans.push_back(to_string(qu.front()));
        }
        else
        {
            ans.push_back(to_string(qu.front()) + "->" + to_string(qu.back()));
        }

        return ans;

    }
};