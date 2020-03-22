#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

int main()
{
  printf("Begin the list with 5\n");
  doublyLinkedListNode* head = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));
  head->value = 5;
  head->next = NULL;
  doublyLinkedListAPI.Print(head);

  printf("Insert 10 after 5\n");
  head = doublyLinkedListAPI.InsertAfterNode(head, 10);
  doublyLinkedListAPI.Print(head);

  printf("Insert in order 7\n");
  head = doublyLinkedListAPI.InsertInOrder(head, 7);
  doublyLinkedListAPI.Print(head);

  printf("Delete in order 6\n");
  head = doublyLinkedListAPI.DeleteInOrder(head, 6);
  doublyLinkedListAPI.Print(head);

  printf("Delete in order 10\n");
  head = doublyLinkedListAPI.DeleteInOrder(head, 10);
  doublyLinkedListAPI.Print(head);

  printf("Delete in order 5\n");
  head = doublyLinkedListAPI.DeleteInOrder(head, 5);
  doublyLinkedListAPI.Print(head);

  printf("Delete in order 7\n");
  head = doublyLinkedListAPI.DeleteInOrder(head, 7);
  doublyLinkedListAPI.Print(head);

  return 0;
}
