#include<stdio.h>
#include<pthread.h>
struct station		// structure declare
{
	int count;
	int key;
}train1,temp;
// function declare
void cond_wait()
{
	sleep(1);
}
void cond_signal()
{
	int j;
	printf("\n\t\tSignal Processing!");
	for(j=0;j<3;j++)
	{
		sleep(1);
		printf("...");
	}
	printf("\n");
	
}
void cond_broadcast()
{
	printf("\n\t\tSignail: Green\n");
	sleep(1);	
 }
lock_init(int lock)
{
	train1.key=2;
}
lock_acquire()
{
	if (train1.key!=1)
	{
	train1.key=1;	
	}
	else{
		sleep(1);
	}
	
}
lock_release() 
{
	train1.key=0;
}

void station_load_train(temp)
{
	int i;
	lock_init(1);
	printf("Trains Has Succesfully Arrived!\n\n");
	lock_acquire(0);
	printf("\t\tTrain Loading...\n");
	int cnt=12;
	for(i=0;i<cnt;i++)
	{
		printf("passenger%d\n",i);
		sleep(1);
	}
	printf("\t\tTrain has  Loaded...");
	
	lock_release(1) ;
}
void station_on_board(struct station *station) 
{
	cond_signal();
	cond_broadcast();
	printf("\n\n\t\tTrain Departed\n\n");

}

void station_wait_for_train(struct station1 *station)
{
	
	if (train1.key==0)
	{
		lock_acquire(0);
	}
	else
	{
		sleep(1);
	}
	pthread_t tid3;
	printf("\n\n\t\tWait for signal\n\n");
	cond_wait();
	pthread_create(&tid3,NULL,station_on_board,&train1);
	pthread_join(tid3,NULL);
	lock_release(1) ;
}
// main 
void main()
{
	pthread_t tid1,tid2;
	train1.count=72;
	(train1);
	pthread_create(&tid1,NULL,station_load_train,&train1);
	pthread_join(tid1,NULL);
	pthread_create(&tid2,NULL,station_wait_for_train,&train1);
	pthread_join(tid2,NULL);
}
