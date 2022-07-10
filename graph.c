#include "graph.h"



Graph new_graph(int vertices, int isOriented){
    Graph element;
    element = malloc(sizeof(element));
    if (element == NULL){
        printf("Error in memory allocation : FORCED EXIT");
        exit(1);
    }
    element->isOriented = isOriented;
    element->nbrVertices = vertices;
    element->neighbours = malloc(vertices * sizeof(AdjencyList*));

    if (element->neighbours == NULL){
        printf("Error in memory allocation : FORCED EXIT");
        exit(1);
    }
    int i;
    for (i = 1; i <= element->nbrVertices ; i++){
        element->neighbours[i - 1].being = NULL;
        return element; 
    }

}

int graph_is_empty(Graph* gr){
    return (gr == NULL) ? 1 : 0;
}

static NodeList add_node(int x){
    NodeList nl = malloc(sizeof(NodeListElement));
    if (nl == NULL){
        printf("Error in memory allocation : FORCED EXIT");
        exit(1);
    }
    nl->value = x;
    nl->next = NULL;
    return nl;
}

void free_graph(Graph gr){
    if (graph_is_empty(g) == 1){
        printf("The graph doesn't exist, nothing to free");
        return;
    }

    //.........
}





int main(void){
    return 0;
}