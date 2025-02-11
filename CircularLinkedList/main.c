#include <stdio.h>
#include <stdlib.h>

//This is Node structure which store each element in the List
struct Node {
    int data;
    struct Node* next;
};

//This is Circular Linked List structure which track the last element, current size, and capacity
typedef struct {
    struct Node* last; //The Node structure points to the last node in the Circular Linked List
    int size;          //Current size of the List
    int capacity;      //Capacity threshold at which the list "doubles"
} CircularLinkedList;

//This is function which create a Circular Linked List with initial capacity
CircularLinkedList* create_list() {
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    if (!list) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    list->last = NULL;
    list->size = 0;
    list->capacity = 4; //Set initial capacity(for example 4) - we can change the capacity from here
    return list;
}

//This is function which double the size of the list if needed when capacity is reached
void double_list_size(CircularLinkedList* list) {
    struct Node* current = list->last->next; //The list starts from the head
    int original_size = list->size;

    //This loop is over the original elements and add them directly without calling add_element function
    for (int i = 0; i < original_size; i++) {
        //This create a new Node directly and append it to the end of the list without recursive checks
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        if (!new_node) {
            printf("Memory allocation failed\n");
            return;
        }
        new_node->data = current->data;
        new_node->next = list->last->next; //Point new node to the head
        list->last->next = new_node;       //Insert new node after last element
        list->last = new_node;             //Update the last element to the new node

        current = current->next;
    }

    list->capacity *= 2; //This doubles the capacity of the List
    printf("List doubled. New capacity: %d\n", list->capacity);
}

//This is function which add an element to the Circular Linked List
struct Node* add_element(CircularLinkedList* list, int data) {
    if (!list) return NULL;

    if (list->size >= list->capacity) {
        double_list_size(list); //If the list is full, we double the capacity
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->data = data;

    if (list->last == NULL) {
        list->last = new_node;
        new_node->next = list->last;
    } else {
        //This block of code inserts the new node after the last element's next (head) and update the last element pointer
        new_node->next = list->last->next;
        list->last->next = new_node;
        list->last = new_node; //Update the last element to the new node
    }
    list->size++;
    return list->last;
}

//This is function which remove an element from the List by key
struct Node* remove_element(CircularLinkedList* list, int key) {
    if (!list || list->last == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* current = list->last->next; //Start from the head of the List(from the first Node)
    struct Node* prev = list->last;          //We make this to know which is the previous element of the current
    do {
        if (current->data == key) { //We check if the current Node data is equal to the key which we enter
            if (current == list->last && current->next == list->last) {
                //Make this if the List has only one Node
                free(current);
                list->last = NULL;
                list->size--;
                return NULL;
            }
            if (current == list->last) {
                //Update the last element if we're removing the last Node
                list->last = prev;
            }
            prev->next = current->next;
            free(current);
            list->size--;
            printf("Element %d removed\n", key);
            return list->last;
        }
        prev = current;
        current = current->next;
    } while (current != list->last->next);

    printf("Element %d not found\n", key);
    return list->last;
}

//This is function which search for an element by key
struct Node* search_element(CircularLinkedList* list, int key) {
    if (!list || list->last == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* current = list->last->next; // Again we start from the head of the List(from the first Node)
    do {
        if (current->data == key) {
            printf("Element %d found\n", key);
            return current;
        }
        current = current->next;
    } while (current != list->last->next);

    printf("Element %d not found\n", key);
    return NULL;
}

//This is function which traverse and display the Circular Linked List
void traverse(CircularLinkedList* list) {
    if (!list || list->last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = list->last->next; //And again we start from the head of the List(from the first Node)
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->last->next);
    printf("(back to start)\n");
}

//This is main function where all the other functions are called
int main() {
    //First we create a circular linked list
    CircularLinkedList* list = create_list();
    if (!list) return 1;

    //Call the add_element function to add elements in the Circular Linked List
    add_element(list, 10);
    add_element(list, 20);
    add_element(list, 30);
    add_element(list, 40);

    printf("List after adding elements:\n");
    traverse(list); //Here we call the traverse function to see the whole Circular Linked List

    //Call the search_element function to search for the elements in the Circular Linked List
    search_element(list, 20);
    search_element(list, 100);

    //Call the remove_element function to remove elements from the Circular Linked List
    remove_element(list, 30);
    printf("List after removing element 30:\n");
    traverse(list); //Here we again call the traverse function to see the whole Circular Linked List after we used remove_element function

    free(list);

    return 0;
}
