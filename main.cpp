#include <bits/stdc++.h>
using namespace std;
bool cycle=false;
vector<vector<int>>adj;
vector<bool> visited;
vector<bool> exploring;
priority_queue<int, vector<int>, greater<int>> Q;
vector <int> in_degree;
int u;

void dfs(int s){
    if(cycle==true){ // Caso base, se encontro un ciclo
        return ;
    }

    exploring[s]=true;
    for(auto v: adj[s]){ //Iterar todos los nodos adyacentes a "s"
        if(exploring[v]==true){ //Si el nodo esta en exploring, entonces hay ciclo
            cycle=true;
            break;
        }

        if(visited[v]==false){
            visited[v]=true;
            dfs(v);
        }
    }

    exploring[s]=false;

}

void Kahn(){
    for(int i=0; i<in_degree.size(); i++){
        if(in_degree[i]==0){
            Q.push(i);
        }
    }

    while(Q.empty()==false){
        u=Q.top();
        Q.pop();
        cout<<u<<" ";

        for(auto k: adj[u]){
            in_degree[k]--;
            if(in_degree[k]==0){
                Q.push(k);
            }
        }

    }

}

int main()
{
    ios::sync_with_stdio(0); //Para que el código sea más rápido
    cin.tie(0); //Para que el código sea más rápido
    int N, M, x, y;
    cin>>N>>M;
    adj.resize(N);
    visited.resize(N);
    exploring.resize(N);
    in_degree.resize(N);

    for(int i=0; i<M; i++){
            cin>>x>>y;
            adj[x].push_back(y);
            in_degree[y]++;
    }


    for(int i=0; i<N; i++){
            dfs(i);

    }

    if(cycle==true){
        cout<<-1;
    }else{

        Kahn();
    }










    return 0;
}
