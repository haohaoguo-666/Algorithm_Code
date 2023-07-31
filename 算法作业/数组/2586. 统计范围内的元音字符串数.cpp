class Solution {
public:

    bool com(char a)
    {
        if(a == 'a' | a == 'e' | a == 'i' | a == 'o' | a == 'u')
            return true;

        return false; 
            
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ret = 0;
        for(int i = left;i <= right;i++)
        {
            int length = words[i].size();//取字符串长度
            if(com(words[i][0]) && com(words[i][length-1]))
                //判断是否是元音字符串
            ++ret;
        }
        return ret;
    }
};