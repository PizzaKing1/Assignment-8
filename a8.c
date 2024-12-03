#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Edge {
    int label;
    int * weights;
    struct Edge* next;
    int num_weights;
} Edge;

typedef struct Graph {
    Edge** adj_list;
    int num_vertices;
} Graph;

typedef struct {
    int label;
    int distance;
    int t;
    int* predecessor;
} HeapNode;

typedef struct {
    int size;
    int capacity;
    int *pos;
    HeapNode **heap;
    int size;
} MinHeap;

HeapNode* newHeapNode(int v, int dist) {
    HeapNode* minHeapNode = (HeapNode*)malloc(sizeof(HeapNode));
    minHeapNode->label = v;
    minHeapNode->distance = dist;
    //predecesor?
    return minHeapNode;
}
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->heap = (HeapNode**)malloc(capacity * sizeof(HeapNode*));
    return minHeap;
}

void swap(HeapNode** a, HeapNode** b) {
    HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->heap[left]->distance < minHeap->heap[smallest]->distance) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->heap[right]->distance < minHeap->heap[smallest]->distance) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&minHeap->heap[index], &minHeap->heap[smallest]);
        minHeapify(minHeap, smallest);
    }
}

HeapNode extractMin(MinHeap* minHeap) {
    if (minheap->size == 0) {
        HeapNode emptyNode = {-1, INT_MAX};
        return emptyNode;
    }

    HeapNode root = minHeap->heap[0];
    minHeap->heap[0] = minHeap->heap[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return root;
}

void insertMinHeap(MinHeap* minHeap, HeapNode newNode) {
    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->heap[i] = newNode;

    while (i != 0 && minHeap->heap[(i-1)/2].distance > minHeap->heap[i].distance) {
        swap(&minHeap->heap[i], &minHeap -> [(i-1)/2]);
        i = (i-1)/2;
    }
}


void add_edge(Graph *graph, int src, int dest, int t) {
    Edge *newNode = malloc(sizeof(Edge));
    newNode->label = dest; //Adjust tp include .1/.2 state
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}


typedef struct gnode {
    int label;
    //int weight;
    struct gnode* next;
} gnode;

int count; 
int c;
struct Block* arr;
int i;
char* buffer[20];


Graph* create_graph(int nv, int nw){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph -> num_vertices = nv * nw;
    graph -> adj_list = (Edge**)malloc(nv * nw * sizeof(Edge*));

    //initialize zero
    for(int i = 0; i < nv; i++) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

int main(int argc, char** argv) {
    int nv = 0;
    int nw = 0;
    int src = 0;
    int dest = 0;
    int weight

    //open file
    FILE* fp;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Error Opening File\n");
        return 0;
    }

    //Read values from file
    if(fscanf(fp, "%d %d\n", &nv, &nw) != 2){
        fprintf(stderr, "scanning first line failed");
        return 0;
    }
    
    //create graph
    Graph *graph = create_graph(nv, nw);

    //read edges
    fscanf(fp, "%d %d ", &src, &dest);
    for (i = 0; i < nw; i++) {
        if(fscanf(fp, "%d ", &weight) != 1) {
            printf("Error reading integer from file");
            break;
        }
        add_edge(graph, src, dest, (i % nw) + 1)//Add cyclical weights here!
    }

    fclose(fp);

    //HeapNode* heap = 0;

}
    
void enqueue(int* arr, int i) {
    int temp = arr[i];
    int j = i;
 
    while (j > 0 && arr[(j-1)/2] < temp) {
        arr[j] = arr[(j-1)/2];
        j = (j-1)/2;
    }
    arr[j] = temp;
}

void dequeue(int* arr, int n) {
    int temp = arr[n];
    arr[n] = arr[0];
    arr[0] = temp;

    n--;

    int i = 0, j;
    while ((j = 2*i+1) <= n) {
        if (j < n && arr[j] < arr[j+1])
            j = j+1;
        if (temp >= arr[j]) break;
        else {
            arr[i] = arr[j];
            i = j;
        }
    }
    arr[i] = temp;
}


void dijkstra(int **graph, int V, int source) {
    int dist[V];
    MinHeap* minHeap = createMinHeap(V);

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        minHeap->nodes[i] = newNode(i, dist[i]);
    }

    struct tnode arr[SIZE];
    int n = SIZE;
    
}
    

