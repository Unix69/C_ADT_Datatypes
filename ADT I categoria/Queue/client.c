#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"
#define M 10

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Error: missing argument\n");
        printf("correct format:\n");
        printf("%s maxN \n", argv[0]);
        return 0;
    }

    int i, j, cont = 1, maxN;
    maxN = atoi(argv[1]);

    Item item;

    Q queues[M];

    for (i=0; i < M; i++)
        queues[i] = QUEUEinit(maxN);

       while(cont)
    {
        printf("\nOperations on an array of  queues\n");
        printf("===============\n");
        printf("1.Insert item \n");
        printf("2.Extract item \n");
        printf("3.Size of queue\n");
        printf("4.Display queue\n");
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
                case 1:     printf("Enter queue number: ");
                            scanf("%d", &j);
                            printf("Enter item: \n");
                            item = ITEMscan();
                            QUEUEput(queues[j], item);
                            break;
                case 2:     printf("Enter queue number: ");
                            scanf("%d", &j);
                            if (QUEUEempty(queues[j]))
                                printf("\nCannot extract from empty  queue!\n");
                            else
                                ITEMshow(QUEUEget(queues[j]));
                            break;
                case 3:     printf("Enter queue number: ");
                            scanf("%d", &j);
                            printf("\nSize of queue is: %d\n", QUEUEsize(queues[j]));
                            break;
                case 4:     printf("Enter queue number: ");
                            scanf("%d", &j);
                            if (QUEUEempty(queues[j]))
                                printf("\n Queue is empty!\n");
                            else
                                QUEUEdisplay(queues[j], ITEMshow);
                            break;
                case 5:     cont = 0;
                            break;
                default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}

