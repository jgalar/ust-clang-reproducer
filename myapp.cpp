#include <dlfcn.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, const char **argv)
{
        const void *ret = dlopen("mylib.so", RTLD_NOW);
        printf("error: %s\n", dlerror());
        printf("dlopen returned %p, errno = %d\n", ret, errno);
        return 0;
}
