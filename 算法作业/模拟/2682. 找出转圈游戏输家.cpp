//https://leetcode.cn/problems/find-the-losers-of-the-circular-game/description/
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> vis(n);
        for(int i = 0, d = k; !vis[i];d+=k)
        {
            vis[i] = true;
            i = (i + d) % n;
        }

        vector<int> ans;
        for(int i = 0;i < n;i++)
        {
            if(!vis[i])
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};