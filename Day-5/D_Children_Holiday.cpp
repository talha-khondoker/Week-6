#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin>>m>>n;
    vector<int> t(n), y(n), z(n), ans(n);
    for(int i=0; i<n; i++)
    {
        cin >> t[i] >> z[i] >> y[i];
    }
    if(m == 0) 
    {
        cout << 0 << endl;
        for(int i=0; i<n; i++) 
        {
            cout << "0 ";
        }
        return 0;
    }

    auto good = [&](int time) 
{
    int res = 0;
    for(int i=0; i<n; i++) 
    {
        int ballon = time/(t[i]*z[i] + y[i]);
        int rem = time - ballon * (t[i]*z[i] + y[i]);
        ballon *= z[i];
        if(rem >= t[i]) 
        {
            if(rem/t[i] > z[i]) 
            {
                ballon += z[i];
            }
            else ballon += (rem/t[i]);
        }
        ans[i] = ballon;
        res += ans[i];
    }
    return res >= m;
};
    int l = 0, r = 1e7, count = 0;
    while(l+1 < r) 
    {
        count++;
        int mid = (l+r)/2;
        if(good(mid)) 
        {
            r = mid;
        }
        else 
        {
            l = mid;
        }
    }
    cout << r << "\n";
    int time = r;
    for(int i=0; i<n; i++) 
    {
        int ballon = time/(t[i]*z[i] + y[i]);
        int rem = time - ballon * (t[i]*z[i] + y[i]);
        ballon *= z[i];
        if(rem >= t[i]) 
        {
            if(rem/t[i] > z[i]) 
            {
                ballon += z[i];
            }
            else ballon += (rem/t[i]);
        }
        ans[i] = ballon;
    }
    int blown = 0;
    for(int i=0; i<n; i++) 
    {
        if(blown + ans[i] > m) 
        {
            if(m > 0) 
            {
                cout << m-blown << " ";
                m = 0;
            }
            else cout << "0 ";
        }
        else cout << ans[i] << " ";
        blown += ans[i];
    }
    cout << "\n";
    return 0;
    return 0;
}