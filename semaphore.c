#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
int val = 1;
void* thread();

int main()
{
	sem_init(&mutex, 0, 1);
	pthread_t pid1;
	pthread_t pid2;
	pthread_create(&pid1, NULL, thread, NULL);
	sleep(1);
	pthread_create(&pid2, NULL, thread, NULL);
	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);
	sem_destroy(&mutex);
	return 0;
}

void* thread()
{
	sem_wait(&mutex); //wait state
	printf("\nENTER THREAD %d\n", val);
	val++;
	int num = 1;
	while  (1) {
		printf("Hlooo! %d\n", num);
		num++;
		break;
		sleep(1);
	}
	//critical section
	printf("\nExiting....\n");
	sem_post(&mutex);//signaling
}
