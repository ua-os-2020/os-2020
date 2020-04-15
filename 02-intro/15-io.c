/*
 *  15-io.c: used to show persistency
 *      An string saved in a file
 *
 *  Un.Austral - Sistemas Operativos - 2020
 *  EAMartinez
 */

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char buffer[20];
    int fd, rc;

    sprintf( buffer, "%s\n", argc == 1 ? "Hello World": *++argv );

    fd = open("tmp/persist", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    assert(fd >= 0);

    rc = write(fd, buffer, strlen(buffer));
    assert(rc == (strlen(buffer)));

    fsync(fd);
    close(fd);
    return 0;
}
