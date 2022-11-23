#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
#define MAXLEN 10

struct item
{
    int n;
    char *str;
};

Item ITEMnew()
{
    Item x;
    x = (Item)malloc(sizeof (struct item));
    x->n = EOF;
    x->str = NULL;
    return x;
}

void ITEMscan(Item x)
{
    int l;
    char word[MAXLEN+1];
    printf("integer = ");
    scanf("%d", &x->n);
    printf("string = ");
    scanf("%s",word);
    l = strlen(word) +1;
    x->str = (char*) malloc(l * sizeof (char));
    strcpy (x->str, word);
}

void ITEMshow(Item x)
{
    printf("\n integer = %4d   string= %s \n", x->n, x->str);
}
