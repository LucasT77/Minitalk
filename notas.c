/* Sending a signal with kill system */
int kill(pid_t pid, int sig);
/*
    pid: the identifier of the process or process group to send the signal to. Here, we can specify:
        a positive integer: a process’ PID,
        a negative integer: a process group’s PGID,
        0: all of the processes in the calling process’ group,
        -1: all of the processes in the system (except process 1, init!) for which the calling process has the permission to send signals to. See the manual page for kill (2) about permissions.
    sig: the signal to send to the process.
*/

/* Intercepting a signal with sigaction */
int sigaction(int signum, const struct sigaction *restrict act,
              struct sigaction *restrict oldact);
/*
    signum: the signal we want to modify the action of,
    
	act: a pointer to a sigaction-type structure that will allow us, 
	among other things, to indicate a signal handler. We will examine this shortly.
    
	oldact: a pointer to another sigaction-type structure in which to store the 
	old behavior that was triggered upon receipt of the signal. 
	If we don’t need to restore the old action later, then we can just put NULL here.
*/

int sigemptyset(sigset_t *set);
/*
sigemptyset()	initializes the signal set given by set to empty, 
				with all signals excluded from the set.
*/

int sigaddset(sigset_t *set, int signum);
/*
sigaddset()	add and delete respectively signal signum from set.
*/

sighandler_t signal(int signum, sighandler_t handler);
/*
DESCRIPTION
       The  behavior  of signal() varies across UNIX versions, and has also varied historically across
       different versions of Linux.  Avoid its use: use sigaction(2) instead.  See Portability below.

       signal() sets the disposition of the  signal  signum  to  handler,  which  is  either  SIG_IGN,
       SIG_DFL, or the address of a programmer-defined function (a "signal handler").

       If the signal signum is delivered to the process, then one of the following happens:

       *  If the disposition is set to SIG_IGN, then the signal is ignored.

       *  If  the  disposition  is  set to SIG_DFL, then the default action associated with the signal
          (see signal(7)) occurs.

       *  If the disposition is set to a function, then first  either  the  disposition  is  reset  to
          SIG_DFL,  or  the signal is blocked (see Portability below), and then handler is called with
          argument signum.  If invocation of the handler caused the signal to  be  blocked,  then  the
          signal is unblocked upon return from the handler.

       The signals SIGKILL and SIGSTOP cannot be caught or ignored.

RETURN VALUE
       signal()  returns  the previous value of the signal handler, or SIG_ERR on error.  In the event
       of an error, errno is set to indicate the cause.
*/

pid_t getpid(void);
/*
getpid()	returns the process ID (PID) of the calling process.  
			(This is often used by routines that generate unique temporary filenames.)
*/

int pause(void);
/*
DESCRIPTION
       pause() causes the calling process (or thread) to sleep until a signal is delivered that either
       terminates the process or causes the invocation of a signal-catching function.

RETURN VALUE
       pause() returns only when a signal was caught and the signal-catching  function  returned.   In
       this case, pause() returns -1, and errno is set to EINTR.
*/



int usleep(useconds_t usec);
/*
DESCRIPTION
       The  usleep()  function  suspends execution of the calling thread for (at least) usec microsec‐
       onds.  The sleep may be lengthened slightly by any system activity or by the  time  spent  pro‐
       cessing the call or by the granularity of system timers.

RETURN VALUE
       The  usleep() function returns 0 on success.  On error, -1 is returned, with errno set to indi‐
       cate the cause of the error.
*/

sleep NUMBER[SUFFIX];
/*
Pause for NUMBER seconds.  SUFFIX may be 's' for seconds (the default),
       'm' for minutes, 'h' for hours or 'd' for days.  Unlike most  implemen‐
       tations  that require NUMBER be an integer, here NUMBER may be an arbi‐
       trary floating point number.  Given two or more  arguments,  pause  for
       the amount of time specified by the sum of their values.


*/

/*
#include<stdio.h>
#include <unistd.h>
#include<signal.h>
#include <stdlib.h>

char *str;

void sig_handler(int signum){
    printf("Inside handler function\n");
    str = malloc(sizeof(char) * 5);
    str = "Ola!";
}
void sig_handler2(int signum){
  kill(getpid(), SIGUSR1);
  printf("Inside handler function 2: %s\n", str);
}

int main(){
  pid_t pid;
  signal(SIGUSR1,sig_handler);
  signal(SIGUSR2,sig_handler2); // Register signal handler
  printf("Inside main function\n");
  pid=getpid();      //Process ID of itself
  kill(pid,SIGUSR2);        
  printf("Inside main function\n");
  return 0;
}
*/