#include "header/pipex.h"
//NOLEAKS
int     ft_pipex(char **argv, char **env)
{
    int     pipe_fd[2];
    pid_t   first_child;
    pid_t   second_child;
    int     status;

    if(pipe(pipe_fd) == -1)
        exit(-1);
    first_child = fork();
    if (first_child == -1)
        exit(-1);
    if (first_child == 0)
        child_in(argv, env, 00, pipe_fd); //TODO function for the first cmd
    second_child = fork();
    if (second_child == -1)
        exit(-1);
    if (second_child == 0)
    {
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        exit(0); //TORM
        //child_function(argv, env, 01, pipe_fd);
    }
    if (waitpid(first_child, &status, 0) == first_child)
        if (waitpid(second_child, &status, 0) == second_child)
            printf("both child terminated\n");
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    return 0;
}