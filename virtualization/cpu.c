#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

// This replaces the missing code from common.h
double GetTime() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double)t.tv_sec + (double)t.tv_usec/1e6;
}

void Spin(int howlong) {
    double t = GetTime();
    while ((GetTime() - t) < (double)howlong)
        ; // Do nothing, just loop to pass time
}

int main (int argc,char *argv[]){
   if(argc != 2){
    fprintf(stderr, "usage: cpu <string>\n");
    exit(1);
   }
   char *str = argv[1];
   while (1){
    Spin(1);
    printf("%s\n", str);
  }
  return 0;
}
