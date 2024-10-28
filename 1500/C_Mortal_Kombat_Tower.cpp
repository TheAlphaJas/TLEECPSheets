#include <bits/stdc++.h>
using namespace std;
//author: von_Braun
#define ll long long
#define lli long long int
#define pb push_back
#define rep(var, start, num) for(ulli var = start; var <start + num; var++)
#define all(x) x.begin(), x.end()
#define ulli unsigned long long int
#define ull unsigned long long
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b) { return (a.second < b.second); }
//p_id=0 means me, 1 means friend
int solve(int i, vector<int> &a, int p_id) {
    int n = a.size();
    if (p_id == 0) {
        if (i==n-1) {
            return 0;
        }
        int z = solve(i+1,a,1-p_id);
        if (i+2<n) {z = min(z,solve(i+2,a,1-p_id));}
        return z;
    } else {
        if (i==n-1) {
            return a[i];
        }
        int z = a[i] + solve(i+1,a,1-p_id);
        if (i+2<n) {
            z = min(z,a[i]+a[i+1]+solve(i+2,a,1-p_id));
        }
        return z;
    }
    return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n) {cin>>a[i];}
    cout<<solve(0,a,1)<<endl;
}
int main() {
    //add quotes incase input output file
    //freopen(input.txt,r,stdin);
    //freopen(output.txt,w,stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}