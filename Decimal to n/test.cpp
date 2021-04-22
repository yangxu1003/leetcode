#include <iostream>
#include <string>

using namespace std;

int main()
{
    int M,N;
    cin >> M >> N;
    
    string s;
    string str = "0123456789ABCDEF";
    
    int flag = 1;
    if(M < 0)
    {
        M = -M;
        flag = -1;
    }
    
    while(M != 0)
    {
        s = str[M%N] + s;
        M /= N;
    }
    
    if(flag == -1)
    {
        s = '-' + s;
    }
    cout << s << endl;
    
    return 0;
}