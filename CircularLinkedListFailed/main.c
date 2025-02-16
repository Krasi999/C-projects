#include <stdio.h>
#include <stdlib.h>

// Node structure to store each element in the list
struct Node {
    int data;
    struct Node* next;
};

// Circular linked list structure to track the tail, current size, and capacity
typedef struct {
    struct Node* tail; // Points to the last node in the circular linked list
    int size;          // Current size of the list
    int capacity;      // Capacity threshold at which the list "doubles"
} CircularLinkedList;

// Function to create a circular linked list with initial capacity
CircularLinkedList* create_list(int capacity) {
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    if (!list) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    list->tail = NULL;
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// Function to add an element to the circular linked list
struct Node* add_element(CircularLinkedList* list, int data) {
    if (!list) return NULL;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->data = data;

    if (list->tail == NULL) {
        // First node in the list
        list->tail = new_node;
        new_node->next = list->tail; // Points to itself
    } else {
        // Insert the new node after the tail's next (head) and update the tail pointer
        new_node->next = list->tail->next;
        list->tail->next = new_node;
        list->tail = new_node; // Update the tail to the new node
    }
    list->size++;

    // Check if the list has reached its capacity
    if (list->size >= list->capacity) {
        double_list_size(list); // Double the list size by duplicating elements
    }
    return list->tail;
}

// Function to double the list size by duplicating each element
void double_list_size(CircularLinkedList* list) {
    if (!list || list->tail == NULL) return;

    struct Node* current = list->tail->next; // Start from the head
    int original_size = list->size;

    // Loop over the original elements and add duplicates
    for (int i = 0; i < original_size; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        if (!new_node) {
            printf("Memory allocation failed\n");
            return;
        }
        new_node->data = current->data;
        new_node->next = list->tail->next; // Point new node to the head
        list->tail->next = new_node;       // Insert new node after tail
        list->tail = new_node;             // Update the tail to the new node

        current = current->next->next;
        list->size++;
    }

    list->capacity *= 2; // Update the capacity
    printf("List doubled. New capacity: %d\n", list->capacity);
}

// Function to remove an element from the list by key
struct Node* remove_element(CircularLinkedList* list, int key) {
    if (!list || list->tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* current = list->tail->next; // Start from the head
    struct Node* prev = list->tail;

    do {
        if (current->data == key) { // If the current node has the key
            if (current == list->tail && current->next == list->tail) {
                // If it's the only node
                free(current);
                list->tail = NULL;
                list->size--;
                return NULL;
            }
            if (current == list->tail) {
                // Update tail if we're removing the last node
                list->tail = prev;
            }
            prev->next = current->next;
            free(current);
            list->size--;
            printf("Element %d removed\n", key);
            return list->tail;
        }
        prev = current;
        current = current->next;
    } while (current != list->tail->next);

    printf("Element %d not found\n", key);
    return list->tail;
}

// Function to search for an element by key
struct Node* search_element(CircularLinkedList* list, int key) {
    if (!list || list->tail == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* current = list->tail->next; // Start from the head
    do {
        if (current->data == key) {
            printf("Element %d found\n", key);
            return current;
        }
        current = current->next;
    } while (current != list->tail->next);

    printf("Element %d not found\n", key);
    return NULL;
}

// Function to traverse and display the circular linked list
void traverse(CircularLinkedList* list) {
    if (!list || list->tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = list->tail->next; // Start from the head
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->tail->next);
    printf("(back to start)\n");
}

int main() {
    // Create a circular linked list with an initial capacity of 4
    CircularLinkedList* list = create_list(4);
    if (!list) return 1;

    // Adding elements to the circular linked list
    add_element(list, 10);
    add_element(list, 20);
    add_element(list, 30);
    add_element(list, 40);

    printf("List after adding elements:\n");
    traverse(list);

    // Add more elements to trigger doubling
    add_element(list, 50);

    printf("List after adding element to trigger doubling:\n");
    traverse(list);

    // Searching for an element
    search_element(list, 20);
    search_element(list, 100);

    // Removing an element
    remove_element(list, 30);
    printf("List after removing element 30:\n");
    traverse(list);

    // Cleanup: Remove all elements and free the list
    while (list->tail != NULL) {
        remove_element(list, list->tail->next->data);
    }
    free(list);

    return 0;
}
