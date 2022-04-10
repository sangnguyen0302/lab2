#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * hello (void*  tid ) {
	pthread_mutex_lock(&mutex);
	int* t = (int *) tid;
	printf("Hello from thread %d\n",*t) ;
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main() {
	pthread_t tid [10] ;
	int i;
	for (i = 0; i < 10; i++) {
		pthread_create(&tid[i] , NULL, hello ,(void *) &i ) ;
	}
	for (i = 0; i < 10; i++) {
		pthread_join(tid[i] , NULL) ;
	}
	
	return 0;
}