#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/spinlock.h"
#include "kernel/riscv.h"
#include "kernel/proc.h"
//#include "kernel/defs.h"
#include "user.h"

static char *states[] = {
        [UNUSED]    "unused",
        [USED]      "used",
        [SLEEPING]  "sleep ",
        [RUNNABLE]  "runble",
        [RUNNING]   "run   ",
        [ZOMBIE]    "zombie"
};

int main() {
    child_processes *info = (child_processes *) malloc(sizeof (child_processes));

    for (int i = 0; i < 5; ++i) {
        int pid = fork();
        if (pid == 0) {
            int ppid = fork();
            if (ppid == 0) {
                sleep(200);
                exit(0);
            }
            sleep(200);
            exit(0);
        }
    }
    sleep(10);


    get_child_processes(info);
    int n = info->count;
    printf("total procs: %d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("name: %s\t\tpid: %d\t\tppid: %d\t\tstate: %s\n", info->processes[i].name, info->processes[i].pid, info->processes[i].ppid,states[info->processes[i].state]);
    }
    free(info);
}