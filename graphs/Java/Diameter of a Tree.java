// Diameter of a Tree
	private static int Diameter_of_Tree() {
		// Write in Main Code
	 	max = -1;
        dfs(1,0);
        
        for(int i=1; i<=n; i++)
        	visited[i] = 0;
        
        
        max = -1;
        dfs(maxNode,0);
	 
		return max;
	}
	static int N = 0;
	static int visited[] = new int[N];
	static int colour[] = new int[N];
	static int maxNode,max = Integer.MIN_VALUE;
	 
	private static void dfs(int node, int dis) {
		visited[node]=1;
		if(dis > max) {
			max = dis;
			maxNode = node;
		}
		for (int  child : adj[node]) {
			if(visited[child] == 0) {
				dfs(child,dis+1);
			}
		}
	}
	
