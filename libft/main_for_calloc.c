#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main() {
    size_t count, size;
    void *ptr_ft_calloc, *ptr_calloc;

    // Test edge cases
    printf("Testing edge cases:\n");

    // Case 1: count or size is zero
    count = 0;
    size = 10;
    ptr_ft_calloc = ft_calloc(count, size);
    ptr_calloc = calloc(count, size);
    printf("Edge case 1: count = %zu, size = %zu\n", count, size);
    printf("ft_calloc result: %p\n", ptr_ft_calloc);
    printf("calloc result: %p\n", ptr_calloc);
    if (ptr_ft_calloc != ptr_calloc) {
        printf("Outputs are different!\n");
    }
    free(ptr_ft_calloc);
    free(ptr_calloc);

    // Case 2: multiplication overflow
    count = SIZE_MAX;
    size = SIZE_MAX;
    ptr_ft_calloc = ft_calloc(count, size);
    ptr_calloc = calloc(count, size);
    printf("Edge case 2: count = %zu, size = %zu\n", count, size);
    printf("ft_calloc result: %p\n", ptr_ft_calloc);
    printf("calloc result: %p\n", ptr_calloc);
    if (ptr_ft_calloc != ptr_calloc) {
        printf("Outputs are different!\n");
    }
    free(ptr_ft_calloc);
    free(ptr_calloc);

    // Case 3: total size greater than 2147483648
    count = 2147483648;
    size = 2;
    ptr_ft_calloc = ft_calloc(count, size);
    ptr_calloc = calloc(count, size);
    printf("Edge case 3: count = %zu, size = %zu\n", count, size);
    printf("ft_calloc result: %p\n", ptr_ft_calloc);
    printf("calloc result: %p\n", ptr_calloc);
    if (ptr_ft_calloc != ptr_calloc) {
        printf("Outputs are different!\n");
    }
    free(ptr_ft_calloc);
    free(ptr_calloc);
    // Case 4: working
    count = 50;
    size = 4;
    ptr_ft_calloc = ft_calloc(count, size);
    ptr_calloc = calloc(count, size);
    printf("Edge case 4: count = %zu, size = %zu\n", count, size);
    printf("ft_calloc result: %p\n", ptr_ft_calloc);
    printf("calloc result: %p\n", ptr_calloc);
    free(ptr_ft_calloc);
    free(ptr_calloc);

    return 0;
}
