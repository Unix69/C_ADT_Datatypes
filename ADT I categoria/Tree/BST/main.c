#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "BST.h"

int  main()
{
    Item item, NULLitem = EMPTYitem;
    int i, pos, cont;
    BST bst;

    bst = BSTinit();
    cont = 1;
    while(cont)
    {
        printf("\nOperations on BSTs\n");
        printf("===============\n");
        printf("1.Insert in leaf (iterative)\n");
        printf("2.Insert in leaf (recursive)\n");
        printf("3.Insert in root\n");
        printf("4.Search \n");
        printf("5.Minimum \n");
        printf("6.Maximum \n");
        printf("7.Select \n");
        printf("8.Preorder visit\n");
        printf("9.Postorder visit\n");
        printf("10.Inorder visit\n");
        printf("11.Size\n");
        printf("12.Delete\n");
        printf("13.Successor\n");
        printf("14.Predecessor\n");
        printf("15.Exit\n");
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
                            if (neq(key(BSTsearch(bst, key(item))), key(NULLitem)))
                                continue;
                            BSTinsert_leafI(bst,item);
                            break;
                case 2:     printf("Enter item: \n");
                            item = ITEMscan();
                            if (neq(key(BSTsearch(bst, key(item))), key(NULLitem)))
                                continue;
                            BSTinsert_leafR(bst,item);
                            break;
                case 3:     printf("Enter item: \n");
                            item = ITEMscan();
                            if (neq(key(BSTsearch(bst, key(item))), key(NULLitem)))
                                continue;
                            BSTinsert_root(bst,item);
                            break;
                case 4:     printf("Enter item: \n");
                            item = ITEMscan();
                            if (neq(key(BSTsearch(bst, key(item))), key(NULLitem)))
                                printf("Item found!\n");
                            else
                                printf("Item not found!\n");
                            break;
                case 5:     if(BSTempty(bst))
                                printf("BST is empty\n");
                            else
                            {
                                printf("Minimum item: ");
                                ITEMshow(BSTmin(bst));
                            }
                            break;
                case 6:     if(BSTempty(bst))
                                printf("BST is empty\n");
                            else
                            {
                                printf("Maximum item: ");
                                ITEMshow(BSTmax(bst));
                            }
                            break;
                case 7:     printf("Enter rank: \n");
                            scanf("%d",&pos);
                            if (pos >= BSTcount(bst))
                                printf("Rank beyond range \n");
                            else
                            {
                                item = BSTselect(bst, pos);
                                printf("Item of rank %d is: ", pos);
                                ITEMshow(item);
                            }
                            break;
                case 8:     if(BSTempty(bst))
                                printf("BST is empty\n");
                            else
                                BSTsortpreorder(bst,ITEMshow);
                            break;
                case 9:     if(BSTempty(bst))
                                printf("BST is empty\n");
                            else
                                BSTsortpostorder(bst,ITEMshow);
                            break;
                case 10:    if(BSTempty(bst))
                                printf("BST is empty\n");
                            else
                                BSTsortinorder(bst,ITEMshow);
                            break;
                case 11:    printf("The BST contains %d distinct items\n", BSTcount(bst));
                            break;
                case 12:    printf("Enter item: \n");
                            item = ITEMscan();
                            if (eq(key(BSTsearch(bst, key(item))), key(NULLitem)))
                                printf("Item not found!\n");
                            else
                                BSTdelete(bst,item);
                            break;
                case 13:    printf("Enter item: \n");
                            item = ITEMscan();
                            if (eq(key(BSTsearch(bst, key(item))), key(NULLitem)))
                                printf("Item not found!\n");
                            else
                            {
                                printf("Successor is: \n");
                                ITEMshow(BSTsucc(bst,item));
                            }
                            break;
                case 14:    printf("Enter item: \n");
                            item = ITEMscan();
                            if (eq(key(BSTsearch(bst, key(item))), key(NULLitem)))
                                printf("Item not found!\n");
                            else
                            {
                                printf("Predecessor is: \n");
                                ITEMshow(BSTpred(bst,item));
                            }
                            break;
                case 15:    cont = 0;
                            break;
                default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}

