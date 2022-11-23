#include <stdio.h>
#include <stdlib.h>
#include "Item.h"


Item ITEMscan()
{
    Item item;
    printf("key = ");
    scanf("%s", item.str);
    printf("value = ");
    scanf("%d", &item.x);
    return item;

}

void ITEMshow(Item item)
{
    printf("(%s, %2d) ", item.str, item.x);
}
