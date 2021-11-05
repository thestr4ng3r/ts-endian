
#include "tree-sitter/lib/src/subtree.h"

#include <stdio.h>

int main()
{
	Subtree st;
	memset(&st, 0, sizeof(st));
	st.data.is_inline = true;
	printf("sizeof(void *) = %zu\n", sizeof(void *));
	printf("TS_PTR_SIZE = %d\n", TS_PTR_SIZE);
	printf("TS_BIG_ENDIAN = %d\n", TS_BIG_ENDIAN);
	printf("sizeof(SubtreeInlineData) = %zu\n", sizeof(SubtreeInlineData));
	printf("sizeof(Subtree) = %zu\n", sizeof(Subtree));
	printf("==> ptr = %p\n", st.ptr);
	if((size_t)st.ptr != 1 || TS_PTR_SIZE != sizeof(void *) * 8 || sizeof(Subtree) > 8)
	{
		printf("FAILED!!!\n");
		return 1;
	}
	return 0;
}
