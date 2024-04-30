#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n;
    cin>>k>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    auto good = [&](ll mid) 
    {
    ll sum = 0;
    for(int i=0; i<n; i++) 
    {
        if (a[i] > mid) sum += mid;
        else sum += a[i];
    }
    return (sum/mid) >= k;
    };
    ll l = 0, r = 25 * 1e9 + 10, ans;
    while(l<= r) 
    {
        ll mid = (l+r)/2;
        if(good(mid)) 
        {
            ans=mid;
            l = mid+1;
        } else 
        {
            r = mid-1;
        }
    }
    cout << ans << "\n";
    return 0;
}