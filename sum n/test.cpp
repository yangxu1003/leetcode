class Sum
{
public:
    Sum()
    {
        _ret += _i;
        ++_i;
    }

    static void init()
    {
        _i = 1;
        _ret = 0;
    }

    static int GetRet()
    {
        return _ret;
    }

private:
    static int _i;
    static int _ret;
};

int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Sum::init();
        Sum arr[n];

        return Sum::GetRet();
    }

};