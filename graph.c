#include "graph.h"


/**
 * @brief define a new graph 
 * 
 * @param vertices 
 * @param isOriented 
 * @return Graph 
 */
Graph new_graph(int vertices, int isOriented){
    Graph element;
    element = malloc(sizeof(element));
    if (element == NULL){
        printf("Error in memory allocation : FORCED EXIT");
        exit(1);
    }
    element->isOriented = isOriented;
    element->nbrVertices = vertices;
    element->neighbours = malloc(vertices * sizeof(AdjencyListElement));

    if (element->neighbours == NULL){
        printf("Error in memory allocation : FORCED EXIT");
        exit(1);
    }
    int i;
    for (i = 1; i <= element->nbrVertices ; i++){
        element->neighbours[i - 1].start = NULL; 
        return element; 
    }

}

/**
 * @brief returns 1 if the graph is empty : 0 if not
 * 
 * @param gr 
 * @return int 
 */
int graph_is_empty(Graph* gr){
    return (gr == NULL) ? 1 : 0;
}

/**
 * @brief creates a node in the graph
 * 
 * @param x 
 * @return NodeListElement* 
 */
static NodeListElement* add_node(int x){
    NodeList nl = malloc(sizeof(NodeListElement));
    if (nl == NULL){
        printf("Error in memory allocation : FORCED EXIT");
        exit(1);
    }
    nl->value = x;
    nl->next = NULL;
    return nl;
}

/**
 * @brief create an edge in the graph
 * 
 * @param gr 
 * @param source 
 * @param destination 
 */
void add_edge(Graph gr, int source, int destination){
    NodeListElement* node = add_node(destination);
    node->next = gr->neighbours[src-1].start; // the vertice next to node is going to be equal to the start of the list 
    gr->neighbours[src-1].start = n; // the start of the list is going to be "node"

    if (g->isOriented == 0){ // if the graph isn't oriented, the same thing goes both ways
        node = add_node(source);
    node->next = gr->neighbours[destination-1].start;
    gr->neighbours[destination-1].start = n;
    }
}

/**
 * @brief free the whole graph in memory
 * 
 * @param gr 
 */
void free_graph(Graph gr){
    if (graph_is_empty(g) == 1){
        printf("The graph doesn't exist, nothing to free");
        return;
    }

    // if there's neighbours vertices
    if (gr->neighbours){
        int i;
        for (i = 1; gr->nbrVertices + 1; i++){
            NodeListElement* n = gr->neighbours[i - 1].begin;
            while(n != NULL){
                NodeListElement* tmp = n;
                n = n->next;
                free(tmp);
            }
        }
        // freeing the whole adgency list after freeing every element of it
        free(gr->neighbours);
    }
    // freeing the whole graph
    free(gr);
}

/**
 * @brief prints the graph
 * 
 * @param gr 
 */
void print_graph(Graph gr){
    if(graph_is_empty(gr)){
        printf("I can't print a non-existing graph..");
        return;
    }
    int i;
    for(i = 1; i < gr->nbrVertices + 1; i++){
        NodeListElement* n = gr->neighbours[i -1].start;
        printf("(%d)", i);
        while (n != NULL){
            printf("%d", n->value);
            n = n->next
        }
    }
}


int main(void){
    return 0;
}