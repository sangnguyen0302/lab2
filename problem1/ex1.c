#include"ex1.h"

void * aligned_malloc(unsigned int size, unsigned int align){
	void *p1;
	void **p2;
	int offset = align - 1 + sizeof(void *);
	p1 = (void*)malloc(size + offset);
	if(p1==NULL){
		return NULL;
	}
	p2 = (void**)(((size_t)(p1)+offset)&~(align-1));
	return p2;
}

void * aligned_free(void *ptr){
	free(((void**)ptr)[-1]);
}
