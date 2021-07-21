#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int dp[n+1][k+1];
    for(int i =0;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else{
                dp[i][j] = dp[i-1][j];
                if(arr[i-1] <= j && arr[i-1] > 0){
                    dp[i][j] += dp[i-1][j/arr[i-1]] + 1;
                }
            }
        }
    }
    cout << dp[n][k];

}
