#include <iostream>
using namespace std

struct NODE{
	int val;
	struct NODE *next;
}

typedef struct NODE * node;

int main(){
