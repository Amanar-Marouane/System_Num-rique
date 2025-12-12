#include <stdio.h>
#include <stdlib.h>

void pBin(long n) { if (n > 1) pBin(n >> 1); printf("%ld", n & 1); }

int main() {
    int s, d, t[][4]={{0},{0,2,3,4},{0,1,3,4},{0,1,2,4},{0,1,2,3}};
    char *n[] = {"", "binary", "decimal", "octal", "hexa-decimal"}, buf[64];
    long v;
    
    printf("press 1 to enter binary code.\npress 2 to enter decimal code.\npress 3 to enter octal code.\npress 4 to enter hexa-decimal code.\npress 0 to quit.\n");
    if(scanf("%d", &s)!=1 || s<0 || s>4) { printf("Press valid number\n"); return 0; }
    if(s==0) { printf("U quit, bye Bitch :)"); exit(0); }
    
    printf("Enter the code ==> ");
    scanf("%s", buf);
    v = strtol(buf, NULL, s==1?2:s==2?10:s==3?8:16);
    
    printf("press 1 to convert your code to %s.\npress 2 to convert your code to %s.\npress 3 to convert your code to %s.\n", n[t[s][1]], n[t[s][2]], n[t[s][3]]);
    if(scanf("%d", &d)!=1 || d<1 || d>3) { printf("R U fokin damp.\n"); return 0; }
    
    int tgt=t[s][d]; // Target Type ID
    printf("Ur %s converted code is ==> ", tgt==4?"hexa_decimal":n[tgt]);
    
    if(tgt==1) { if(v==0) printf("0000"); else pBin(v); printf(".\n"); }
    else printf(tgt==4?"%lX.\n":tgt==3?"%lo.\n":"%ld.\n", v);
    
    return 0;
}
