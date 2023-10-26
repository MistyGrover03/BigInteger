#include <stdio.h>
#include <stdlib.h>
#ifndef BIGINTEGER_H
#define BIGINTEGER_H
struct node{
	int data;
	struct node *next;
};

struct BigInteger
{
  struct node *head;
  int  length;
  int sign;
};
struct node ** convertnumtoLL(struct node **start,int num);
int compare(struct BigInteger p1,struct BigInteger p2);
struct BigInteger initialize(char *s);

void dis(struct node *l);
int length(struct node *start);
void reverseLL(struct node **start);
void display(struct BigInteger ll);
struct BigInteger add(struct BigInteger p1,struct BigInteger p2);
struct BigInteger sub(struct BigInteger p1,struct BigInteger p2);
struct BigInteger mul(struct BigInteger p1,struct BigInteger p2);
#endif