#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    int option = atoi(argv[1]);

    // In ra so luong command-line truyen vao
    printf("Number of arguments: %d\n", argc);

    // In ra noi dung cua moi command-line
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i + 1, argv[i]);
    }

    switch (option)     
    {
    case 1:
        printf("job A\n");
        break;
    
    case 2:
        printf("job B\n");
        break;

    case 3:
        printf("job C\n");
        break;
    default:
        break;
    }
    return 0;
}