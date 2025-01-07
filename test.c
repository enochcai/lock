#include <stdio.h>
#include <pthread.h>
 
void* myFunction(void* arg) {
    int param = *(int*)arg;
    printf("This is a thread! Parameter = %d\n", param);
    return NULL;
}
 
int main() {
    pthread_t myThread;
    int param = 42;
 
    if(pthread_create(&myThread, NULL, myFunction, &param) != 0) {
        printf("Failed to create thread\n");
        return 1;
    }
 
    // 等待新线程执行结束
    pthread_join(myThread, NULL);
 
    printf("Main thread exiting\n");
 
    return 0;
}
