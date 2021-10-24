// Find Bridge in graph
	
	// Main 		----	dfs(root) ----
	/*
	 
	private static ArrayList<Integer>[] adj;
	private static int n,timer;
	private static int[] vis,in,low;
	
	 */
	private static void dfs(int node, int par) {
		vis[node] = 1;
		in[node] = low[node] = timer;
		timer++;
		
		for(int child : adj[node]) {
			if(par == child)continue;
			if(vis[child] == 1) {
				// back edge
				low[node] = Math.min(low[node], in[child]);
			}
			else {
				// forward edge
				dfs(child, node);
				if(low[child] > in[node]) {
					System.out.println(node+" - "+child+" is a Bridge");
				}
				low[node] = Math.min(low[node], low[child]);
			}
		}
		
	}

	
	
