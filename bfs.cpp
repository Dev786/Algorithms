#include<iostream>
#define MAX 6
using namespace std;

int visited[MAX] = {0};
int queue[MAX]= {-1};
int front = -1;
int last = 0;
int parent[MAX];

void bfs(int a[MAX][MAX],int n,int root,int dest)
{
	visited[root] = 1;
	queue[last++] = root;
	parent[root] = 0;
	while(front<=last)
	{
		int c = queue[++front];
		for(int i=1;i<=n;i++)
		{
				if(a[c][i] == 1 && !visited[i])
				{
				queue[last++] = i;
				visited[i] = 1;
				parent[i] = c;
				}
		}
	}
	
	/*for(int i=1;i<=4;i++)
	cout<<parent[i]<<" ";
//	int c;
	*/
	
	int c;
	int path[MAX],k = 0;
	path[k++] = dest;
	while((c = parent[dest])!=0)
	{
		path[k++] = c;	
		dest = c;
	}
	
	cout<<"\n PATH IS \n";
	
	for(int  i = k-1;i>0;i--)
	cout<<path[i]<< " --> ";
	
	cout<<path[0];

}

int main()
{
	int n,a[MAX][MAX];
	cout<<"\nEnter the number of input: ";
	cin>>n;
	cout<<"\nEnter the Graph: \n";
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	cin>>a[i][j];
	
	int root = 1;
	int dest = 5;
	
	bfs(a,n,root,dest);
	return 0;
}
