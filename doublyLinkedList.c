#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

static doublyLinkedListNode* AddNodeAfter(doublyLinkedListNode* current, doublyLinkedListNode* node)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return current;
}

static doublyLinkedListNode* AddValueAfter(doublyLinkedListNode* current, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return current;
}

// not possible with doublyLinkedList
static doublyLinkedListNode* AddNodeBefore(doublyLinkedListNode* current, doublyLinkedListNode* node)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return current;
}

// not possible with doublyLinkedList
static doublyLinkedListNode* AddValueBefore(doublyLinkedListNode* current, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return current;
}

static doublyLinkedListNode* AddNodeFirst(doublyLinkedListNode* head, doublyLinkedListNode* node)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* AddValueFirst(doublyLinkedListNode* head, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* AddNodeLast(doublyLinkedListNode* head, doublyLinkedListNode* node)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* AddValueLast(doublyLinkedListNode* head, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* Clear(doublyLinkedListNode* head)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static int Contains(doublyLinkedListNode* head, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return 0;
}

static doublyLinkedListNode* CopyToArray(doublyLinkedListNode* head, int startingIndex)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static int Equal(doublyLinkedListNode* headOne, doublyLinkedListNode* headTwo)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return 0;
}

static int Count(doublyLinkedListNode* head)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return 0;
}

static doublyLinkedListNode* FindFirst(doublyLinkedListNode* head, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* FindLast(doublyLinkedListNode* head, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* RemoveNode(doublyLinkedListNode* head, doublyLinkedListNode* node, int (* predicate)(doublyLinkedListNode *node1, doublyLinkedListNode *node2))
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* RemoveFirst(doublyLinkedListNode* head, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* RemoveLast(doublyLinkedListNode* head, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* RemoveStart(doublyLinkedListNode* head, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static doublyLinkedListNode* RemoveEnd(doublyLinkedListNode* head, int value)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
}

static char* ToString(doublyLinkedListNode* head)
{
  fprintf(stderr, "ERROR in file %s line:%d %s is not implemented do not use\n", __FILE__, __LINE__, __FUNCTION__);
  return NULL;
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
