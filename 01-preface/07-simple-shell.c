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

/*
 *  split_line:
 *      Splits line in 's' in tokens and constructs array 'argv'
 *      returns pointer to constructed 'argv'
 */

static char **
split_line( char *s )
{
    static char *argv[500];
    char *token;
    int i;

/*  'strtok' is a library function that splits in tokens (words) separated by
 *  characters as, for example tab and spaces; return the pointer to the token
 *  separated; if there are no more tokens, return NULL.
 *
 *  In the first call, must be passed as first argument the pointer to the line
 *      to be splitted.
 *  The function has memory where the last token has ended in the array; if following
 *      strtok call has NULL as pointer, then retakes form it were last time to separate next token
 */

    for( token = strtok(s, "\t "), i = 0 ; token != NULL; token = strtok(NULL, "\t "), ++i )
        argv[i] = token;
    argv[i] = NULL; // set last value to NULL for execvp

    return argv;
}

/*
 *  get_command_string:
 *      Constructs an array 'argv' form a line taken from 'stdin'
 *      Return pointer to the array constructed and terminated by NULL ptr
 *      In case of EOF in stdin or EXIT command, return NULL
 */

static char **
get_command_string( void )
{
    char line[1024];
    int last_char_ix;

    printf(PROMPT);     

/*
 *      Gets line from stdin.. if NULL returned or line length == 0
 *      then is recognized as EOF and exits from shell
 *      (Note: in stdin from keyboard, you can force EOF with ^D)
 */
    if( fgets(line, sizeof(line), stdin) == NULL || strlen(line) == 0 )
    {
        putchar('\n');
        return NULL;
    }

/*
 *  If there is a new line at end of line
 *      then replace with '\0' removing it
 */
    last_char_ix =  strlen(line)-1;

    if( line[last_char_ix] == '\n' )
        line[last_char_ix] = '\0';

/*
 *  If command received is the EXIT command, then exit shell
 */

    if( strcmp(line, EXIT) == 0 )
        return NULL;

/*
 *  Now, actually split line !!!
 */
    return split_line(line);
}

/*
 *  do_process:
 *      Tries to create new process to
 *      execute command through 'exec' system call
 */

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
        execvp( argv[0], argv);
        fprintf(stderr, "No cmd \"%s\"\n", argv[0] );
        return EXIT_FAILURE;
    } else              
    {                   //  Parent
        wait(NULL);     //  waits for the child to terminate
        return EXIT_SUCCESS;
    }
}

int
main( void )
{
    char **cmd_argv;

    forever
    {
        if( ( cmd_argv = get_command_string() ) == NULL )
            return EXIT_SUCCESS;
        do_process( cmd_argv );
    }
}

