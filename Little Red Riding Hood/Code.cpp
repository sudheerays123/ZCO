#include <iostream>
#include <vector>
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

int main(){

    ll n,m;
    cin in n in m;

    vector<vi> grid(n+5,vi(n+5));

    fo(i,0,n-1){
        fo(j,0,n-1){
            cin in grid[i][j];
        }
    }

    vector<vector<bool>> safe(n+5,vector<bool>(n+5,false));


    fo(i,0,m-1) {
        ll x,y,k;
        cin in x in y in k;
        x--;y--;

        fo(row,max(0ll,x-k),min(n,x+k)){
            ll remstrength = k - abs(row-x);
            fo(column,max(0ll,y-remstrength),min(n,y+remstrength)){
                safe[row][column] = true;
            }
        }
    }

    vector<vi> dp(n+5,vi(n+5,-INF));

    if(safe[0][0] == false || safe[n-1][n-1] == false){
        cout out "NO";
        return 0;
    }

    // BASE CASE :

    dp[0][0] = grid[0][0];
    fo(i,1,n-1){
        if(safe[i][0] == false) break;
        dp[i][0] = grid[i][0] + dp[i-1][0];
    }
    fo(j,1,n-1){
        if(safe[0][j] == false) break;
        dp[0][j] = grid[0][j] + dp[0][j-1];
    }

    // RECURRENCE RELATION :

    fo(i,1,n-1){
        fo(j,1,n-1){
            if(safe[i][j] == false) continue;
            if(max(dp[i-1][j],dp[i][j-1]) == -INF) continue;
            dp[i][j] = grid[i][j] + max(dp[i-1][j],dp[i][j-1]);
        }
    }

    if(dp[n-1][n-1] == INF) cout out "NO\n";
    else cout out "YES\n" out dp[n-1][n-1];

    return 0;
}
