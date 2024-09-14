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
    int n;
    cin>>n;
    int a[n], b[n];
    rep(i,0,n) {cin>>a[i]>>b[i];}
    vector<pair<int,int>> v;
    multiset<int> S;
    rep(i,0,n) {v.pb({b[i]-a[i], b[i]}); S.insert(b[i]);}
    int ans=0;
    sort(v.begin(),v.end());
    for(auto x:v) {
        int start = x.second - x.first;
        int end = x.second;
        auto it = S.lower_bound(start);
        auto it2 = S.upper_bound(end);
        it2--;
        ans+=abs(distance(it,it2));
    }
    cout<<ans<<endl;

    // int cnt=0;
    // rep(i,0,n) {
    //     for(int j=i+1;j<n;j++) {
    //         //will i and j meet?
    //         //if j starts behind i
    //         if (a[j] < a[i]) {
    //             if (b[i]-a[i] < b[j]-a[j]) {
    //                 if (b[j] >= b[i]) {cnt++;}
    //             }
    //         } else {
    //             //i starts behind j
    //             if (b[j]-a[j] < b[i]-a[i]) {
    //                 if (b[i] >= b[j]) {cnt++;}
    //             }
    //         }
    //     }
    // }
    // cout<<cnt<<endl;
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