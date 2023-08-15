//https://www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId=85&&tqId=29840&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int W, H, res = 0;
    cin >> W >> H;
    vector<vector<int>> nums;
    nums.resize(W);
    for(auto& e : nums)
    {
        e.resize(H, 1);
    }

    for(int i = 0;i < W;++i)
    {
        for(int j = 0;j < H;++j)
        {
            if(nums[i][j] == 1)
            {
                res++;

                if(i + 2 < W)
                    nums[i+2][j] = 0;
                
                if(j + 2 < H)
                    nums[i][j+2] = 0;
            }
        }
    }

    cout << res << endl;
}
// 64 位输出请用 printf("%lld")