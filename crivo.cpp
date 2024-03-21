#include <bits/stdc++.h>
#define int long long
using namespace std;

void trial_division1(long long n)
{
    while(n%2==0){
        cout << 2 << " ";
        n/=2;
    }
    
    for (long long d = 3; d * d <= n; d+=2)
    {
        while (n % d == 0)
        {
            cout << d << " ";
            n /= d;
        }
    }
    if (n > 1)
        cout << n;
}

signed main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(n%i==0) cout << i << " ";
    }
    cout << endl;
    trial_division1(n);
    cout << endl;
}