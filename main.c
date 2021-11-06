
#include "tree-sitter/lib/src/subtree.h"

#include <stdio.h>

static void check_le_attribute();

int main()
{
	printf("sizeof(void *) = %zu\n", sizeof(void *));
#ifdef TS_PTR_SIZE
	printf("TS_PTR_SIZE = %d\n", TS_PTR_SIZE);
#endif
	printf("TS_BIG_ENDIAN = %d\n", TS_BIG_ENDIAN);
	printf("sizeof(SubtreeInlineData) = %zu\n", sizeof(SubtreeInlineData));
	printf("sizeof(Subtree) = %zu\n", sizeof(Subtree));

	Subtree st;
	memset(&st, 0xff, sizeof(st));
	printf("1-initialized: %#10llx\n", (unsigned long long)*(uint64_t *)(void *)&st);
	st = NULL_SUBTREE;

	// sanity check for zero-initialization
	uint64_t val = *(uint64_t *)(void *)&st;
	if (val)
	{
		printf("NULL_SUBTREE: %#10llx\n", (unsigned long long)val);
		return 1;
	}

	st.data.is_inline = true;
	printf("==> ptr = %p\n", st.ptr);
	if((st.ptr && (size_t)st.ptr != 1)
#if TS_PTR_SIZE
			|| TS_PTR_SIZE != sizeof(void *) * 8
#endif
			|| sizeof(Subtree) > 8)
	{
		printf("FAILED!!!\n");
		return 1;
	}
	return 0;
}
