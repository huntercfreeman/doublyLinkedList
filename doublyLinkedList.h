/*
Hunter Freeman

Attempt to recreate the C# class LinkedList<T> in C.
https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.linkedlist-1?view=netframework-4.8
*/

#ifndef doublyLinkedList
#define doublyLinkedList

typedef struct doublyLinkedListNode{
  int value;
  struct doublyLinkedListNode* next;
  struct doublyLinkedListNode* previous;
} doublyLinkedListNode;

typedef struct doublyLinkedListAPIStruct {
  void (* const Print)(doublyLinkedListNode* head);

  doublyLinkedListNode* (* const InsertInOrder)(doublyLinkedListNode *head, int value);

  // Adds the specified new node after the specified existing node in the LinkedList
  doublyLinkedListNode* (* const AddNodeAfter)(doublyLinkedListNode* current, doublyLinkedListNode* node);
  // Adds a new node containing the specified value after the specified existing node in the LinkedList
  doublyLinkedListNode* (* const AddValueAfter)(doublyLinkedListNode* current, int value);
  // Adds the specified new node before the specified existing node in the LinkedList
  doublyLinkedListNode* (* const AddNodeBefore)(doublyLinkedListNode* current, doublyLinkedListNode* node);
  // Adds a new node containing the specified value before the specified existing node in the LinkedList
  doublyLinkedListNode* (* const AddValueBefore)(doublyLinkedListNode* current, int value);

  // Adds the specified new node at the start of the LinkedList
  doublyLinkedListNode* (* const AddNodeStart)(doublyLinkedListNode* head, doublyLinkedListNode* node);
  // Adds a new node containing the specified value at the start of the LinkedList
  doublyLinkedListNode* (* const AddValueStart)(doublyLinkedListNode* head, int value);
  // Adds the specified new node at the end of the LinkedList
  doublyLinkedListNode* (* const AddNodeEnd)(doublyLinkedListNode* head, doublyLinkedListNode* node);
  // Adds a new node containing the specified value at the end of the LinkedList
  doublyLinkedListNode* (* const AddValueEnd)(doublyLinkedListNode* head, int value);

  // Removes all nodes from the LinkedList
  doublyLinkedListNode* (* const Clear)(doublyLinkedListNode* head);

  // Determines whether a value is in the LinkedList 0 is false anything else is true
  int (* const Contains)(doublyLinkedListNode* head, int value);

  // Copies the entire LinkedList to a compatible one-dimensional Array, starting at the specified index of the target array
  doublyLinkedListNode* (* const CopyToArray)(doublyLinkedListNode* head, int startingIndex);

  // Determines whether the specified object is equal to the current object. 0 is false anything else is true.
  int (* const Equal)(doublyLinkedListNode* headOne, doublyLinkedListNode* headTwo);

  // Returns the number of nodes actually contained in the LinkedList
  int (* const Count)(doublyLinkedListNode* head);

  // Finds the first node that contains the specified value
  doublyLinkedListNode* (* const FindFirst)(doublyLinkedListNode* head, int value);
  // Finds the last node that contains the specified value
  doublyLinkedListNode* (* const FindLast)(doublyLinkedListNode* head, int value);

  // Removes the specified node from the LinkedList
  doublyLinkedListNode* (* const RemoveNode)(doublyLinkedListNode* head, doublyLinkedListNode* node, int (* predicate)(doublyLinkedListNode *node1, doublyLinkedListNode *node2));
  // Removes the first occurrence of the specified value from the LinkedList
  doublyLinkedListNode* (* const RemoveFirst)(doublyLinkedListNode* head, int value);
  // Removes the last occurrence of the specified value from the LinkedList
  doublyLinkedListNode* (* const RemoveLast)(doublyLinkedListNode* head, int value);
  // Removes the starting (head) node;
  doublyLinkedListNode* (* const RemoveStart)(doublyLinkedListNode* head);
  // Removes the ending (tail) node;
  doublyLinkedListNode* (* const RemoveEnd)(doublyLinkedListNode* head);

  // Returns a string that describes the list.
  char* (* const ToString)(doublyLinkedListNode* head);
} doublyLinkedListAPIStruct;

doublyLinkedListAPIStruct const doublyLinkedListAPI;

#endif
