#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e18;

int a[105];
char who[25];
int isPick[25];
int dp[1 << 20];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());
    cin >> m;
    for (int i=0; i < m; i++){
        string e, s;
        cin >> e >> s;
        who[i] = e[0];
        if(s == "pick"){
            isPick[i] = 1;
        }
        else{
            isPick[i]=0;
        }
    }


    int full = (1 << m) - 1;
    for(int mask = full; mask >= 0; mask--){
        int step = __builtin_popcountll(mask);
        if (step == m){
            dp[mask] = 0;
            continue;
        }

        int best;
        if(who[step]=='A'){
            best = -INF;
        }
        else{
            best =  INF;
        }

        for(int j = 0; j < m; j++){
            if(mask & (1 << j)){
                continue;
            }
            int gain = 0;
            if(isPick[step]){
                if(who[step] == 'A'){
                    gain = a[j];
                }
                else{
                    gain = -a[j];
                }
            }

            int val = gain + dp[mask | (1<<j)];
            if(who[step] == 'A'){
                best = max(best, val);
            }
            else{
                best = min(best,val);
            }
        }
        dp[mask] = best;
    }

    if(dp[0] > 0){
        cout << "A " << dp[0] << endl;
    }
    else{
        cout << "B " << -dp[0] << endl;
    }
    return 0;
}