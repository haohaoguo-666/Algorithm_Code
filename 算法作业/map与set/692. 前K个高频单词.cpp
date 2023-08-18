//https://leetcode.cn/problems/top-k-frequent-words/
class Solution {
public:
    struct compare
    {
        bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2)
        {
            return kv1.second > kv2.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> countMap;
        for(auto& str : words)
        {
            countMap[str]++;
        }

        vector<pair<string, int>> res(countMap.begin(), countMap.end());
        
        stable_sort(res.begin(), res.end(), compare());//稳定排序

        vector<string> ans;
        ans.resize(k);
        for(int i = 0;i < k;i++)
        {
            ans[i] = res[i].first;
        }

        return ans;
    }
};