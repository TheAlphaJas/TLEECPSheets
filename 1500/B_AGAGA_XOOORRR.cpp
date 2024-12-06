#include <bits/stdc++.h>
using namespace std;
//author: von_Braun
#define ll long long
#define lli long long int
#define pb push_back
#define rep(var, start, num) for(lli var = start; var <start + num; var++)
#define all(x) x.begin(), x.end()
#define ulli unsigned long long int
#define ull unsigned long long
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b) { return (a.second < b.second); }

int getxor(vector<vector<ll int>> &pf, int i, int j) {
    ll int ans=0;
    for(ll int k=0;k<30;k++) {
        ll int z = pf[j][k]-pf[i-1][k];
        z=z%2;
        ans += z*(1<<k);
    }
    return ans;
}

bool check2case(vector<vector<ll int>> &pf, vector<ll int> &a) {
    ll int n = a.size();
    for(ll int i=0;i<n-1;i++) {   
        if (getxor(pf,1,i+1) == getxor(pf,i+2,n)) {
            return 1;
        }
        return 0;
    }

}



bool check3case(vector<ll int> &a, vector<vector<ll int>> &pf, vector<lli> &prfx, vector<lli> &suffx) {
    ll int n = a.size();
    for(ll int i=0;i<n;i++) {
        for(ll int j=i+1;j<n-1;j++) {
            lli z = getxor(pf,i+2,j+1);
            if ((prfx[i] == z)&&(z == suffx[j+1])) {
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    ll int n;
    cin>>n;
    vector<ll int> a(n);
    vector<lli> prfx(n);
    vector<lli> suffx(n);
    rep(i,0,n) {cin>>a[i]; prfx[i] = a[i]; suffx[i]=a[i];}
    rep(i,1,n-1) {prfx[i]=prfx[i-1]^prfx[i];}
    for(int i=n-2;i>=0;i--) {suffx[i]=suffx[i]^suffx[i+1];}
    vector<vector<ll int>> pf(n+1, vector<ll int>(30,0));
    rep(i,0,n) {
        rep(j,0,30) {
            pf[i+1][j] = ((a[i]&(1<<j)) > 0);
            pf[i+1][j]+=pf[i][j];
        }
    }
    if (check2case(pf,a) || check3case(a,pf, prfx, suffx)) {cout<<"YES\n";} else {
        cout<<"NO\n";
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