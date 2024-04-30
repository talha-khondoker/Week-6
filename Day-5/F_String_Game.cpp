#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool ok(int *ar, int mid, string t, string p)
{
    unordered_set<int> h;
    for(int i=0; i<mid; i++)
    {
        h.insert(ar[i]);
    }
    string res="";
    for(int i=0; i<t.size(); i++)
    {
        if(h.find(i)==h.end())
        {
            res+=t[i];
        }
    }
    int p1=0, p2=0;
    while (p1<res.length() && p2< p.length())
    {
        if(res[p1]==p[p2])
        {
            p1++;
            p2++;
        }
        else
        {
            p1++;
        }
    }
    return (p2==p.length());
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string t, p;
    cin>>t>>p;
    int ar[t.size()];
    for(int i=0; i<t.size(); i++)
    {
        cin>>ar[i];
        ar[i]-=1;
    }
    int l=0; 
    int r=t.length();
    while (r>l+1)
    {
        int mid=(l+r)>>1;
        if(ok(ar, mid, t, p))
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<l<<endl;
    return 0;
}