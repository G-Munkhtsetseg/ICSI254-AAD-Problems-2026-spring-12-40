// Sarnai, B.Enhjin, Munhtsetseg, Nymdavaa


#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int graph[MAX][MAX];
int neighbors[MAX]; // хэдэн хөрштэйг хадгална

int check[MAX]; // 0 = очоогүй, 1 = DFS дотор, 2 = дууссан
int n, m;

bool dfs(int v) {
    check[v] = 1; // DFS дотор байгаа 
    for(int i = 0; i < neighbors[v]; i++) {
        int u = graph[v][i];
        // хэрвээ u дээр DFS дотор байгаа бол цикл байна
        if(check[u] == 1) {
            return true;
        }
        // u дээр очоогүй бол DFS-г үргэлжлүүлнэ
        if(check[u] == 0) {
            if(dfs(u)) { 
                return true; 
            }
        }
    }
    check[v] = 2; // DFS дууссан тул 2 болгоно
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    // графыг эхлээд хоосон болгоно
    for(int i = 0; i < n; i++) {
        neighbors[i] = 0;
        check[i] = 0;
    }
    // графыг оруулна
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][neighbors[u]++] = v;
    }
    bool cycle = false; // цикл байгаа эсэхийг хадгалах хувьсагч

    // бүх оройгоос DFS эхлүүлж шалгана
    for(int i = 0; i < n; i++) {
        if(check[i] == 0) {
            if(dfs(i)) {
                cycle = true; // цикл олдсон тул
                break; 
            }
        }
    }

    if(cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
