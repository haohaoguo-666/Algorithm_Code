#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;//数组个数
    vector<int> arr;    
    arr.resize(n*3);
    int a = 0;
    for(int i = 0;i < 3 * n;i++)
    {
        cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());
    
    long long ans = 0;
    for(int i = 0;i < n;i++)
    {
        ans += arr[3 * n - 2 *(i + 1)];
    }

    cout << ans << endl;

}
// 64 位输出请用 printf("%lld")