/**
 * myShell.c: implement shell
 * @author: Joonsung Choe
 * @email: 32214668@dankook.ac.kr
 * @version: 1.0
 * @date: 2025. 11. 15
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
void func_cd(int token_count, char *tokens[])
{
    if (token_count > 2)
    {
        fprintf(stderr, "USAGE: cd [path]\n");
        return;
    }
    if (token_count == 1) // input command is only "cd"
    {
        char *home = getenv("HOME");
        if (home == NULL)
            home = "/";
        if (chdir(home) < 0)
            perror("chdir");
    }
    else // cd <path>
    {
        if (chdir(tokens[1]) < 0)
            perror("cd");
    }
}
void func_pwd(int token_count)
{
    if (token_count > 1)
    {
        fprintf(stderr, "USAGE: pwd\n");
        return;
    }
    char buf[1024];
    if (getcwd(buf, sizeof(buf)) != NULL)
    {
        printf("%s\n", buf);
    }
    else
    {
        perror("pwd");
    }
}
int tokenize(char *buf, char *delims, char *tokens[], int maxTokens)
{
    char *token;
    int token_count = 0;
    token = strtok(buf, delims);
    while (token != NULL && token_count < maxTokens)
    {
        tokens[token_count++] = token;
        token = strtok(NULL, delims);
    }
    return token_count;
}
bool run(char *line)
{
    char *tokens[100];
    char *delims = " \t\n";
    int token_count = 0;
    int pipe_count = 0;
    int pipe_index[10] = {
        0,
    };

    // tokenize command
    token_count = tokenize(line, delims, tokens, sizeof(tokens) / sizeof(char *));
    if (token_count == 0) // when input enter without command
        return true;
    // internal command proccessing
    if (token_count == 1 && !strcmp(tokens[0], "exit")) // quit myshell
        return false;
    if (!strcmp(tokens[0], "cd")) // cd
    {
        func_cd(token_count, tokens);
        return true;
    }
    if (!strcmp(tokens[0], "pwd")) // pwd
    {
        func_pwd(token_count);
        return true;
    }
    for (int i = 0; i < token_count; i++)
    {
        if (!strcmp(tokens[i], "|")) // count pipe
        {
            pipe_index[pipe_count++] = i;
        }
    }
    if (pipe_count) // case of pipe
    {
        for (int i = 0; i < pipe_count; i++)
        {
            if (pipe_index[i] <= 0 || pipe_index[i] >= token_count - 1) // invailed pipe error
            {
                fprintf(stderr, "syntax error: invalid pipe\n");
                return true;
            }
        }
        char *cmd[11][100];
        int p[10][2];
        memset(cmd, 0, sizeof(cmd));         // init cmd
        for (int i = 0; i < pipe_count; i++) // active pipe
            pipe(p[i]);
        for (int i = 0; i <= pipe_count; i++) // segment command
        {
            int start = (i == 0 ? 0 : pipe_index[i - 1] + 1);
            int end = (i == pipe_count ? token_count : pipe_index[i]);

            int cnt = 0;
            for (int j = start; j < end; j++)
                cmd[i][cnt++] = tokens[j];

            cmd[i][cnt] = NULL;
        }

        int num_cmd = pipe_count + 1; // number of command always pipe_count+1
        for (int i = 0; i < num_cmd; i++)
        {
            int pid = fork();
            if (pid < 0)
            {
                perror("fork");
                exit(1);
            }
            if (pid == 0)
            {
                if (i > 0) // connect STDIN to previous pipe
                {
                    dup2(p[i - 1][0], STDIN_FILENO);
                }
                if (i < num_cmd - 1) // connect STDOUT to next pipe
                {
                    dup2(p[i][1], STDOUT_FILENO);
                }

                for (int k = 0; k < num_cmd - 1; k++) // close all pipe ends in child
                {
                    close(p[k][0]);
                    close(p[k][1]);
                }

                execvp(cmd[i][0], cmd[i]);
                perror("execvp");
                exit(1);
            }
        }
        for (int i = 0; i < num_cmd - 1; i++)
        {
            close(p[i][0]);
            close(p[i][1]);
        }

        for (int i = 0; i < num_cmd; i++)
            wait(NULL);
    }
    else // case of no pipe
    {
        int pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(1);
        }
        if (pid == 0)
        {
            execvp(tokens[0], tokens);
            perror("execvp");
            exit(1);
        }
        wait(NULL);
    }
    return true;
}
void print_current_dir_name()
{
    char buf[1024];

    if (getcwd(buf, sizeof(buf)) != NULL)
    {
        printf("%s $ ", buf);
        fflush(stdout); // 버퍼 처리
    }
    else
    {
        perror("getcwd");
    }
}
int main()
{
    char line[1024];
    while (1)
    {
        print_current_dir_name();
        fgets(line, sizeof(line) - 1, stdin);
        if (run(line) == false)
            break;
    }
}