#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

#define check(exp, msg) if(exp) {} else {\
   printf(1, "%s:%d check (" #exp ") failed: %s\n", __FILE__, __LINE__, msg);\
   exit();}

int
main(int argc, char *argv[])
{
   struct pstat st;
   check(getpinfo(&st) == 0, "getpinfo");

   for(int i = 0; i < NPROC; i++){
       if(st.pid[i] > 0){
           printf(1, "PID: %d, INUSE: %s, TICKETS: %d, TICKS: %d\n", st.pid[i], st.inuse[i] ? "Yes" : "No", st.tickets[i], st.ticks[i]);
       }
   }
   exit();
}
