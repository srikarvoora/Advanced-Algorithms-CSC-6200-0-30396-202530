#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 

int main() {
    std::string s1 = "ABAB";
    std::string s2 = "BABA";
    int n = s1.size();
    int m = s2.size();

    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));

    int maxLen = 0;       
    int maxPos = 0;       

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    maxPos = i; 
                }
            } else {
                dp[i][j] = 0; 
            }
        }
    }

    std::cout << "DP Table:\n\n";
    std::cout << std::setw(4) << " ";
    for(int j = 0; j < m; ++j) {
        std::cout << std::setw(3) << s2[j];
    }
    std::cout << "\n";
    
    for(int i = 0; i <= n; ++i) {
        if(i == 0) {
            std::cout << std::setw(3) << " ";
        } else {
            std::cout << std::setw(3) << s1[i-1];
        }
        
        for(int j = 0; j <= m; ++j) {
            std::cout << std::setw(3) << dp[i][j];
        }
        std::cout << "\n";
    }

    std::string longestCommonSubstring = s1.substr(maxPos - maxLen, maxLen);

    std::cout << "\nLongest Common Substring Length: " << maxLen << "\n";
    std::cout << "One such Longest Common Substring: \"" 
              << longestCommonSubstring << "\"\n";

    return 0;
}
