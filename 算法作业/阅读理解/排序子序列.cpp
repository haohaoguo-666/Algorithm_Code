#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr;
        arr.resize(n);
        for(int i = 0; i < n;++i)
        {
            cin >> arr[i];
        }
        int ret = 0;
        int i = 0;
        while(i < n)
        {
            if(arr[i] < arr[i + 1])
            {//非递减序列
                    while(i < n && arr[i] <= arr[i + 1])
                    ++i;
                ++ret;//找到一个非递减序列
                ++i;    
            }
            else if(arr[i] > arr[i + 1])
            {//非递增序列
                    while(i < n && arr[i] >= arr[i+1])
                    ++i;
                ++ret;//找到一个非递增序列
                ++i;
            }
            else
            {
                ++i;
            }
        }
        cout << ret << endl;
        
    }
}
// 64 位输出请用 printf("%lld")