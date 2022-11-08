#include "qf.h"
#include "bf.h"
#include "cf.h"

int main()
{
    printf("Choose a data set to continue:\n1 ~ Bloom Filter\n2 ~ Cuckoo Filter\n3 ~ Quotient Filter\n0 ~ Quit\nEnter a option: ");
    int option1;
    scanf("%d", &option1);
    while (option1)
    {
        switch (option1)
        {
        case 0:
            break;

        case 1:
            bool bitarray[100] = {false};
            printf("Enter a username: ");
            char x[100];

            scanf("%s", x);
            bf_insert(bitarray, x);
            bool check;
            int option = 1;

            while (option != 0)
            {
                printf("1 ~ Insert another username\n2 ~ Lookup for username\n0 ~ Quit\nEnter option: ");
                scanf("%d", &option);
                switch (option)
                {
                case 0:
                    break;
                case 1:
                    printf("Enter a username: ");
                    scanf("%s", x);

                    bf_insert(bitarray, x);
                    break;
                case 2:
                    printf("Enter a username: ");
                    scanf("%s", x);
                    check = bf_lookup(bitarray, x);
                    if (check)
                        printf("Username present !!\n");
                    else
                        printf("Username not present !!\n");
                    break;
                }
            }
            break;

        case 2:
            int *CF;
            CF = (int *)malloc(m * sizeof(int));
            for (int i = 0; i < m; i++)
            {
                CF[i] = -1;
            }
            printf("Enter a username: ");
            scanf("%s", x);

            check = cf_insert(x, CF);
            if (check)
                printf("Successfully Inserted !!");
            else
                printf("Inserted but another username deleted !!");

            while (option != 0)
            {
                printf("\n1 ~ Insert another username\n2 ~ Lookup for username\n3 ~ Delete a username\n0 ~ Quit\nEnter option: ");
                scanf("%d", &option);
                switch (option)
                {
                case 0:
                    break;
                case 1:
                    printf("Enter a username: ");
                    scanf("%s", &x);
                    check = cf_insert(x, CF);
                    if (check)
                        printf("Successfully Inserted !!");
                    else
                        printf("Inserted but another username deleted !!");
                    break;
                case 2:
                    printf("Enter a username: ");
                    scanf("%s", &x);
                    check = cf_lookup(x, CF);
                    if (check)
                        printf("Username present !!");
                    else
                        printf("Username not present !!");
                    break;
                case 3:
                    printf("Enter a username: ");
                    scanf("%s", &x);
                    check = cf_delete(x, CF);
                    if (check)
                        printf("Username successfully deleted !!");
                    else
                        printf("Username not present !!");
                    break;
                }
            }
            break;
        case 3:
            node *QF;
            QF = (node *)malloc(m * sizeof(node));
            for (int i = 0; i < m; i++)
            {
                QF[i].value = -1;
            }
            printf("Enter a username(minimum length 8): ");

            scanf("%s", x);

            int l = strlen(x);
            if (l < 8)
            {
                printf("Minimum length = 8\n");
                goto start;
            }

            check = qf_insert(x, QF);
            if (check)
                printf("Successfully Inserted !!\n");
            else
                printf("Inserted but another username deleted !!\n");
            option = 1;
            while (option != 0)
            {
                printf("1 ~ Insert another username\n2 ~ Lookup for username\n3 ~ Delete a username\n0 ~ Quit\nEnter option: ");
                scanf("%d", &option);
                switch (option)
                {
                case 0:
                    break;
                case 1:
                start:
                    printf("Enter a username: ");
                    scanf("%s", &x);

                    l = strlen(x);
                    if (l < 8)
                    {
                        printf("Minimum length = 8\n");
                        goto start;
                    }

                    check = qf_insert(x, QF);
                    if (check)
                        printf("Successfully Inserted !!\n");
                    else
                        printf("Inserted but another username deleted !!\n");
                    break;
                case 2:
                    printf("Enter a username: ");
                    scanf("%s", &x);
                    check = qf_lookup(x, QF);
                    if (check)
                        printf("Username present !!\n");
                    else
                        printf("Username not present !!\n");
                    break;
                case 3:
                    printf("Enter a username: ");
                    scanf("%s", &x);
                    check = qf_delete(x, QF);
                    if (check)
                        printf("Username successfully deleted !!\n");
                    else
                        printf("Username not present !!\n");
                    break;
                }
            }
            break;
        }
        printf("Choose a data set to continue:\n1 ~ Bloom Filter\n2 ~ Cuckoo Filter\n3 ~ Quotient Filter\n0 ~ Quit\nEnter a option: ");
        scanf("%d", &option1);
    }
    return 0;
}