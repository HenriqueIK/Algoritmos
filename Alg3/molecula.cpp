#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main() 
{
    int N;
    
    int M;
    
    cin >> N;
    
    vector<string> seq1(N);
    
    for(int i = 0; i < N; i++) 
	{
        cin >> seq1[i];
    }
    
    cin >> M;
    
    vector<string> seq2(M);
    
    for(int i = 0; i < M; i++) 
	{
        cin >> seq2[i];
    }
    
    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    
    for(int i = 1; i <= N; i++) 
	{
        for(int j = 1; j <= M; j++) 
		{
            if(seq1[i-1] == seq2[j-1]) 
			{
                dp[i][j] = dp[i-1][j-1] + 1;
            }
			else
			{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int i = N, j = M;
    
    vector<string> result;
    
    while(i > 0 && j > 0) 
	{
        if(seq1[i-1] == seq2[j-1]) 
		{
            result.push_back(seq1[i-1]);
            i--;
            j--;
        }
		else if(dp[i-1][j] > dp[i][j-1])
		{
            i--;
        } 
		else
		{
            j--;
        }
    }
    
    reverse(result.begin(), result.end());
    
    for(const auto& molecula : result) 
	{
        cout << molecula << " ";
    }

    return 0;
}