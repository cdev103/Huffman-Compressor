#include <stdio.h>
#include "heap.h"

// Swap two integers 
static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Move an element upward 
static void heapifyUp(MinHeap *heap, int index)
{
    int parent;

    while (index > 0) {
        parent = (index - 1) / 2;

        if (heap->arr[parent] <= heap->arr[index])
            break;

        swap(&heap->arr[parent], &heap->arr[index]);
        index = parent;
    }
}

// Move an element downward
static void heapifyDown(MinHeap *heap, int index)
{
    int left, right, smallest;

    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < heap->size &&
            heap->arr[left] < heap->arr[smallest]) {
            smallest = left;
        }

        if (right < heap->size &&
            heap->arr[right] < heap->arr[smallest]) {
            smallest = right;
        }

        if (smallest == index)
            break;

        swap(&heap->arr[index], &heap->arr[smallest]);
        index = smallest;
    }
}

void initHeap(MinHeap *heap)
{
    heap->size = 0;
}

void insert(MinHeap *heap, int value)
{
    if (heap->size >= MAX_SIZE) {
        printf("Heap is full.\n");
        return;
    }

    heap->arr[heap->size] = value;
    heap->size++;

    heapifyUp(heap, heap->size - 1);
}

int extractMin(MinHeap *heap)
{
    int min;

    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    min = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    if (heap->size > 0)
        heapifyDown(heap, 0);

    return min;
}

int getMin(const MinHeap *heap)
{
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    return heap->arr[0];
}

void displayHeap(const MinHeap *heap)
{
    int i;

    for (i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }

    printf("\n");
}

int isEmpty(const MinHeap *heap)
{
    return heap->size == 0;
}
