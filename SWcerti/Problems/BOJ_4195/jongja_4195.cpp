#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

#define PN 23
#define MAX_HASH_SIZE 2000000

struct fnode
{
	char name[21];
	struct fnode* next;
	struct fnode* network;
};

struct env
{
	int cnt;
	bool isNewNode;
	fnode* p;
};

struct fnode data_pool[MAX_HASH_SIZE] = { 0 };
struct fnode *hash_table[MAX_HASH_SIZE] =  { 0 };
int T, F;
int data_pool_idx = 0;

struct fnode* salloc() {
	return &data_pool[data_pool_idx++];
}

int _strcmp(char* s1, char* s2) {
	while (*s1) {
		if (*s1 != *s2) {
			return *s1 > * s2 ? 1 : -1;
		}
		s1++; s2++;
	}
	return *s2 != '\0' ? 1 : 0;
}

void _strcpy(char* dst, char* src) {
	while (*src) *(dst++) = *(src++);
	*dst = '\0';
	return;
}

unsigned int hasing(char* str) {
	unsigned int p = 1, key = 0;
	while (*str) {
		key += (*str) * p;
		p *= PN;
		str++;
	}
	return key % MAX_HASH_SIZE;
}

struct env hash_insert(char* str) {
	int idx = hasing(str);
	fnode* newNode = salloc();
	newNode->next = NULL;
	newNode->network = NULL;
	_strcpy(newNode->name, str);
	return Insert_node(hash_table[idx], newNode);
}

struct env Insert_node(fnode* head, fnode *newNode){
	struct env res;
	res.isNewNode = true;
	res.cnt = 0;
	if (!head) {
		head = newNode;
		res.cnt++;
	}
	else {
		fnode* walker = head;
		while (walker->next) {
			if (!_strcmp(walker->name, newNode->name)) {
				res.isNewNode = false;
				res.p = walker;
			}
			walker = walker->next;
			res.cnt++;
		}
		if (!_strcmp(walker->name, newNode->name)) {
			res.isNewNode = false;
			res.p = walker;
		}
		else {
			walker->next = newNode;
			res.p = newNode;
			res.cnt++;
		}
	}
	if (!res.isNewNode) res.cnt--;
	return res;
}

void init() {
	for (int i = 0; i < MAX_HASH_SIZE; i++)
		hash_table[i] = NULL;
	data_pool_idx = 0;
}

int main(void) {
	freopen("wow.csv", "r", stdin);
	int T, F, r1, r2;
	struct env res1, res2;

	char s1[21] = { 0 }, s2[21] = { 0 };
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		init();
		scanf("%d", &F);
		for (int j = 0; j < F; j++) {
			scanf("%s %s", s1, s2);
			res1 = hash_insert(s1);
			res2 = hash_insert(s2);
			Insert_node(res1.p->network, res2.p->network);

		}
	}
	return 0;
}