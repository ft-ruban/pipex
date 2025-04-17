#include "header/pipex.h"

char *free_double_array(char **one, char **two, char *three, char *four)
{
    int i;

    i = 0;
    if (one)
    {
        while(one[i])
        {
            free(one[i]);
            i++;
        }
        free(one);
    }
    i = 0;
    if (two)
    {
        while(two[i])
        {
            free(two[i]);
            i++;
        }
        free(two);
    }
    if (three)
        free(three);
    if (four)
        free(four);
    return (NULL);
}

char *find_path_loop(char **result_split, char *buff, char *cmd, char *full_path)
{
    int i;
    
    i = 0;
    while (result_split[i])
    {
        buff = ft_strjoin(result_split[i], "/"); 
        if(!buff)
            return(free_double_array(NULL,result_split, cmd, NULL));
        ft_printfd("CMD = %s\n",cmd);
        ft_printfd("BUFF VITE = %s\n",buff);
        full_path = ft_strjoin(buff, cmd); //fait
        if(!full_path)
            return(free_double_array(NULL,result_split, cmd, buff));
        ft_printfd("FUL_PATH = %s\n",full_path);
        free(buff);  
        if(!access(full_path, X_OK))
        {
            free_double_array(result_split, NULL, cmd, NULL);
            ft_printfd("FUL_PATHsucc = %s\n",full_path);
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
    result_split = ft_split(path, ':'); //GOOD
    if (!result_split)
        return(NULL);
    cmd_separated_flags = ft_split(cmd,' ');
    if (!cmd_separated_flags || !result_split)
        return(free_double_array(result_split,NULL, NULL, NULL));
    buff = ft_strdup(cmd_separated_flags[0]);
    if (!buff)
        return(free_double_array(result_split,cmd_separated_flags, NULL, NULL));

    free_double_array(NULL,cmd_separated_flags, NULL, NULL);
    // free(buff);
    // return (NULL);
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
            path = ft_strdup(env[i]);
            if (path == NULL)
                return (NULL); //path is now = PATH= blablabla
            final_result = find_path(path, cmd);
            if (final_result == NULL)
            {
                free(path);
                return (NULL);
            }
            break;
        }
        i++;
    }
    return(final_result);
}

void child_in_exec(char *cmd, char **env, int *fd)
{
    char *path;
    char **args;

    path = return_path(env, cmd);
    if (path == NULL)
        child_error(-42, fd);
    ft_printfd("PATHQQQQQQQQQQQQQQQ = %s\n", path);
    args = ft_split(cmd,' ');
    ft_printfd("args = %s\n",args[0]);
    ft_printfd("args = %s\n",args[1]);
    ft_printfd("args = %s\n",args[2]);
    ft_printfd("THEENDOFCHILDIN\n\n\n\n\n\n",args[2]);
    execve(path, args, NULL);
    ft_printfd("IT FAILED\n");
    exit(-1);
}
void    child_error(int infile, int *fd)
{
    if (infile >= 0)
        close(infile);
    if(fd[1])
        close(fd[1]);
    exit(-1);
}

void    child_in(char **argv, char **env, int flag_open, int *fd)
{
    int infile;

    flag_open = 1; //TODO rm????
    ft_printfd("Child IN\n");
    close(fd[0]);
    infile = -42;
    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
        child_error(infile, fd);//exit(-1); //TODO check if I have to free anything
    if(dup2(fd[1], STDOUT_FILENO) == -1)
        child_error(infile, fd);
    if(dup2(infile, STDIN_FILENO) == -1)
        child_error(infile, fd);  
    close(infile); //do exec close it?
    child_in_exec(argv[2], env, fd);
}
