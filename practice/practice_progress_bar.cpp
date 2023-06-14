#include <stdio.h>
#include <unistd.h>

int progress_bar(int x)
{
    int i;

    printf("\r\033[K");
    printf("%d%[", x);
    for (i = 0; i < (x / 10); i++) {
        printf("#");
    }
    printf("]");
    fflush(stdout); //立刻输出

    return 0;
}

int main()
{
    int x = 0;
    printf("progress bar test \n");

    while (1) {
        progress_bar(x);
        x++;
        if (x > 100)
            x = 0;
        usleep(50000);
    }
    return 0;
}
