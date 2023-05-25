#include <stdio.h>
#include "stream.h"
#include <stdlib.h>
#include <sys/sysinfo.h>

// 获取当前的CPU使用率（以百分比表示）
float get_cpu_usage() {
    FILE* fp = popen("top -bn1 | grep 'Cpu(s)' | awk '{print $2 + $4}'", "r");
    if (fp == NULL) {
        perror("popen failed");
        return -1;
    }

    float cpu_usage;
    if (fscanf(fp, "%f", &cpu_usage) != 1) {
        perror("fscanf failed");
        pclose(fp);
        return -1;
    }

    pclose(fp);
    return cpu_usage;
}

// 获取当前的内存使用情况（以MB为单位）
long get_memory_usage() {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("sysinfo failed");
        return -1;
    }

    long total_memory = info.totalram / (1024 * 1024);
    long free_memory = info.freeram / (1024 * 1024);
    long memory_usage = total_memory - free_memory;
    return memory_usage;
}

// 2个进程,一个进程执行,一个进程用来监控系统信息
// 时间长的才启动进程
int main(){
    float cpu_usage = get_cpu_usage();
    long memory_usage = get_memory_usage();

    printf("CPU Usage: %.2f%%\n", cpu_usage);
    printf("Memory Usage: %ld MB\n", memory_usage);
    
    printf("STRESS_TEST_VERSION_0_1 \r\n");
    printf("SCANNING_SYSTEM_PLATFORM_PARAMETER_INFORMATION, %CPU  %MEM  \r\n");

    // MAIN_MENU
    printf("[0] hello\r\n[1] stream \r\n[h] help \r\n");
    char k =getchar();

    // SELECT_FUNCITON
    switch(k){
        case '0':
        printf("hello world");
        break;

        case '1':
        printf("stream test");
        main_stream();
        break;

        case 'h':
        printf("HELP");
        break;

        default:
        printf("INVALID_INPUT");
        return 0;
        break;
    }


}
