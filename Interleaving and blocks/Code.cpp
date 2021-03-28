#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define INF 1e18
#define MOD 100000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max((x),(i))
#define mmin(x,i) x = min((x),(i))
#define N 205

ll dp[105][105][205][2];

int main() {

    fast;

    tc{
        memset(dp,0,sizeof dp);

        ll n,m,k;
        cin in n in m in k;

        vi a(n+5);
        vi b(m+5);

        fo(i,1,n) cin in a[i];
        fo(i,1,m) cin in b[i];

        // dp[i][j][k][l] = number of ways to create k blocks , if we consider the first i elements in A and first j elements in B and the last element is from A ( if l = 0 ) , or last element is from B ( if l = 1 )

        // base case :

        dp[0][0][0][0] = 1;
        dp[0][0][0][1] = 1;

        // recurrence relation :

        fo(i,0,n){
            fo(j,0,m){

                if(i == 0 && j == 0) continue;

                fo(l,0,k){
                    // calculating dp[i][j][l][0]

                    if(i != 0 && a[i] == a[i-1] && l != 0) dp[i][j][l][0] += dp[i-1][j][l-1][0];
                    else if(i != 0 && a[i] != a[i-1]) dp[i][j][l][0] += dp[i-1][j][l][0];

                    if(i != 0 && a[i] == b[j] && l != 0) dp[i][j][l][0] += dp[i-1][j][l-1][1];
                    else if(i != 0 && a[i] != b[j]) dp[i][j][l][0] += dp[i-1][j][l][1];

                    // calculating dp[i][j][l][1]

                    if(j != 0 && b[j] == a[i] && l != 0) dp[i][j][l][1] += dp[i][j-1][l-1][0];
                    else if(j != 0 && b[j] != a[i]) dp[i][j][l][1] += dp[i][j-1][l][0];

                    if(j != 0 && b[j] == b[j-1] && l != 0) dp[i][j][l][1] += dp[i][j-1][l-1][1];
                    else if(j != 0 && b[j] != b[j-1]) dp[i][j][l][1] += dp[i][j-1][l][1];
                }
            }
        }

        // answer :

        ll ans = 0;

        ans += dp[n][m][k][0];
        ans %= MOD;
        ans += dp[n][m][k][1];
        ans %= MOD;

        cout out ans%MOD nextline;
    }

    return 0;
}
