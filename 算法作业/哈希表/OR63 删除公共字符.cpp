#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    string b;
    getline(cin , a);
    getline(cin , b);
    string c;
    int arr[128] = {0};
    for(auto i : b)
    {
        ++arr[i]; 
    }

    for(auto i : a)
    {
        if(arr[i] == 0)
        c += i;
    }

    cout << c;
}
