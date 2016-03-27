class KMP{
public:
	int strStr(string haystack, string needle){
		int needle_len = needle.size();
		int haystack_len = haystack.size();
		int P[needle_len];
		memset(P, -1, sizeof(P));
		//求解字串的自匹配数组P
		P[0] = -1;
		int j = -1, i = 1;
		for(; i<needle_len; ++i)
		{
			while(j>-1 && needle[j+1]!=needle[i])
				j = P[j];
			if(needle[j+1] == needle[i])
				j++;
			P[i] = j;
		}

		//KMP匹配
		j = -1;
		for(i=-1; i<haystack_len-1;)
		{
			while(j>-1 && haystack[i+1]!=needle[j+1])
				j = P[j];
			if(haystack[i+1] == needle[j+1])
				j++;
			i++;
			if(j == needle_len-1)
				return i-j;
		}
		return -1;
	}
};
