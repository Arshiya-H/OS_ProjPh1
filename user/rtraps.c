#include "kernel/types.h"
#include "kernel/param.h"
#include "kernel/spinlock.h"
#include "kernel/riscv.h"
#include "kernel/proc.h"
#include "kernel/defs.h"
//#include "user.h"


int main(){
    printf("this is trap syscal program\n");
    struct traps_report *s = (void *)0;
    traps_report(s);
}