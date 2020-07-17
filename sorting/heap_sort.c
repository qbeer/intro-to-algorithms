#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>

struct MaxHeap
{
    unsigned int length;
    unsigned int heap_size;

    double *arr;
};

unsigned int nextPowerOfTwo(unsigned int a)
{
    a--;
    a |= a >> 1;
    a |= a >> 2;
    a |= a >> 4;
    a |= a >> 8;
    a |= a >> 16;
    a++;
    return a;
}

void maxHeapify(struct MaxHeap *heap, unsigned int index)
{
    unsigned int left = index << 1;
    unsigned int right = (index << 1) + 1;
    unsigned int largest = index;
    if (heap->heap_size > left && heap->arr[left] > heap->arr[index])
    {
        largest = left;
    }
    if (heap->heap_size > right && heap->arr[right] > heap->arr[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        double temp = heap->arr[index];
        heap->arr[index] = heap->arr[largest];
        heap->arr[largest] = temp;
        maxHeapify(heap, largest);
    }
    return;
}

void buildMaxHeap(struct MaxHeap *heap)
{
    heap->heap_size = heap->length;
    for (int i = heap->length / 2; i >= 0; --i)
    {
        maxHeapify(heap, i);
    }
}

struct MaxHeap initMaxHeap(unsigned int n_args, double *vec)
{
    struct MaxHeap heap;
    heap.heap_size = nextPowerOfTwo(n_args);
    heap.length = n_args;
    heap.arr = malloc(heap.heap_size * sizeof(double));

    for (int i = 0; i < n_args; ++i)
    {
        heap.arr[i] = vec[i];
    }

    //building maxHeap
    buildMaxHeap(&heap);

    return heap;
}

struct MaxHeap initMaxHeapFromArgsList(unsigned int n_args, ...)
{

    va_list ap;
    va_start(ap, n_args);

    double value;
    double *vec = malloc(sizeof(double) * n_args);
    value = va_arg(ap, double);
    vec[0] = value;
    for (int i = 1; i < n_args; ++i)
    {
        value = va_arg(ap, double);
        vec[i] = value;
    }

    va_end(ap);

    return initMaxHeap(n_args, vec);
}

void heapSort(struct MaxHeap *heap)
{
    while (heap->heap_size > 1)
    {
        double largestElement = heap->arr[0];
        heap->arr[0] = heap->arr[heap->heap_size - 1];
        heap->arr[heap->heap_size - 1] = largestElement;
        heap->heap_size--;
        maxHeapify(heap, 0);
    }
}

int main()
{
    struct MaxHeap myHeap = initMaxHeapFromArgsList(9, 1.2, 3.4, 2.1, -3.4, 5.4, 0.1, 756.12, 12.3, -273.15);
    heapSort(&myHeap);

    for (int vec_size = 4; vec_size < pow(2, 20); vec_size *= 2)
    {
        // alloc and fill vector
        double *pseudo_random_vec = malloc(sizeof(double) * vec_size);
        for (int i = 0; i < vec_size; ++i)
        {
            pseudo_random_vec[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
        }

        struct MaxHeap heap = initMaxHeap(vec_size, pseudo_random_vec);

        clock_t begin = clock();

        heapSort(&heap);

        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("%d\t%lf\n", vec_size, time_spent);
    }
}