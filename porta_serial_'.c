#include <stdio.h>
int main(int argc, char **argv)
{
    char bytes[2] = {11, 0}; /* 11 is the TIOCLINUX cmd number */
    if (argc==2) 
        bytes[1] = atoi(argv[1]); /* the chosen console */
    else 
    {
        fprintf(stderr, "%s: need a single arg\n", argv[0]); 
        exit(1);
    }
    if (ioctl(STDIN_FILENO, TIOCLINUX, bytes)<0) 
    {
        /* use stdin */
        fprintf(stderr,"%s: ioctl(stdin, TIOCLINUX): %s\n", argv[0], strerror(errno));
        exit(1);
    }
    exit(0);
}
