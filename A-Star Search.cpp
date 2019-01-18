#include<bits/stdc++.h>
using namespace std;

#define V 20
string S[] = {"Oradea", "Zerind", "Arad", "Timisoara", "Lugoj", "Mehadia", "Dobreta", "Sibiu", "Rimnicu_Vilcea", "Craiova", "Fagaras", "Pitesti", "Bucharest", "Giurgiu", "Neamt", "Iasi", "Vaslui", "Urziceni", "Hirsova", "Eforie"};
int A[] = {380, 374, 366, 329, 244, 241, 242, 253, 193, 160, 178, 98, 0, 77, 234, 226, 199, 80, 151, 161};
int edge[25][25];
int ss,dd;

void initialization()
{
    memset(edge, 0, sizeof(edge));

    edge[1][2] = 71, edge[1][8] = 151;
    edge[2][1] = 71, edge[2][3] = 75;
    edge[3][2] = 75, edge[3][4] = 118, edge[3][8] = 140;
    edge[4][3] = 118, edge[4][5] = 111;
    edge[5][4] = 111, edge[5][6] = 70;
    edge[6][5] = 70, edge[6][7] = 75;
    edge[7][6] = 75, edge[7][10] = 120;
    edge[8][1] = 151, edge[8][3] = 140, edge[8][9] = 80, edge[8][11] = 99;
    edge[9][8] = 80, edge[9][10] = 146, edge[9][12] = 97;
    edge[10][7] = 120, edge[10][9] = 146, edge[10][12] = 138;
    edge[11][8] = 99, edge[11][13] = 211;
    edge[12][9] = 97, edge[12][10] = 138, edge[12][13] = 101;
    edge[13][11] = 211, edge[13][12] = 101, edge[13][14] = 90, edge[13][18] = 85;
    edge[14][13] = 90;
    edge[15][16] = 87;
    edge[16][15] = 87, edge[16][17] = 92;
    edge[17][16] = 92, edge[17][18] = 142;
    edge[18][17] = 142, edge[18][19] = 98, edge[18][13] = 85;
    edge[19][18] = 98, edge[19][20] = 86;
    edge[20][19] = 86;

}


int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printPath(int parent[], int j)
{
	if (parent[j] == - 1)
		return;

	printPath(parent, parent[j]);


	cout<<S[j]<<" ";
}

int printSolution(int dist[], int n,int parent[])
{
	int src = ss;
    int i=dd;
	cout<<"Destination: "<<S[src]<<" to "<<S[i]<<endl;
	cout<<"Cost: "<<dist[i]+A[i]<<endl;
	cout<<"Road: "<<S[src]<<" ";
	printPath(parent, i);
	cout<<endl;
}


void FindPath(int graph[V][V], int src )
{
	int dist[V];
	bool sptSet[V];
	int parent[V];
	for (int i = 0; i < V; i++)
	{
		parent[src] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;
	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	printSolution(dist, V, parent);
}


int main()
{
    initialization();
    int graph[V][V];
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
            graph[i][j]=edge[i+1][j+1];
    }
    string s,d;
    puts("Enter source and destination:");
    cin>>s>>d;

    for(int i=0;i<20;i++){
        if(S[i]==s)
            ss=i;
        if(S[i]==d)
            dd=i;
    }
    cout<<ss<<" "<<dd<<endl;
	FindPath(graph, ss);
	return 0;
}
