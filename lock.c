#include <stdio.h>
#include <pthread.h>
#include <unistd.h> //sleep,usleep声明

#define THREAD_COUNT 10

pthread_mutex_t mutex;

void *thread_callback(void *arg){
	int *pcount = (int *)arg;
	int i = 0;
	while(i++ < 100000){
#if 0
		(*pcount) ++;//
#else
		pthread_mutex_lock(&mutex);
		(*pcount) ++;//
		pthread_mutex_unlock(&mutex);
#endif
		usleep(1);//休眠1微妙
	}
}

int main(){
	pthread_t threadid[THREAD_COUNT] = {0};
    
	pthread_mutex_init(&mutex, NULL);

	int i = 0;
	int count = 0;
	for (i = 0; i < THREAD_COUNT; i++){
		//callback后的参数带到回调函数里,线程id, 堆栈信息，回调函数,回调函数参数
		pthread_create(&threadid[i], NULL, thread_callback, &count);
	}
	for(i=0;i<100;i++){
		printf("count: %d\n", count);
		sleep(1);
	}
}
