#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/spinlock.h"
#include "kernel/riscv.h"
#include "kernel/proc.h"
//#include "kernel/defs.h"
#include "user.h"


int main(){
    int pid = fork();
    if (pid == 0) {
//        int ppid = fork();
//        if (ppid == 0) {
//            int *nn = 0;
//            *nn = 5;
//            sleep(200);
//            exit(0);
//        }
        int *n = 0;
        *n = 4;

        sleep(200);
        exit(0);
    }
    sleep(1);
    struct traps_report *r = (struct traps_report *) malloc(sizeof (struct traps_report));
    traps_report(r);
    printf("PPID\t\tPID\t\tPNAME\t\tscause\t\tsepc\t\tstval\n");
    for (int i = 0; i < r->count; ++i) {
        printf("%d\t\t%d\t\t%s\t\t0x%lx\t\t0x%lx\t\t0x%lx\n",r->reports[i].ppid,r->reports[i].pid,r->reports[i].pname,r->reports[i].scause,r->reports[i].sepc,r->reports[i].stval);
    }
    free(r);

}