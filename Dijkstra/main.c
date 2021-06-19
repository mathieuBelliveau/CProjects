#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4

typedef struct Nodes node;

struct Nodes
{
    int value;
    node * origin;

};

void create_prior_queue(int*map, int*q);
void sort_queue(int*q);

int main()
{
    //int exq[2][2] = {{0,8},{0,7}};
    int blah[V][V] = {{0,8,7,0},
                    {8,0,3,6},
                    {7,3,0,5},
                    {0,6,5,0}};
    //Vector by [Node,origin,value]
    int q [V][2];
    int done [V][2];

    create_prior_queue(&blah, &q);

    for (int i = 0; int < V; i++)
    {
        curr = *(q[i][1])
    }


    //printf("%d\n",exq[0][1]);


    return 0;
}

void sort_queue(int*q)
{
    int temp[2];
    for(int i = 0; i<2-1; i++)
    {
        int * first = ((q+1)+i*2);
        int * second = ((q+1)+i*2+2);

        if(*first > *second)
        {
            temp[0] = *(first-1);
            temp[1] = *first;

            *(first-1) = *(second-1);
            *(first) = *(second);

            *(second-1) = temp[0];
            *(second) = temp[1];
        }

    }
}

void create_prior_queue(int* map, int* q)
{
    //Filling all queue values with [-1,intmax]
    for (int i = 0;i<V;i++)
    {
        *(q+i*2) = -1;
        *((q+1)+i*2) = INT_MAX;
    }
}
