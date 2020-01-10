// 기수정렬
#include <stdio.h>
#include <stdlib.h>
#define BUCKETS 8
#define DIGITS 2
#include "CircularQueue.h"

void radixSort( int list[], int n )
{
	CircularQueue queues[BUCKETS];
    int factor=1, i, b, d;

    for( d=0 ; d<DIGITS ; d++ ){
		printf("[BUCKETS]\n");

		for( i=0 ; i<n ; i++ )
			queues[(list[i]/factor)%10].enqueue(list[i]);

		for( b=i=0 ; b<BUCKETS ; b++) {
			printf("bucket[%d] = ", b);

			for(int x=queues[b].front; x<=queues[b].rear; x++)
				if(queues[b].data[x] > -1)
					printf("%3d",queues[b].data[x]);
			printf("\n");

			while( !queues[b].isEmpty() )
				list[i++] = queues[b].dequeue();

			queues[b].reset();

			/*for(int x=queues[b].front; x<BUCKETS; x++)
				if(queues[b].data[x] > -1)
					printf("%d ",queues[b].data[x]);
			printf("\n");*/
		}
		printf("PASS %d : ", d+1);
		for( int i=0 ; i<n ; i++ )
			printf("%3d ", list[i]);
		printf("\n\n");
		factor *= 10;
    }
}

// 배열을 화면에 보기 좋게 출력하는 함수. 디폴트 매개변수 사용
static void printArray( int arr[], int n, char *str="Array" )
{
    printf("%s = ", str);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

int sequentialSearch(int list[], int key, int low, int high)
{
	int c = 0;
    for(int i=low; i<=high; i++, c++)
		if(list[i]==key){
			printf("%d ", c);
			printf("%d ", i);
		return i;
		}
		
    return -1;
}

int sortedSequentialSearch(int list[], int key, int low, int high)
{
    int i,c=0;
    if(key<list[low] || key>list[high]) return -1;  // 리스트에 없는 경우

    for(i=low; i<=high; i++){
	c++;
	if(list[i] > key) return -1;  //탐색키보다 큰 레코드를 만나면 탐색 종료 
	if(list[i] == key) {printf("%d ", c);  printf("%d ", i); return i;}  //탐색키를 찾았다 !
    }
}

int binarySearchIter (int list[], int key, int low, int high)
{
    int middle, c=0;
    while ( low <= high ){
	c++;
	middle = (low+high)/2;		// 가운데 인덱스 계산
	if ( key == list[middle] )	// 탐색 성공
		{printf("%d ", c);
	printf("%d ", middle);
	return middle;}
	else if( key > list[middle] )    // 오른쪽 리스트를 탐색하라 !
	    low = middle+1;
	else				// 왼쪽 리스트를 탐색하라 !
	    high = middle-1;
    }
    return -1;				// 탐색 실패
}

void main()
{
	int list[8] = { 27, 10, 12, 20, 25, 13, 15, 22};
	printArray( list, 8, "Original Data" );	// 정렬 전 배열 출력 
	radixSort( list, 8 ); 		// 기수 정렬 실행 
	printArray( list, 8, "Radix Sorting " );	// 정렬 후 배열 출력 
	sequentialSearch(list, 12, 0, 7);
	sortedSequentialSearch(list, 12, 0, 7);
	binarySearchIter(list, 12, 0, 7);
	 
	system("pause");
}