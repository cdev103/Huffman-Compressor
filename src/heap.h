#ifndef HEAP_H
#define HEAP_H


#define MAX_SIZE 256

typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

// Initialize the heap 
void initHeap(MinHeap *heap);

// Insert an element into the heap 
void insert(MinHeap *heap, int value);

// Remove and return the minimum element
int extractMin(MinHeap *heap);

// Return the minimum element without removing it
int getMin(const MinHeap *heap);

// Display the heap
void displayHeap(const MinHeap *heap);

// Check if the heap is empty
int isEmpty(const MinHeap *heap);

#endif