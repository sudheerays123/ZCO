#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define INF 1e18
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i.first spacef i.second out "     ";
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 100005

struct blaster{
    ll x,y,time,frequency;
};

int main() {

    fast;

    ll n,m,k;
    cin in n in m in k;

    vector<blaster> death(k+5);
    fo(i,1,k) cin in death[i].x in death[i].y in death[i].time in death[i].frequency;

    vector<vector<bool>> go(n+5,vector<bool>(m+5,true));

    // finding the time at which pulse will be at i,j

    fo(i,1,k) {

        ll x = death[i].x;
        ll y = death[i].y;

        go[x][y] = false;

        ll t = x-1;
        mmax(t,n-x);
        mmax(t,y-1);
        mmax(t,m-y);

        fo(pulse,1,t){
            if(x-pulse >= 1 && x-pulse+y-2-death[i].time-pulse >= 0 && (x-pulse+y-2-death[i].time-pulse)%death[i].frequency == 0) go[x-pulse][y] = false;
            if(x+pulse <= n && x+pulse+y-2-death[i].time-pulse >= 0 && (x+pulse+y-2-death[i].time-pulse)%death[i].frequency == 0) go[x+pulse][y] = false;
            if(y-pulse >= 1 && y-pulse+x-2-death[i].time-pulse >= 0 && (y-pulse+x-2-death[i].time-pulse)%death[i].frequency == 0) go[x][y-pulse] = false;
            if(y+pulse <= m && y+pulse+x-2-death[i].time-pulse >= 0 && (y+pulse+x-2-death[i].time-pulse)%death[i].frequency == 0) go[x][y+pulse] = false;
        }
    }

    // finding whether we can go to i,j

    fo(i,1,n){
        fo(j,1,m){
            if((i == 1 && j == 1) || (go[i-1][j] == true || go[i][j-1] == true)) continue;
            go[i][j] = false;
        }
    }

    if(go[n][m] == false) cout out "NO";
    else cout out "YES\n" out n+m-2;

    return 0;
}
