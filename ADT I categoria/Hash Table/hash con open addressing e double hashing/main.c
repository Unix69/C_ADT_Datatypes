#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Item.h"
#include "ST.h"

int main()
{
    Item item, item1, NULLitem = EMPTYitem;
    int i,  cont, maxN;

    printf("Input size of hash table to guarantee load factor < 1/2:");
    scanf("%d", &maxN);

    ST st;
    st = STinit(maxN);

    cont = 1;
    while(cont)
    {
        printf("\nOperations on hash tables\n");
        printf("===============\n");
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        if(scanf("%d",&i)<=0)
        {
            printf("Integers only!\n");
            exit(0);
        }
        else
        {
            switch(i)
            {
                case 1:     printf("Enter item: \n");
                            item = ITEMscan();
                            STinsert(st, item);
                            break;
                case 2:     printf("Enter item: \n");
                            item = ITEMscan();
                            item1 = STsearch(st, key(item));
                            if (neq(key(item1), key(NULLitem)))
                                printf("Item found!\n");
                            else
                                printf("Item not found!\n\n");
                            break;
                case 3:     if(STempty(st))
                            {
                                printf("Hash table is empty!\n");
                                break;
                            }
                            else
                            {
                                printf("Enter item: \n");
                                item = ITEMscan();
                                item1 = STsearch(st, key(item));
                                if (eq(key(item1), key(NULLitem)))
                                    printf("Item not in table!\n");
                                else
                                    STdelete(st, item);
                            }
                            break;
                case 4:     STlist(st, ITEMshow);
                            break;
                case 5:     cont = 0;
                            break;
                default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}
