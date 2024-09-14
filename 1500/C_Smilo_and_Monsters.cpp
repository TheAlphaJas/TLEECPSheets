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
    deque<int> a(n);
    rep(i,0,n) {cin>>a[i];}
    sort(all(a));
    lli x=0;
    lli at=0;
    while(!a.empty()) {
        if (a.size() == 1) {
            // cout<<a[0]<<" "<<x<<endl;
            int k = (a[0] -x)/2;
            // cout<<"k "<<k<<endl;
            x+=k;
            at+=k;
            a[0]-=k;
            if (x>0) {
            at+=1;
            a[0] -= x;
            x=0;
            }
            // cout<<"rem a0 "<<a[0]<<endl;
            at += a[0];
            a.clear();
            continue;
        }
        if (x + a[0] < a[a.size()-1]) {
            x+=a[0];
            at += (a[0]);
            a.pop_front();
        } else {
            int z = a[a.size()-1]-x;
            x += z;
            a[0]-=z;
            at += z;
        }   
        if (a[0] == 0) {a.pop_front();}
        if (x == a[a.size()-1]) {a.pop_back(); at+=1; x=0;}
    }
    cout<<at<<endl;
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