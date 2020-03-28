#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "doublyLinkedList.h"

int NULLTests();
int OneNULLTests();
int OneFiveNULLTests();

int main()
{
  // NULL Tests
  NULLTests();

  // 1->NULL Tests
  OneNULLTests();

  // 1->5->NULL Tests
  OneFiveNULLTests();

  return 0;
}

int NULLTests()
{
  doublyLinkedListNode* temporary1 = NULL;
  doublyLinkedListNode* temporary2 = NULL;
  char* asString = NULL;

  // InsertInOrder
  temporary1 = doublyLinkedListAPI.InsertInOrder(NULL, 1);
  asString = doublyLinkedListAPI.ToString(temporary1);
  assert(NULL == asString);

  // AddNodeAfter
  temporary2 = (doublyLinkedListNode*)malloc(sizeof(doublyLinkedListNode));
  temporary2->value = 5;
  temporary2->next = NULL;
  temporary2->previous = NULL;
  temporary1 = doublyLinkedListAPI.AddNodeAfter(NULL, temporary2);
  asString = doublyLinkedListAPI.ToString(temporary1);
  assert(NULL == asString);
  free(temporary2);
  temporary2 = NULL;


  return 0;
}

int OneNULLTests()
{
  return 0;
}

int OneFiveNULLTests()
{
  return 0;
}
