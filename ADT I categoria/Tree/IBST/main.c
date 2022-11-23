#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "IBST.h"

int  main()
{
    Item item, NULLitem = EMPTYitem;
    int i, cont;
    IBST ibst;

    ibst = IBSTinit();
    cont = 1;
    while(cont)
    {
        printf("\nOperations on IBSTs\n");
        printf("===============\n");
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Preorder visit\n");
        printf("4.Postorder visit\n");
        printf("5.Inorder visit\n");
        printf("6.Size\n");
        printf("7.Delete \n");
        printf("8.Exit\n");
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
                case 1:     printf("Enter interval: \n");
                            item = ITEMscan();
                            IBSTinsert(ibst,item);
                            break;
                case 2:     printf("Enter interval: \n");
                            item = ITEMscan();
                            if (neq((IBSTsearch(ibst,item)), NULLitem))
                            {
                                printf("Overlapping interval found!\n");
                                ITEMshow(IBSTsearch(ibst,item));
                            }
                            else
                                printf("Overlapping interval not found!\n");
                            break;
                case 3:     IBSTsortpreorder(ibst,ITEMshow);
                            break;
                case 4:     IBSTsortpostorder(ibst,ITEMshow);
                            break;
                case 5:    IBSTsortinorder(ibst,ITEMshow);
                            break;
                case 6:    printf("The IBST contains %d distinct items\n", IBSTcount(ibst));
                            break;
                case 7:    if(IBSTempty(ibst))
                                printf("IBST is empty\n");
                            else
                            {
                                printf("Enter interval: ");
                                item = ITEMscan();
                                IBSTdelete(ibst,item);
                            }
                            break;
                case 8:     cont = 0;
                            break;
                default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}
