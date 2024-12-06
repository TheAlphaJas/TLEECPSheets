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
    pair<int,int> p[n];
    rep(i,0,n) {cin>>p[i].first>>p[i].second;}
    sort(p,p+n);
    int l1=-1, l2=-1;
    vector<int> v;
    bool eb=0;
    l1=p[0].second;
    v.pb(1);
    rep(i,1,n-1) {
        if (p[i].first <= l1) {
            if (p[i].first<=l2) {
                eb=1;
                break;
            } else {
                l1 = max(l1,p[i].second);
                v.pb(1);
            }
        }   else  {
            l1 = max(l1,p[i].second);
            v.pb(1);
        }
    }
    if (eb) {cout<<"-1\n";} else {
        bool t2=0;
        for(auto x:v) {if (x==2) {t2=1; break;}}
        if (t2==0) {
            cout<<2<<" ";
            for(int i=1;i<v.size();i++) {cout<<v[i]<<" ";}
            cout<<endl;
        } else {
            for(auto x:v) {cout<<x<<" ";}
            cout<<endl;
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
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}