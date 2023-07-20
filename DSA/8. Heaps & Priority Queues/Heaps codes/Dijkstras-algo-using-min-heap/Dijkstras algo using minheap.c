#include <stdio.h>
#include <stdlib.h>

//#define HEAP_PARENT(i) (i/2)
//#define HEAP_LEFT(i) (2*i)
//#define HEAP_RIGHT(i) (2*i+1)

void min_heapify(int A[][2], int i, int n) {
    int l = 2*i;
    int r = 2*i+1;
    int min = 0;
    
    if(l <= n && A[l-1][0] < A[i-1][0]) {
        min = l;
    } else {
        min = i;
    }
    if(r <= n && A[r-1][0] < A[min-1][0]) {
        min = r;
    }
    if(min != i) {
        int temp1 = A[i-1][0];
        int temp2 = A[i-1][1];
        
        A[i-1][0] = A[min-1][0];
        A[i-1][1] = A[min-1][1];
        A[min-1][0] = temp1;
        A[min-1][1] = temp2;

        min_heapify(A, min, n);
    }
}

void build_min_heap(int A[][2], int n) {    
    for(int i = (n/2); i > 0; i--) {
        min_heapify(A, i, n);
    }
}

int heap_extract_min(int A[][2], int n, int *node_index) {
    if(n < 1) {
        printf("error: underflow\n");
        return -1;
    }
    
    int min = A[0][0];
    int u = A[0][1];

    if(n > 1) {        
        A[0][0] = A[n-1][0];
        A[0][1] = A[n-1][1];
        build_min_heap(A, n - 1);
        //min_heapify(A, 1, n - 1);
    }
    *node_index = u;
    return min;
}

void heap_decrease_key(int heap[][2], int u, int weight, int n) {
    for(int i = 0; i < n; i++) {
        if(heap[i][1] == u) {
            if(weight < heap[i][0]) {
                heap[i][0] = weight;
                int parent = i/2;
                while(i > 0 && heap[parent][0] > heap[i][0]) {
                    //swap
                    int temp1 = heap[parent][0];
                    int temp2 = heap[parent][1];
                    heap[parent][0] = heap[i][0];
                    heap[parent][1] = heap[i][1];
                    heap[i][0] = temp1;
                    heap[i][1] = temp2;
                    i = parent;
                    parent = i/2;
                }
            }
            break;
        }
    }
}

void relax(int heap[][2], int distance[][2], 
           int u, int v, int w, int n) {
    
    int weight = distance[u][0] + w;

    if(distance[v][0] > weight) {
        distance[v][0] = weight;        
        distance[v][1] = u;
        heap_decrease_key(heap, v, weight, n);
    }
}
void run_dijkstra(int adj_matrix[][3000], int distance[][2], int s, int n) {
    
    int heap[n][2];
    int S[n];
    
    for(int i = 0; i < n; i++) {
        distance[i][0] = -1;
        distance[i][1] = -1;
        heap[i][0] = -1;
        heap[i][1] = i;
        S[i] = 0;
    }
    distance[s][0] = 0;
    distance[s][1] = 0;
    heap[s][0] = 0;
    
    int heap_size = n;
    
    build_min_heap(heap, heap_size);
    
    while(heap_size > 0) {
        int u = -1;
        int min_val = heap_extract_min(heap, heap_size, &u);

        if (u == -1) {
           printf("unexpected case\n");
            break;
        }        
        S[u] = 1; 
        heap_size--;
        if(min_val == (int)-1) {
            break;
        } else {
            for (int v = 0; v < n; v++) {
                int w = adj_matrix[u][v];
                if (w != (int)-1 && S[v] != 1) {
                    relax(heap, distance, u, v, w, heap_size);
                }
            }
        }
    }
    
}


int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        int m; 
        scanf("%d %d",&n,&m);
        
        int adj_matrix[n][3000];
        int shortest_distance[n][2];
        
        //memset(adj_matrix, -1, sizeof(adj_matrix));
        //memset(shortest_distance, -1, sizeof(shortest_distance));
    
        
        for(int a1 = 0; a1 < m; a1++){
            int x; 
            int y; 
            int r; 
            scanf("%d %d %d",&x,&y,&r);
            if(adj_matrix[x-1][y-1] > r) {
                adj_matrix[x-1][y-1] = r;
                //comment this line to make the graph a directed one
                //adj_matrix[y-1][x-1] = r;
            }
        }
        int s; 
        scanf("%d",&s);
        run_dijkstra(adj_matrix, shortest_distance, s-1, n);
        
        for(int i = 0; i < n; i++) {
            printf("node: %d weight: %d\n", i+1, shortest_distance[i][0]);
        }
        printf("\n");
    }
    return 0;
}

