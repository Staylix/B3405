
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)
#define PARENT(i) ((i)-1)/2


typedef struct
{
    int allocated; /* current allcoation of array */
    int filled;    /* number of items present in the binheap */
    int *array;    /* array of values */
} BinaryHeap;


/* Init allocates the structure BinaryHeap and
* also the membre array with the given size
* it also fill allocated (size) and intializes
* filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
* the array is reallocated if necessary (allocated changed
* with respect to the new size )
* filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
* otherwise it return 1 and fills *val with the maximum
* value present in the binary heap
* filled is decremented by 1  and the max value is removed
* from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);
void real(BinaryHeap * heap);



int main(void)
{
    char lecture[100];
    int val;
    BinaryHeap * heap;
    heap = Init(2);
    
    
    /*InsertValue(heap, 72);
    InsertValue(heap, 50);
    InsertValue(heap, 20);
    InsertValue(heap, 80);
    InsertValue(heap, 100);
    InsertValue(heap, 8);
    InsertValue(heap, 7);
    InsertValue(heap, 5);
    InsertValue(heap, 11);
    printf("\n");               //Facilite le test

*/
    scanf("%99s", lecture);
    while (strcmp(lecture, "bye") != 0)
    {
        if (strcmp(lecture, "insert") == 0)
        {
            scanf("%99s", lecture);
            val = strtol(lecture, NULL, 10);
            InsertValue(heap, val);
        }
        else if (strcmp(lecture, "extract") == 0)
        {
            if (ExtractMax(heap, &val))
            {
                printf("%d\r\n", val);
            }
        }
        scanf("%99s", lecture);
    }
    Destroy(heap);
    return 0;
}


void real(BinaryHeap * heap)
{
    int i;
    int size = heap->allocated;
    int *tmp = (int *) malloc(2*size*sizeof(int));
    if(tmp == NULL){printf("Error in real"); exit(-1);}
    for (i=0;i<size; i++)
    {
        tmp[i] = heap->array[i];
    }
    free(heap->array);
    heap->array = tmp;
    heap->allocated = 2*size;

    return;
}


BinaryHeap * Init(int size)
{
    BinaryHeap * heap;
    heap = (BinaryHeap*)malloc(sizeof(BinaryHeap));
    if (heap == NULL)
        exit(-1);
    heap->array = (int*)malloc(sizeof(int)*size);
    if (heap->array == NULL)
        exit(-1);
    heap->allocated = size;
    heap->filled = 0;
    return heap;
}



void swap(int *array, int a, int b)
{
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}


void heapify(int *array, int n, int i)
{
    if (LEFT(i) >= n) return;

    if (RIGHT(i) < n)
    {
        if (array[LEFT(i)] > array[i] && array[LEFT(i)] > array[RIGHT(i)])
        {
            swap(array, i, LEFT(i));
            heapify(array, n, LEFT(i));
            return;
        }
        else if (array[RIGHT(i)] > array[i] && array[RIGHT(i)] > array[LEFT(i)])
        {
            swap(array, i, RIGHT(i));
            heapify(array, n, RIGHT(i));
            return;
        }
        else
            return;
    }

    else
    {
        if (array[LEFT(i)] > array[i])
        {
            swap(array, i, LEFT(i));
            return;
        }
    }
}



void InsertValue(BinaryHeap * heap, int value)
{
    if (heap->filled >= heap->allocated-1)
    {
        real(heap);
    }
    heap->array[heap->filled] = value;
    int i = heap->filled;
    while (PARENT(i) >= 0 && heap->array[i] > heap->array[PARENT(i)])
    {
        swap(heap->array, i, PARENT(i));
        i = PARENT(i);
    }
    heap->filled++;
    //printf("%d\t%d\t", heap->allocated, heap->filled);

    //for (i = 0; i < heap->filled; i++) printf("%d ", heap->array[i]);
}



int ExtractMax(BinaryHeap * heap, int *res)
{
    if (heap->filled == 0) return 0;
    *res = heap->array[0];
    heap->filled--;
    swap(heap->array, 0, heap->filled);

    heapify(heap->array, heap->filled, 0);

    return 1;
}



void Destroy(BinaryHeap * heap)
{
    free(heap->array);
    free(heap);
    return;
}
