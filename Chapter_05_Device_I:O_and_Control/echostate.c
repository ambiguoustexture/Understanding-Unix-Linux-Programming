/* echostate.c
 *     reports current state of echo bit in tty driver for fd 0
 *     shows how to read attributes from driver and test a bit
 */

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

int main() {
    struct termios info;
    int rv;

    // read values from driver
    rv = tcgetattr(0, &info);

    if (rv == -1) {
        perror( "tcgetattr"); exit(1);
    }
    if (info.c_lflag & ECHO) 
        printf("echo is on , since its bit is 1\n");
    else 
        printf("echo if OFF, since its bit is 0\n");
    
    return 0;
}
