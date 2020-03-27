#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"
#include "stringBuilder.h"

static doublyLinkedListNode* AddNodeAfter(doublyLinkedListNode* current, doublyLinkedListNode* node)
{
  if(current == NULL) return NULL;

  node->next = current->next;
  node->next->previous = node;
  node->previous = current;

  current->next = node;

  return current;
}

static doublyLinkedListNode* AddValueAfter(doublyLinkedListNode* current, int value)
{
  if(current == NULL) return NULL;

  doublyLinkedListNode* temporary = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));
  temporary->value = value;
  temporary->next = current->next;
  temporary->next->previous = temporary;
  temporary->previous = current;

  current->next = temporary;

  return current;
}

static doublyLinkedListNode* AddNodeBefore(doublyLinkedListNode* current, doublyLinkedListNode* node)
{
  if(current == NULL) return NULL;

  current->previous->next = node;
  current->previous = node;
  node->next = current;

  return current;
}

static doublyLinkedListNode* AddValueBefore(doublyLinkedListNode* current, int value)
{
  if(current == NULL) return NULL;

  doublyLinkedListNode* temporary = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));
  temporary->value = value;
  current->previous->next = temporary;
  temporary->previous = temporary;
  temporary->next = current;

  return current;
}

static doublyLinkedListNode* AddNodeFirst(doublyLinkedListNode* head, doublyLinkedListNode* node)
{
  if(head == NULL) return NULL;

  head->previous = node;
  node->next = head;
  node->previous = NULL;

  return node;
}

static doublyLinkedListNode* AddValueFirst(doublyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  doublyLinkedListNode* node = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));

  head->previous = node;

  node->value = value;
  node->next = head;
  node->previous = NULL;

  return node;
}

static doublyLinkedListNode* AddNodeLast(doublyLinkedListNode* head, doublyLinkedListNode* node)
{
  if(head == NULL) return NULL;

  if(head->next == NULL)
  {
    head->next = node;
    node->next = NULL;
    node->previous = head;

    return head;
  }

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;
  }

  temporary->next = node;
  node->next = NULL;
  node->previous = temporary;

  return head;
}

static doublyLinkedListNode* AddValueLast(doublyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  if(head->next == NULL)
  {
    doublyLinkedListNode* node = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));
    node->value = value;
    node->next = NULL;
    node->previous = head;

    head->next = node;


    return head;
  }

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;
  }

  doublyLinkedListNode* node = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));
  node->value = value;
  node->next = NULL;
  node->previous = temporary;

  temporary->next = node;

  return head;
}

static doublyLinkedListNode* Clear(doublyLinkedListNode* head)
{
  if(head == NULL) return NULL;

  if(head->next == NULL)
  {
    free(head);
    head = NULL;

    return NULL;
  }

  doublyLinkedListNode* temporary1 = head;
  while(temporary1->next != NULL)
  {
    doublyLinkedListNode* temporary2 = temporary1->next;

    free(temporary1);

    temporary1 = temporary2;
  }

  free(temporary1);

  return NULL;
}

static int Contains(doublyLinkedListNode* head, int value)
{
  if(head == NULL) return 0;

  if(head->value == value)
  {
    return 1;
  }

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;

    if(temporary->value == value) return 1;
  }

  return 0;
}

static doublyLinkedListNode* CopyToArray(doublyLinkedListNode* head, int startingIndex)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static int Equal(doublyLinkedListNode* headOne, doublyLinkedListNode* headTwo)
{
  if((headOne == NULL) && (headTwo == NULL)) return 1;
  if((headOne == NULL) || (headTwo == NULL)) return 0;

  int equivalence = 1;

  doublyLinkedListNode* temporary1 = headOne;
  doublyLinkedListNode* temporary2 = headTwo;

  if(temporary1->value != temporary2->value) equivalence = 0;

  while(equivalence && (temporary1->next != NULL) && (temporary2->next != NULL))
  {
    temporary1 = temporary1->next;
    temporary2 = temporary2->next;

    if(temporary1->value != temporary2->value) equivalence = 0;
  }

  if(equivalence != 0)
  {
    if((temporary1->next == NULL) && (temporary2->next == NULL)) return 1;
    if((temporary1->next == NULL) || (temporary2->next == NULL)) return 0;
  }

  return equivalence;
}

static int Count(doublyLinkedListNode* head)
{
  if(head == NULL) return 0;

  int count = 1;

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;

    count++;
  }

  return count;
}

static doublyLinkedListNode* FindFirst(doublyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  if(head->value == value) return head;

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;
    if(temporary->value == value) return temporary;
  }

  return NULL;
}

static doublyLinkedListNode* FindLast(doublyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  doublyLinkedListNode* foundNode = NULL;

  if(head->value == value) foundNode = head;

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;
    if(temporary->value == value) foundNode = temporary;
  }

  return foundNode;
}

static doublyLinkedListNode* RemoveNode(doublyLinkedListNode* head, doublyLinkedListNode* node, int (* predicate)(doublyLinkedListNode *node1, doublyLinkedListNode *node2))
{
  if(head == NULL) return NULL;
  if(predicate == NULL) return NULL;

  if(predicate(head, node))
  {
    doublyLinkedListNode* temporary = head->next;
    temporary->previous = NULL;

    free(head);
    head = NULL;

    return temporary;
  }

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;
    if(predicate(temporary, node))
    {
      temporary->previous->next = temporary->next;
      free(temporary);
      temporary = NULL;

      return head;
    }
  }

  return head;
}

