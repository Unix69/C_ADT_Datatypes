#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

Item ITEMscan()
{
    Item item;
    printf("x = ");
    scanf("%d", &item.x);
    printf("y = ");
    scanf("%d", &item.y);
    return item;

}

Item ITEMrand()
{
    Item item;
    item.x = 1000*(1.0 * rand()/RAND_MAX);
    item.y = 1000*(1.0 * rand()/RAND_MAX);
    return item;

}

void ITEMshow(Item item)
{
    printf("\n x = %d  y = %d \n", item.x, item.y);
}

