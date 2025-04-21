#include "header/pipex.h"

int     ft_pipex(char **argv, char **env)
{
    int     pipe_fd[2];
    pid_t   first_child;
    pid_t   second_child;
    int     status;
    int     status_two;

    if(pipe(pipe_fd) == -1)
        exit(-1);
    first_child = fork();
    if (first_child == -1)
        exit(-1);
    if (first_child == 0)
        child_in(argv, env,pipe_fd); //TODO function for the first cmd
    second_child = fork();
    if (second_child == -1)
        exit(-1);
    if (second_child == 0)
    {
        //exit(0); //TORM
        child_out(argv, env, pipe_fd);
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    // if (waitpid(first_child, &status, 0) == first_child && waitpid(second_child, &status_two, 0))
    //     printf("both child terminated\n");//if (waitpid(second_child, &status, 0) == second_child)
    waitpid(first_child, &status, 0);
    waitpid(second_child, &status_two, 0);

    return (status_two >> 8);
}

//tester pipex42

// int bait = waitpid(-1, NULL, 0);
//     while (bait >= 0){
//         bait = waitpid(-1, NULL, 0);
//     }