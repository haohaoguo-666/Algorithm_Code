//https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include <iostream>
#include<vector>
using namespace std;
int GetMax(int a, int b) { //得到两个数的最大值
    return (a) > (b) ? (a) : (b);
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (size_t i = 0; i < size; ++i)
        cin >> nums[i];
    int Sum = nums[0]; //临时最大值
    int MAX = nums[0]; //比较之后的最大值
    
    for(int i = 1;i < nums.size();++i)
    {
        Sum = GetMax(Sum + nums[i], nums[i]);//状态方程
        if(MAX < Sum)
            MAX = Sum;

    }
    cout << MAX;
}
