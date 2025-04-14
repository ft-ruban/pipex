/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:02:13 by ldevoude          #+#    #+#             */
/*   Updated: 2025/04/14 16:41:52 by ldevoude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

char *find_path_loop(char **result_split, char *buff, char *cmd, char *full_path)
{
    int i;
    
    i = 0;
    while (result_split[i])
    {
        buff = ft_strjoin(result_split[i], "/");
        full_path = ft_strjoin(buff, cmd);
        if(!full_path)
        {
            exit(-1);
            //stuff to free here
        }
        free(buff);  
        if(!access(full_path, X_OK))
        {
            free(result_split);
            //MAYBE STUFF TO FREE HERE
            return (full_path);
        }
        free(full_path);
        i++;
    }
    //free stuff here
    exit(-1);
}

char *find_path(char *path, char *cmd)
{
    char **result_split;
    int i;
    char **cmd_separated_flags;
    char *buff;

    i = 0;
    while ((cmd[i] >= 9 && cmd[i] <= 13) || cmd[i] == 32)
        i++;
    result_split = ft_split(path, ':');
    if (!result_split)
        exit(-1); //FREE STUFF HERE MAYBE
    cmd_separated_flags = ft_split(cmd,' ');
    buff = ft_strdup(cmd_separated_flags[0]);
    i = 0;
    while(cmd_separated_flags[i])
    {
        free(cmd_separated_flags[i]);
        i++;
    }
    free(cmd_separated_flags);
    return(find_path_loop(result_split, NULL, cmd, NULL));
}

char *return_path(char **env, char *cmd)
{
    int i;
    char *path;
    //char *buff;
    char *final_result;
    
    final_result = NULL;
    path = NULL;
    i = 0;
    
    //TODO check if already pathed to avoid all this
    while (env[i] || !path)
    {
        if(!ft_strncmp(env[i], "PATH=", 5))
        {
            path = ft_strdup(env[i]); //path is now = PATH= blablabla
            final_result = find_path(path, cmd);
            break;
        }
        i++;
    }
    return(final_result);
}

void child_in_exec(char *cmd, char **env, int *fd)
{
    char *path;
    fd = 0;

    path = return_path(env, cmd);
    ft_printfd("PATH = %s\n", path);
    exit(0);
}

void    child_in(char **argv, char **env, int flag_open, int *fd)
{
    //printf("TESTREE\n"); //on rentre ici
    env = NULL;
    fd = NULL;
    flag_open = 1;
    
    int infile;
    //printf("ICIIICICIIC\n");
    //close(fd[0]);
   
    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
        exit(-1); //TODO check if I have to free anything
    if(dup2(fd[1], STDOUT_FILENO) == -1)
        exit(-1);
    if(dup2(infile, STDIN_FILENO) == -1)
        exit(-1);
    printf("Child IN\n");
    close(infile); //do exec close it?
    child_in_exec(argv[2], env, fd);
    exit(0);
    
}

int     ft_pipex(char **argv, char **env)
{
    int     pipe_fd[2];
    pid_t   first_child;
    pid_t   second_child;
    int     status;
    
    printf("ICI\n");
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
        //child_function(argv, env, 01, pipe_fd);

    if (waitpid(first_child, &status, 0) == first_child)
        if (waitpid(second_child, &status, 0) == second_child)
            printf("both child terminated\n");
    return 0;
}

//TODO? ft_init_pipex()
int main(int argc, char *argv[], char **env)
{
    //int          p_fd[2];
    //pid_t   pid;
    int error_code;
    if (argc != 5)  //TODO if (ft_check_args() == 1)
        exit_function(1, argv);
    error_code = (ft_check_args(argv, env, 0));  //TODO ft_parse_cmds()  //TODO ft_parse_args()
    if (error_code != 0)
        exit_function(error_code, argv);  //TODO     exit_function(1);
    ft_pipex(argv, env);
   
   
    
    //TODO while (cmds)
    //TODO      ft_exec()
    //TODO ft_cleanup
    ft_printf("Program worked :>\n");
    printf("CMD: %s\n",argv[2]);
    return(0);
}

/*
- parent : check arg (le nombre ? acces infile ? access outfile ? path cmd1 ? path cmd2 ?)
- créer un pipe
- parent : fork pid1 (infile cmd1)
    enfant : execve(cmd1)
- parent : fork pid2
    enfant : execve(cmd2)
- parent : waitpid
*/