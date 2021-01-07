#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

int main() {

    ll n;
    cin in n;

    vi a(n+5);
    fo(i,0,n-1) cin in a[i];

    vi dp1(n+5);
    vi dp2(n+5);

    dp1[0] = a[0];
    dp2[0] = a[0];

    dp1[1] = a[1]+dp1[0];
    dp2[1] = a[1];

    ll ans = -INF;

    fo(i,2,n-1){
        dp1[i] = max(a[i] + dp2[i-1],dp1[i-1]);
        dp2[i] = max(a[i] + max(dp2[i-2],dp1[i-2]),dp2[i-1]);

        mmax(ans,max(dp1[i],dp2[i]));
    }

    cout out ans;

    return 0;

}
