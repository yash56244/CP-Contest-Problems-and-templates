bool cycle(int s, int p, vector<int> adj[], vector<int> &color){
    color[s] = 1;
    for(auto v : adj[s]){
        if(v != p){
	        if(color[v] == 0){
	            if(cycle(v, s, adj, color)){
	                return true;
	            }
	        }else if(color[v] == 1){
	            return true;
	        }
        }
    }
    color[s] = 2;
    return false;
}
bool isCycle(int V, vector<int> adj[]) 
{
    vector<int> color(V, 0);
    for(int i = 0; i < V; i++){
        if(color[i] == 0){
            if(cycle(i, -1, adj, color)){
                return true;
            }
        }
    }
    return false;
}