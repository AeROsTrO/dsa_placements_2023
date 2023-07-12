#include <bits/stdc++.h>
using namespace std;
// problem description here
//  Reverse bits of a given 32 bits unsigned integer.

// Note:
// Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
// In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
int sol1(int n)
{
    vector<int> v(32, 0);
    for (int i = 0; i < 32; ++i)
    {
        if (((n >> i) & 1) != 0)
        {
            v[i] = 1;
        }
    }
    reverse(v.begin(), v.end());

    for (int i : v)
        cout << i << " ";
    uint32_t ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += (v[i] * pow(2, i));
    }
    return ans;
}
int sol(uint32_t n)
{
    // O(1) O(1)
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int a = n & 1;       // remainder
        n = n >> 1;          // getting to the next integer
        ans = (ans * 2) + a; // building the number
    }
    return ans;
}
int soll(uint32_t n){
    uint32_t answer= 0;
        //first digit appended will be MSB at the end ensuring reverse
        for(int i=0; i<32; i++) {
            answer = (answer<<1) + (n>>i &1);
        }
    return answer;
}
int main()
{
    int n;
    cin >> n;

    return 0;
}