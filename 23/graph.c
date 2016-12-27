#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mylib.h"

/**
 *  Global variable with file scope.
 * (exists outside the recursion stack)
 * 
 */
static int step;

/**
 * Vertex datatype.
 * 
 */
struct vertex{
    int predecessor;
    int distance;
    state_t state;
    int finish;
};


/**
 * Graph datatype.
 * 
 */
struct graphrec{
   int **edges;
   int size;
   struct vertex *vertices;
};


/**
 * Creates a new graph by assigning memory to components, initialising
   the adjacency matrix with zeroes and setting the vertices to their 
   initial state.
 * 
 * 
 * @param v how many vertices the graph will have(graph size).
 * @return g return a graph with no edges. 
 */
graph graph_new(int numOfvertices){
    int i,j;
   
    /*create the graph struct*/
    graph g = emalloc(sizeof *g);
    /*set size of graph to amount of vertices*/
    g->size = numOfvertices;
    /*memory alloc to vertices struct*/
   
    g->vertices = emalloc(g->size*sizeof g->vertices[0]);

    /*adjacency array allocation*/
   
    g->edges = emalloc(g->size*sizeof g->edges[0]);

    /*initialize edges*/
    for(i=0; i<g->size; i++){
        g->edges[i] = emalloc(g->size*sizeof g->edges[0][0]);
        for(j = 0; j < g->size;j++){	
            g->edges[i][j] = 0;
        }
    }
   
    /*initialize vertices*/
    for(i=0; i<g->size; i++){
        g->vertices[i].predecessor = -1;
        g->vertices[i].distance = -1;
        g->vertices[i].state = UNVISITED;
        g->vertices[i].finish = 0;      
    }
    return g;
}

/**
 * Adds an edge from vertices u to v (for directed graphs).
 *
 * @param g the graph requiring edges.
 * @param u first vertex.
 * @param v second vertex.
 */
void graph_directional_edge(graph g, int u, int v){
   g->edges[u][v] = 1;
}

/**
 * Adds bidirectional edges from vertices u to v (for undirected graphs).
 *
 * @param g  the graph requiring edges.
 * @param u  first vertex.
 * @param v  second vertex.
 */

void graph_bidirectional_edges(graph g, int u, int v){
   g->edges[u][v] = 1;
   g->edges[v][u] = 1;
}

/**
 * Frees the memory the graph was using.
 *
 * @param g the graph to free memory from.
 */
void graph_free(graph g){
   int i;
   for(i=0; i<g->size; i++){
      free(g->edges[i]);
   }
   free(g->edges);
   free(g->vertices);
   free(g);
}

/**
 * Prints the graph (as if it where an adjaceny list).
 *
 * @param g the graph to be printed.
 */
void graph_print(graph g){
   int i,j,k;
    
   printf("adjacency list:\n");
   for(i=0; i<g->size; i++){
      k = 0;
      printf("%d | ",i);
      for (j=0; j<g->size; j++){
         if (g->edges[i][j] == 1){
            if (k==0){
      
               printf("%d",j);
               k++;
            }
            else{
               printf(", %d",j);
            }
         }
      }
      printf("\n");
   }
   printf("vertex distance pred finish\n");
   for(i=0; i<g->size; i++){
       printf("%5d%8d%5d%6d\n", i, g->vertices[i].distance,
              g->vertices[i].predecessor, g->vertices[i].finish);    
   }
}

/**
 * Recursively visits vertices and and their neighbours  
 * updating their visit states.
 *
 * @param g the graph to perform visits on.
 * @param v the vertex to be visited.
 */
void visit(graph g, int v){
    int i;
    /*set v’s state as visited_self*/
    g->vertices[v].state = VISITED_SELF;
    /*increment step*/
    step++;
    /*set the distance to the vertex to step*/
    g->vertices[v].distance = step;
    /*for each vertex u adjacent to v*/
    for (i=0;i<g->size;i++){
        /*if the the vertex is unvisited*/
        if ((g->edges[v][i] == 1) && (g->vertices[i].state == UNVISITED)){
            /*set predecessor as v*/
            g->vertices[i].predecessor = v;
            /*recursive call*/
            visit(g,i);
        }
    }
    step++;
    /*set v’s state as visited_descendants*/
    g->vertices[v].state = VISITED_DESCENDANTS;
    /*set v’s finish value to step*/
    g->vertices[v].finish = step;
}

/**
 * Performs a depth first search on the input graph.
 * 
 * @param g the graph to be searched
 */
void graph_dfs(graph g){
   int i;
   /*for each vertex in the graph*/
   for (i=0;i<g->size;i++){
       /*set state to unvisited*/
      g->vertices[i].state = UNVISITED;
      /*set predecessor to non-existent (-1)*/
      g->vertices[i].predecessor = -1;
   }
   /*initialize step*/
   step = 0;
   /*for each vertex in the graph*/
   for (i=0;i<g->size;i++){
       /*if vertex state is unvisited*/
      if (g->vertices[i].state == UNVISITED){
          /*use the visit method*/
         visit(g,i);
      }
   }
}


