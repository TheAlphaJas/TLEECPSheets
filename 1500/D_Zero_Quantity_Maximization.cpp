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

pair<ll int,ll int> proc(ll int a, ll int b) {
    if (a<0) {
        a=-a;
        b=-b;
    }
    ll int g = gcd(abs(a),abs(b));
    a=a/g; b=b/g;
    if (b==0) {a=abs(a);}
    return {b,a};
}

void solve() {
    int n;
    cin>>n;
    ll int cc=0;
    map<pair<ll int,ll int>, ll int> mp;
    ll int a[n], b[n];
    rep(i,0,n) {cin>>a[i];} 
    rep(i,0,n) {cin>>b[i];}
    rep(i,0,n) {
        if (a[i]==0) {
            if(b[i]==0) {cc++;}
            continue;
        }
        mp[proc(a[i],-b[i])]++;
    }
    ll int mx=0;
    for(auto x:mp) {
        // cout<<x.first.first<<" "<<x.first.second<<" : "<<x.second<<endl;
        mx = max(mx,x.second);
    }
    cout<<cc+mx<<endl;
}
int main() {
    //add quotes incase input output file
    //freopen(input.txt,r,stdin);
    //freopen(output.txt,w,stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}