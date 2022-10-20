/*
 * SKELETON.C --System entrypoint for the SKELETON daemon.
 *
 * Remarks:
 * This implements an "old style" SYSV init daemon.  It's deprecated.
 *
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <xtd.h>
#include <log.h>

int main(void)
{
    pid_t process_id = fork(), session_id;

    switch (process_id)
    {
    case -1:                            /* fork failed */
        log_sys_quit(LOG_ERR, "cannot fork new process");
        break;                          /* unreached */
    case 0:                             /* ...in child process */
        break;
    default:                            /* ...in parent process */
        info("created child process: %d", process_id);
        exit(0);
        break;
    }
    if ((session_id = setsid()) < 0)
    {
        log_sys_quit(LOG_ERR, "cannot set session");
    }
    if (chdir("/") < 0)
    {
        log_sys_quit(LOG_ERR, "cannot change directory");
    }

    umask(0);                    /* use unadjusted file permissions */
    close(0);                    /* close standard file descriptors */
    close(1);
    close(2);
    /* TODO: setup signal handlers */
    /* TODO: write pid file */
    /* TODO: drop privileges */
    /* TODO: notify parent that we're ready (signal HUP?)*/
    while (1)
    {
        sleep(30);
    }
    exit(0);
}
