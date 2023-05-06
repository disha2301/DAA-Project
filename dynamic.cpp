#include<bits/stdc++.h>

using namespace std;

int minCoins(int C[], int l, int N, int dp[]){

    if(dp[N]!=-1) //if the subproblem is already visited
        return dp[N]; //return the stored result

    int coinsRequired = INT_MAX;
    for(int i = 0; i<l; i++){ //looping over all the denominations
        if(C[i] <= N){ //checking if current denomination is less than given value
            int curr = minCoins(C, l, N-C[i], dp);
            /*
            checking if any combinations exists with the current denomination
            and the length of the combination is less than coinsRequired
            */
            if(curr != INT_MAX && curr + 1 < coinsRequired)
                coinsRequired = curr + 1; //updating the result with the minimum number
      }
   }
    dp[N]=coinsRequired; //storing the result of current subproblem
    return coinsRequired;
}

int coinChange(int C[], int l, int N, int dp[]){ //wrapper method to handle -1 case
    int coinsRequired = minCoins(C, l, N, dp);
    if(coinsRequired == INT_MAX)
        return -1;
    return coinsRequired;
}

int main()
{
    int coins[] = {1, 2, 6, 4, 8, 10}; //denominations
	int N = 13; //given value N
	int l = sizeof(coins)/sizeof(coins[0]); //number of denominations

	int dp[N+1]; //DP array to store results of subproblems

    /*
    Initially filling the whole dp array with -1
    Indicates that all the subproblems are unvisited
    */
    fill(dp, dp+N+1, -1);

    //base case
    dp[0]=0;

    int coinsRequired = coinChange(coins, l, N, dp);

    if(coinsRequired == -1){
        cout<<"Given value cannot be exchanged with available denominations";
    }
    else
	    cout<<"Minimum coins required is "<<coinsRequired;

    return 0;
}
