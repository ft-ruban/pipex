#include "header/pipex.h"

char *find_path_loop(char **result_split, char *buff, char *cmd, char *full_path)
{
    int i;
    
    i = 0;
    while (result_split[i])
    {
        buff = ft_strjoin(result_split[i], "/");
        ft_printfd("BUFF VITE = %s\n",buff);
        full_path = ft_strjoin(buff, cmd);
        ft_printfd("FUL_PATH = %s\n",full_path);
        if(!full_path)
        {
            exit(-1);
            //stuff to free here
        }
        free(buff);  
        if(!access(full_path, X_OK))
        {
            i = 0;
            while (result_split[i])
            {
                free(result_split[i]);
                i++;
            }
            free(result_split);
            ft_printfd("FUL_PATH = %s\n",full_path);
            free(cmd); //rename maybe?
            return (full_path);
        }
        free(full_path);
        i++;
    }
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
    ft_printfd("BUFF = %s\n", buff);
    i = 0;
    while(cmd_separated_flags[i])
    {
        free(cmd_separated_flags[i]);
        i++;
    }
    free(cmd_separated_flags);
    free(path);
    return(find_path_loop(result_split, NULL, buff, NULL));
}

char *return_path(char **env, char *cmd)
{
    int i;
    char *path;
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
    char *args[3];
    args[0] = "ls";
    args[1] = "-l";
    args[2] = NULL;
    fd = 0;

    path = return_path(env, cmd);
    ft_printfd("PATHQQQQQQQQQQQQQQQ = %s\n", path);
    ft_printfd("CMD FIN %s\n",cmd);
    execve(path, args, NULL);
    exit(0);
}
void    child_error(int infile, int *fd)
{
    int i;

    i = 0;
    close(infile);
    while(fd[i])
    {
        close(fd[i]);
        i++;
    }
    exit(-1);
}

void    child_in(char **argv, char **env, int flag_open, int *fd)
{
    flag_open = 1;
    
    int infile;
    ft_printfd("Child IN\n");
    close(fd[0]);
    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
        child_error(infile, fd);//exit(-1); //TODO check if I have to free anything
    //child_error(infile, fd);
    close(infile);
    close(fd[1]);
    close(*fd);
    ft_printfd("TEST\n");
    exit(-1);
    if(dup2(fd[1], STDOUT_FILENO) == -1)
        exit(-1);
    if(dup2(infile, STDIN_FILENO) == -1)
        exit(-1);
    
    close(infile); //do exec close it?
    child_in_exec(argv[2], env, fd);
    exit(0);
}