#include "get_next_line_bonus.h"

int main(int arc, char **argv)
{
    int fd1;
    int fd2;
    char *line;

    if (arc > 1)
    {
        fd1 = open(argv[1], O_RDONLY);
        fd2 = open(argv[2], O_RDONLY);
        get_next_line(fd2, &line);
        printf("%s\n\n", line);
        free(line);

        get_next_line(fd1, &line);
        printf("%s\n\n", line);
        free(line);

        get_next_line(fd2, &line);
        printf("%s\n\n", line);
        free(line);

        get_next_line(fd1, &line);
        printf("%s\n\n", line);
        free(line);
        //close(fd1);

        get_next_line(fd2, &line);
        printf("%s\n\n", line);
        free(line);
        //close(fd2);

        //fd1 = open(argv[2], O_RDONLY);
        get_next_line(fd1, &line);
        printf("%s\n\n", line);
        free(line);
        close(fd2);
        close(fd1);
    }
    return (0);
}