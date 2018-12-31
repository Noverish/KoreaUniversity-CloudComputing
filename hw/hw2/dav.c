// gcc -o dav dav.c
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define VM_NUM 2
#define MAX_VCPU 4
#define MIN_VCPU 1
#define BUFFER_LEN 1024

//this code needs to running vm more than one
struct var{
    char name[10];  // name
    int id;
    char state[8];  // state
    int cpu_sec;  // execution time
    double cpu_per;  // utilization
    int vcpu;
};//vm info structure
struct var topvar[VM_NUM];

void get_xllist();
void get_xentop(FILE*);
void print_topvar();
void dvam();

int main() {
    FILE *openxentop = popen("xentop -b d 1", "r");

    struct tm *t;
    time_t timer;

    while(1) {
        timer = time(NULL);
        t = localtime(&timer);
        printf("\n[Time] %04d-%02d-%02d %02d:%02d:%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

        get_xllist();
        get_xentop(openxentop);
        print_topvar();
        dvam();
        sleep(3);
    }

    pclose(openxentop);

    return 0;
}

void get_xllist() {
    FILE *xllist_buffer = popen("xl list", "r");
    char line[BUFFER_LEN], name[20];
    int i = 0, trash = 0;

    while(i < VM_NUM) {
        if(fgets(line, BUFFER_LEN, xllist_buffer) == NULL)
            break;

        memset(name, 0, sizeof(name));
        sscanf(line, "%s", name);
        if(strcmp(name, "Name") == 0) continue;
        if(strcmp(name, "Domain-0") == 0) continue;

        sscanf(line, "%s %d %d %d", topvar[i].name, &topvar[i].id, &trash, &topvar[i].vcpu);
        i++;
    }

    pclose(xllist_buffer);
}

void get_xentop(FILE *xentop_buffer) {
    char line[BUFFER_LEN], name[20];
    int i = 0;

    while(i < VM_NUM) {
        if(fgets(line, BUFFER_LEN, xentop_buffer) == NULL)
            break;

        memset(name, 0, sizeof(name));
        sscanf(line, "%s", name);
        if(strcmp(name, "NAME") == 0) continue;
        if(strcmp(name, "Domain-0") == 0) continue;
        
        sscanf(line, "%s %s %d %lf", topvar[i].name, topvar[i].state, &topvar[i].cpu_sec, &topvar[i].cpu_per);
        i++;
    }
}

void print_topvar() {
    int i = 0;
    for(i = 0; i < VM_NUM; i++) {
        printf("[VM] id:%d name:%s cpu(%%):%.1f vcpu:%d\n", topvar[i].id, topvar[i].name, topvar[i].cpu_per, topvar[i].vcpu);
    }
}

void dvam() {
    char command[64];
    int i = 0;
    for(i = 0; i < VM_NUM; i++) {
        if(strcmp(topvar[i].state, "-----r") != 0) // If VM is not running, then no re-allocation
            continue;

        int now_vcpu = topvar[i].vcpu;
        int new_vcpu = topvar[i].vcpu;
        double max_cpu_per = 100.0 * now_vcpu;

        if(max_cpu_per - topvar[i].cpu_per < 10.0 && now_vcpu < MAX_VCPU)
            new_vcpu = now_vcpu + 1;

        if(max_cpu_per - topvar[i].cpu_per > 100.0 && now_vcpu > MIN_VCPU)
            new_vcpu = now_vcpu - 1;

        if(now_vcpu != new_vcpu) {
            sprintf(command, "xl vcpu-set %s %d", topvar[i].name, new_vcpu);
            pclose(popen(command, "r"));
            printf("[DVAM] %s vcpu changed:%d -> %d\n", topvar[i].name, now_vcpu, new_vcpu);
        } else {
            printf("[DVAM] %s vcpu not changed:%d\n", topvar[i].name, now_vcpu);
        }
    }
}