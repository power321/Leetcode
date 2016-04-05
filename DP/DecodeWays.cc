class Solution {
public:
	int numDecodings(string s) {
		int len = s.size();
		int dp[10005][2] = {0};
		if(s[0]-'0' >= 1 && s[0]-'0' <= 26)
			dp[0][0] = 1;
		for(int i=1; i<len; i++)
		{
			if(s[i]-'0' >= 1 && s[i]-'0' <= 26)
				dp[i][0] = dp[i-1][0] + dp[i-1][1];
			int tmp = (s[i-1]-'0')*10 + (s[i]-'0');
			if(tmp <= 26 && tmp >= 1)
				dp[i][1] = dp[i-1][0];
		}
		return dp[len-1][0] + dp[len-1][1];
	}
};
