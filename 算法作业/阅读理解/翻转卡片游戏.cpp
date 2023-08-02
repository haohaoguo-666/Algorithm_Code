class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        //通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。
        //关键是一个背面数字固定时，可以翻转卡片组成任意的正面数组，所以如果正反面相同的数字会导致一些数字无法符合条件。
        unordered_set<int> forbidden;
        for(int i = 0;i < fronts.size();i++)
        {
            if(fronts[i] == backs[i])
            {//真反面相同的数字不能作为最小数字（关键点）
                forbidden.insert(fronts[i]);
            }
        }
        int ans = INT_MAX;
        for(auto i : fronts)
        {
            if(!forbidden.count(i)) ans = ans < i ? ans : i;
        }
        for(auto i : backs)
        {
            if(!forbidden.count(i)) ans = ans < i ? ans : i;
        }
        return ans == INT_MAX ? 0 : ans;
    }
    
};