#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 1e18;
const int N = 200010;

int v[N], lo[N], hi[N], sm[N], L[N], R[N], q[N], ok[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, x, p = 2, t = 1, best=0;
    while(cin>>x){
        v[++n]= x;
    }
    if (n == 0 || v[1] < 0){
        cout <<0<< endl;
        return 0;
    }


    q[0] = 1;
    for(int h = 0; h < t && p <= n; h++){
        int u = q[h];
        if(p <= n && v[p++] >= 0){
            L[u] = p-1;
            q[t++] = p - 1;
        }
        if (p <= n && v[p++]>=0){
            R[u] =p - 1;
            q[t++] =  p - 1;
        }
    }

    for(int k = t - 1; k >= 0; k--){
        int i = q[k], l = L[i],r = R[i];
        ok[i] = 1;
        lo[i] = v[i];
        hi[i]=v[i];
        if(l != 0){
            if(ok[l] == 0 || hi[l] >= v[i]){
                ok[i]= 0;
            }
            lo[i] = lo[l];
        }
        if (r != 0){
            if(ok[r]==0 || lo[r] <= v[i]){
                ok[i] = 0;
            }
            hi[i] = hi[r];
        }
        sm[i] = v[i] + sm[l] +sm[r];

        if(ok[i]){
            best = max(best,sm[i]);
        }
    }

    cout<<best <<endl;
    return 0;
}