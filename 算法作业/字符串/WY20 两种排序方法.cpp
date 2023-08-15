//https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> nums;
    nums.resize(n);
    for(int i = 0;i < n;i++)
    {
        cin >> nums[i];
    }
    bool length = true;
    bool lexico = true;

    for(int i = 0;i < n - 1;i++)
    {
        if(nums[i].size() > nums[i+1].size())
            length = false;
        if(nums[i] > nums[i+1])
            lexico = false;
    }

    if(length && lexico)
        cout << "both" << endl;
    else if(length)
        cout << "lengths" << endl;
    else if(lexico)
        cout << "lexicographically" << endl;
    else 
        cout << "none" << endl;
}
// 64 位输出请用 printf("%lld")