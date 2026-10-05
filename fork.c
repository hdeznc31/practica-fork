#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int i;

    switch (fork())
    {
        case -1:
            perror("Error al crear proceso");
            exit(-1);
            break;

        case 0:
            /* Proceso hijo */
            for (i = 10000; i >= 1; i--)
            {
                printf("Proceso HIJO: %d\n", i);
            }
            break;

        default:
            /* Proceso padre */
            for (i = 1; i <= 10000; i++)
            {
                printf("Proceso PADRE: %d\n", i);
            }
            break;
    }

    return 0;
}
