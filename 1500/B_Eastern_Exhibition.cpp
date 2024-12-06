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

void solve() {
    ll int n; 
    cin>>n;
    vector<ll int> x(n), y(n);
    rep(i,0,n) {cin>>x[i]>>y[i];}
    sort(all(x)); sort(all(y));
    ll int cx=0, cy=0;
    if (n%2 == 1) {cout<<1<<endl;} else {
        cx  = x[n/2] - x[n/2 - 1] + 1;
        cy = y[n/2] - y[n/2 - 1] +1;
        cout<<cx*cy<<endl;
    }

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