static doublyLinkedListNode* RemoveFirst(doublyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  if(head->value == value)
  {
    doublyLinkedListNode* newHead = head->next;
    newHead->previous = NULL;
    free(head);
    head = NULL;

    return newHead;
  }

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;

    if(temporary->value == value)
    {
      temporary->previous->next = temporary->next;
      temporary->next->previous = temporary->previous;
      free(temporary);
      temporary = NULL;

      return head;
    }
  }

  return head;
}

static doublyLinkedListNode* RemoveLast(doublyLinkedListNode* head, int value)
{
  if(head == NULL) return NULL;

  doublyLinkedListNode* removeNode;
  int removeNodeIsHead;

  if(head->value == value)
  {
    removeNode = head;
    removeNodeIsHead = 1;
  }

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;

    if(temporary->value == value)
    {
      removeNodeIsHead = 0;
      removeNode = temporary;
    }
  }

  if(removeNodeIsHead)
  {
    if(head->next != NULL)
    {
      doublyLinkedListNode* newHead = head->next;
      newHead->previous = NULL;
      free(head);
      head = NULL;

      return newHead;
    }
    else
    {
      free(head);
      head = NULL;

      return NULL;
    }
  }

  removeNode->previous->next = removeNode->next;
  removeNode->next->previous = removeNode->previous;
  free(removeNode);
  removeNode = NULL;

  return head;
}

static doublyLinkedListNode* RemoveStart(doublyLinkedListNode* head)
{
  if(head == NULL) return NULL;

  if(head->next != NULL)
  {
    doublyLinkedListNode* newHead = head->next;
    newHead->previous = NULL;
    free(head);
    head = NULL;

    return newHead;
  }
  else
  {
    free(head);
    head = NULL;

    return NULL;
  }
}

static doublyLinkedListNode* RemoveEnd(doublyLinkedListNode* head)
{
  if(head == NULL) return NULL;

  if(head->next == NULL)
  {
    doublyLinkedListNode* newHead = head->next;
    newHead->previous = NULL;
    free(head);
    head = NULL;

    return NULL;
  }

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    temporary = temporary->next;
  }

  temporary->previous->next = NULL;
  free(temporary);
  temporary = NULL;

  return head;
}

// Look into freeing the stringBuilder
static char* ToString(doublyLinkedListNode* head)
{
  if(head == NULL) return NULL;

  stringBuilder* stringBuilder = malloc(sizeof(stringBuilder));
  stringBuilderAPI.AppendInt(stringBuilder, head->value);

  doublyLinkedListNode* temporary = head;

  while(temporary->next != NULL)
  {
    stringBuilderAPI.AppendChars(stringBuilder, "->");

    temporary = temporary->next;
    stringBuilderAPI.AppendInt(stringBuilder, temporary->value);
  }
  //stringBuilderAPI.AppendChars(stringBuilder, "\n");

  return stringBuilder->string;
}

static doublyLinkedListNode* DeleteInOrder(doublyLinkedListNode *head, int value)
{
  if(head == NULL) return NULL;

  if(head->value == value)
  {
    doublyLinkedListNode *temporary = head->next;
    free(head);
    head = NULL;

    return temporary;
  }

  doublyLinkedListNode* temporary = head;
  while(temporary->next != NULL)
  {
    if(temporary->next->value == value)
    {
        temporary->next = temporary->next->next;
        return head;
    }
    temporary = temporary->next;
  }

  return head;
}

static doublyLinkedListNode* InsertInOrder(doublyLinkedListNode *head, int value)
{
  if(head == NULL) return NULL;

  if(head->value >= value)
  {
    doublyLinkedListNode* temporary = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));
    temporary->next = head;
    temporary->value = value;

    return temporary;
  }

  doublyLinkedListNode* temporary = head;
  while((temporary->next != NULL) && (temporary->next->value < value))
  {
    temporary = temporary->next;
  }

  doublyLinkedListNode* newNode = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));
  newNode->next = temporary->next;
  newNode->value = value;

  temporary->next = newNode;

  return head;
}

static doublyLinkedListNode* InsertAfterNode(doublyLinkedListNode* current, int value)
{
  if(current == NULL) return NULL;

  doublyLinkedListNode* temporary = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));
  temporary->next = current->next;
  temporary->value = value;

  current->next = temporary;

  return current;
}

static void Print(doublyLinkedListNode* head)
{
  if(head == NULL) return;

  printf("%d", head->value);
  doublyLinkedListNode* current = head;
  while(current->next != NULL)
  {
    current = current->next;
    printf("->%d", current->value);
  }
  printf("\n");
}

doublyLinkedListAPIStruct const doublyLinkedListAPI =
{DeleteInOrder, InsertInOrder,
  InsertAfterNode, Print, AddNodeAfter, AddValueAfter, AddNodeBefore, AddValueBefore,
AddNodeFirst, AddValueFirst, AddNodeLast, AddValueLast, Clear, Contains, CopyToArray,
Equal, Count, FindFirst, FindLast, RemoveNode, RemoveFirst, RemoveLast, RemoveStart,
RemoveEnd, ToString};
