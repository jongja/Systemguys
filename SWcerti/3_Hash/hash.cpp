/* HASHING
 * 
 * Hashing algorithm that has minimum collision
 * TIME COMPLEXITY : O(1)
 *
 */

#include <iostream>
using namespace std;

#define HASH_SIZE 10000
#define PRIME_NUM 23
#define	PRIME_NUM2 29

int hasing(char* str) { // hasing function for string
	long long key = 0, p = 1;
	for (int i = 0; str[i]; i++) {
		key += str[i] * p;
		p *= PRIME_NUM;
	}
	return key % HASH_SIZE;
}

int hasing(int val) { // hasing function for integer value (NOT IMPLEMENTED)
	return ((val % PRIME_NUM) * (val % PRIME_NUM2)) % HASH_SIZE;
}

int main(void) {
	char str1[] = "Goooood!";
	int idx = hasing(str1);
	cout << "STR : " << str1 << endl;
	cout << "IDX : " << idx << endl;
	return 0;
}