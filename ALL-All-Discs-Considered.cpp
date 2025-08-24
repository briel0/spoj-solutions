#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5;
vector<int> adj[N], indegree;

int calc(queue<int> um, queue<int> dois, int atual, int n1){
    int cnt = 1;

    queue<int> fila[2];

    fila[0] = um;
    fila[1] = dois;

    while(!fila[0].empty() || !fila[1].empty()){
        if(fila[atual].empty()){
            atual ^= 1;
            cnt++;
        }

        int v = fila[atual].front();
        fila[atual].pop();

        for(int &i : adj[v]){
            bool temp = i > n1;
            fila[temp].push(i);
        }
    }
    return cnt + 1;
}

void work(int n1, int n2, int d){

    indegree.assign(n1 + n2 + 1, 0);

    for(int i = 1; i <= n1 + n2; i++){
        adj[i].clear();
    }

    while(d--){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        indegree[a]++;
    }

    queue<int> f[2];

    for(int i = 1; i <= n1 + n2; i++){
        if(!indegree[i]){
            bool temp = i > n1;
            f[temp].push(i);
        }
    }

    int um = calc(f[0], f[1], 0, n1);
    int dois = calc(f[0], f[1], 1, n1);
    cout << min(um, dois) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n1, n2, d;
    while(cin >> n1 >> n2 >> d){
        if(!n1 && !n2 && !d){
            break;
        }
        work(n1, n2, d);
    }
}
