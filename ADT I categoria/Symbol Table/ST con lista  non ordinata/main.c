#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

int main(int argc, char *argv[])
{
    if (argc !=2)
    {
        printf("Error in command line, correct format: \n");
        printf("client <maximun number of items> \n");
        exit(1);
    }

    int i, n, cont, maxN = atoi(argv[1]);
    Item item, NULLitem = EMPTYitem;
    ST st;

    st = STinit(maxN);

    cont = 1;
    while(cont)
    {
        printf("\nOperations on Symbol Tables\n");
        printf("===============\n");
        printf("1.Random fill with n items\n");
        printf("2.Insert \n");
        printf("3.Search \n");
        printf("4.Delete \n");
        printf("5.Display \n");
        printf("6.Size\n");
        printf("7.Exit\n");
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
                case 1:     printf("\nFilling in n random items\n");
                            printf("how many items?\n");
                            scanf("%d", &n);
                            for (i=0; i < n; i++)
                            {
                                item = ITEMrand();
                                if (eq(key(STsearch(st, key(item))), key(NULLitem)))
                                STinsert(st, item);
                            }
                            break;
                case 2:     printf("\nEnter item: \n");
                            item = ITEMscan();
                            if (eq(key(STsearch(st, key(item))), key(NULLitem)))
                                STinsert(st, item);
                            break;
                case 3:     printf("\nEnter item: \n");
                            item = ITEMscan();
                            if (neq(key(STsearch(st, key(item))), key(NULLitem)))
                                printf("item found!\n");
                            else
                                printf("item not found!\n");
                            break;
                case 4:     printf("\nEnter item: \n");
                            item = ITEMscan();
                            if (eq(key(STsearch(st, key(item))), key(NULLitem)))
                                printf("item not found!\n");
                            else
                                STdelete(st, item);
                            break;
                case 5:     STdisplay(st, ITEMshow);
                            break;
                case 6:     printf("\nThe symbol table contains %d distinct items\n", STcount(st));
                            break;
                case 7:     cont = 0;
                            break;
                default:    printf("\nInvalid option\n");
            }
        }
    }
    return 0;
  }

