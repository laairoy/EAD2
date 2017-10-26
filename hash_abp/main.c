#include "hash.h"
#include <stdio.h>


int main()
{
	HASH * hash = init_hash(1000);

	inserir_hash(hash, 5);

	return 0;
}