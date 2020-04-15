/*
 *  07-simple-shell.c
 *  Implements a super simple shell
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define PROMPT  "ua-shell: $"
#define EXIT    "exit"
#define forever for(;;)

static char **
get_command_string( void )
{
    static char *argv[500];
    static char line[1024];
    int i;
    char *token;

    printf(PROMPT);

    if( fgets(line, sizeof(line), stdin) == NULL || strlen(line) == 0 )
    {
        putchar('\n');
        return NULL;
    }

    if( line[strlen(line)-1] == '\n' ) line[strlen(line)-1] = '\0';

    if( strcmp(line, EXIT) == 0 )
        return NULL;

    for( i = 0, token = strtok(line, " ") ; token != NULL; ++i, token = strtok(NULL, " ") )
        argv[i] = token;
    argv[i] = NULL; // set last value to NULL for execvp

    return argv;
}

static int
do_process( char *const argv[] )
{
    int pid;

    if( ( pid = fork() ) < 0 )
    {
        fprintf(stderr, "Can't fork\n");
        return EXIT_FAILURE;
    }

    if( pid == 0 )      //  Child
    {
        execvp( *argv, argv);
        fprintf(stderr, "No cmd \"%s\"\n", *argv );
        return EXIT_FAILURE;
    } else              
    {                   //  Parent
        wait(NULL);
        return EXIT_SUCCESS;
    }
}

int
main( int argc, char **argv )
{
    char **cmd_argv;

    forever
    {
        if( ( cmd_argv = get_command_string() ) == NULL )
            return EXIT_SUCCESS;
        do_process( cmd_argv );
    }
}

