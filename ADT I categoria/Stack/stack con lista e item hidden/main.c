#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "stack.h"
#define N 100
#define M 10

int  main()
{
    Item item;
    int i, j, cont = 1;
    S stacks[M];

    for (i=0; i < M; i++)
    stacks[i] = STACKinit(N);

    while(cont)
    {
        printf("\nOperations on an array of stacks\n");
        printf("===============\n");
        printf("1.Push item onto stack\n");
        printf("2.Pop item from stack\n");
        printf("3.Top of stack\n");
        printf("4.Size of stack\n");
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
                case 1:     printf("Enter stack number: ");
                            scanf("%d", &j);
                            item = ITEMnew();
                            printf("Enter item: \n");
                            ITEMscan(item);
                            STACKpush(stacks[j], item);
                            break;
                case 2:     printf("Enter stack number: ");
                            scanf("%d", &j);
                            if (STACKempty(stacks[j]))
                                printf("\nCannot pop from empty stack!\n");
                            else
                            {
                                item = STACKpop(stacks[j]);
                                ITEMshow(item);
                            }
                            break;
                case 3:     printf("Enter stack number: ");
                            scanf("%d", &j);
                            if (STACKempty(stacks[j]))
                                printf("\nStack is empty!\n");
                            else
                            {
                                item = STACKtop(stacks[j]);
                                ITEMshow(item);
                            }
                            break;
                case 4:     printf("Enter stack number: ");
                            scanf("%d", &j);
                            printf("\nSize of stack %d is: %d\n", j, STACKsize(stacks[j]));
                            break;
                case 5:     cont = 0;
                            break;
                default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}


