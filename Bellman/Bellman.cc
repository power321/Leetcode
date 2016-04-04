#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

const int MAXN = 150;
const int MAXM = MAXN * MAXN;
const int INF = 111222333;
map<string, int>my_map;
struct EDGE{
	int u, v, len;
	int pre;
}edge[MAXM];
int p[MAXN+5], dis[MAXN+5], n, m, edge_cnt;
int startPoint, endPoint;

void addEdge(int u, int v, int num)
{
	edge[edge_cnt].u = u; edge[edge_cnt].v = v; edge[edge_cnt].len = num;
	edge[edge_cnt].pre = p[u];
	p[u] = edge_cnt++;
	edge[edge_cnt].u = v; edge[edge_cnt].v = u; edge[edge_cnt].len = num;
	edge[edge_cnt].pre = p[v];
	p[v] = edge_cnt++;
}

bool BellmanFord(int st)
{
	//cout << INF << endl;
	for(int i=0; i<=n+1; i++)
		dis[i] = INF;
	dis[st] = 0;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<edge_cnt; j++)
		{
			int u = edge[j].u;
			int v = edge[j].v;
			int len = edge[j].len;
			if(dis[v] > dis[u] + len)
				dis[v] = dis[u] + len;
		}
	}
	for(int i=0; i<edge_cnt; i++)
		if(dis[edge[i].v] > dis[edge[i].u] + edge[i].len)
			return false;
	return true;
}

int main()
{
	int T, len, map_cnt;
	string str1, str2;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		my_map.clear();
		memset(p, -1, sizeof(p));
		edge_cnt = 0;
		my_map["swust"] = 1;
		startPoint = 1;
		map_cnt = 1;
		while(m--)
		{
			cin >> str1 >> str2 >> len;
			if(!my_map[str1])
				my_map[str1] = ++map_cnt;
			if(!my_map[str2])
				my_map[str2] = ++map_cnt;
			addEdge(my_map[str1], my_map[str2], len);
		}
		cin >> str1;
		if(!my_map[str1])
		{
			
			cout << "You can't reach!" << endl;
			continue;
			my_map[str1] = ++map_cnt;
		}
		endPoint = my_map[str1];
		//for(int i=0; i<edge_cnt; i++)
		//	cout << "edge: " << edge[i].u << " --> " << edge[i].v << " len=" << edge[i].len << endl;
		//cout << endPoint << endl;
		if(BellmanFord(startPoint) && dis[endPoint]!=INF)
			cout << dis[endPoint] << endl;
		else
			cout << "You can't reach!" << endl;
	}
	return 0;
}
