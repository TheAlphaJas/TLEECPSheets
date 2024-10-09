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
    char x;
    ll int cp=0, cn=0;
    rep(i,0,n) {cin>>x; if (x=='+'){cp++;} else {cn++;}}
    ll int q; cin>>q;
    ll int a,b;
    rep(i,0,q) {
        cin>>a>>b;
        if (a==b) {
            if (cp==cn) {cout<<"YES\n";} else {cout<<"NO\n";}
        } else {
        ll int g = __gcd(a,b);
        int ar = a, br=b;
        a=a/g; b=b/g;
        ll int n1 = abs((cp-cn)/(a-b));
        bool fl=0;
        if (cp - n1*a == cn - n1*b) {
            if (cp - n1*a >= 0) {fl=1;}
        }
        if (cn - n1*a == cp - n1*b) {
            if (cn - n1*a >= 0) {fl=1;}
        }

        if (fl) {cout<<"YES\n";} else {cout<<"NO\n";}
        }
    }
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