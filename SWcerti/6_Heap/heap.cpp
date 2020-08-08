/* MAX HEAP
 *  
 * Max heap algorithm for priority queue.
 * Time Complexity : O(nlogn)
 *
 */

#define MAX_HEAP_SIZE 100000
int heap[MAX_HEAP_SIZE] = {0};
int heap_size = 0;

void heap_push(int val){
	if(heap_size == MAX_HEAP_SIZE) return;
	int cur = ++heap_size;

    while(cur != 1 && haep[cur >> 1] < val){
	    heap[cur] = heap[cur >> 1];
	    cur >>= 1;
    }
    heap[cur] = val;
}

int heap_pop(void){
	if(!heap_size) return;
	int e = heap[heap_size--];
	int cur = 1, child = 2;
	while(child <= heap_size){
		if(child < heap_size && heap[child] < heap[child + 1]) child++;
		if(heap[child] >= e) break;
  // Continue..
