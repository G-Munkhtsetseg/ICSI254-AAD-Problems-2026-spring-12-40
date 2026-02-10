#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200005

typedef struct { int to, next; } Edge; 

static Edge e[2 * MAX];
static int head[MAX], E = 0;

static void add(int u, int v) {
    e[E] = (Edge){v, head[u]};
    head[u] = E++;
}

// soldiers = одоогийн амьд цэрэг, enemies = тухайн өрөөний мэргид
static long long fight(long long soldiers, long long enemies) {
    return (soldiers > enemies) ? soldiers : soldiers / 2;
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    memset(head, -1, sizeof(head));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }

    // 1-р өрөөнд анх орж ирэх цэргийн тоо.
    long long x;
    scanf("%lld", &x);

    // a[i] = i-р өрөөний мэргидийн тоо хадгална.
    long long *a = malloc((n + 1) * sizeof(long long));
    // best[i] = i-р өрөөнд хүрч чадсан хамгийн их амьд цэрэг
    long long *best = malloc((n + 1) * sizeof(long long));
    
    int *inq = calloc(n + 1, sizeof(int));
    int *q = malloc((n + 5) * sizeof(int));

    //  Өрөө бүрийн мэргэдийн тоог уншина
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) best[i] = -1;

    // l = queue-ийн урд индекс (гарах тал)
    // r = queue-ийн ард индекс (орох тал)
    int l = 0, r = 0;

    best[1] = fight(x, a[1]);
    if (best[1] > 0) q[r++] = 1, inq[1] = 1;

    // queue хоосроогүй үед давтана.
    while (l < r) {
        int u = q[l++];
        inq[u] = 0;
        // cur = u өрөөнд хүрэх хамгийн их цэрэг.
        long long cur = best[u];
        if (cur <= 0) continue;

        for (int id = head[u]; id != -1; id = e[id].next) {
            int v = e[id].to;
            long long nxt = fight(cur, a[v]);

            if (nxt > best[v]) {
                best[v] = nxt;
                if (!inq[v]) q[r++] = v, inq[v] = 1;
            }
        }
    }

    long long ans = best[n];
    printf("%lld\n", ans < 0 ? 0 : ans);

    free(a); free(best); free(inq); free(q);
    return 0;
}
