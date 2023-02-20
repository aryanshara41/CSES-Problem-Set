#include<bits/stdc++.h>
using namespace std;
#define pqsmall(name) priority_queue<int,vector<int>,greater<int>>name;
#define yes "YES\n"
#define no "NO\n"
#define int long long 
#define mod 1000000007

inline void debugMode() {
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif // ONLINE_JUDGE
}

/*========================**Shubham Kumar**========================*/

int PerfectSums( int input1, int input2[], int input3 ){

    sort( input2, input2 + input1 );

    int dp[input1+1][input3+1];
    for( int i = 0; i<=input1; i++ ) dp[i][0] = 1;
    for( int j = 0; j<=input3; j++ ) dp[0][j] = 0;

    dp[0][0] = 1;

    for( int i = 1; i<=input1; i++ ){
        for( int j = 1; j<=input3; j++ ){
            if( j >= input2[i-1] ){
                dp[i][j] = dp[i-1][j] + dp[i-1][ j - input2[i-1] ];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    int ans = dp[input1][input3];

    for( int i = 0; i<input1; i++ ){
        if( input2[i] == input3 ) ans--;
    }

    if( ans == 0 ) ans = 999;

    return ans;
}


void solve(){
    string str; cin >> str;
    int n = str.size();

    bool flag = true; // consider it is java
    for( auto ch : str ){
        if( ch == '_' ){
            flag = false; break;
        }
    }

    string ans = "";

    if( !flag ){
        int i = 0;
        while( i < n ){
            if( str[i] == '_' ){
                while( i < n and str[i] == '_' )i++;
                if( i < n ){
                    ans += toupper(str[i]);
                    i++;
                }
            }
            else ans += str[i++];
        }

    }
    else{
        // it means convert into c++;
        int i = 0;
        while( i < n ){
            if( str[i] >= 'A' and str[i] <= 'Z' ){
                ans += "_";
                ans += tolower(str[i]);
                i++;
            }
            else ans += str[i++];
        }
    }

    cout << ans << endl;
}

signed main(){
    debugMode();
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while( t-- ){
        solve();
    }
    return 0;
}