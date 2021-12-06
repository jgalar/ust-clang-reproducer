#include <dlfcn.h>
#include <stdio.h>
#include <errno.h>

#define LTTNG_UST_TRACEPOINT_DEFINE
#define LTTNG_UST_TRACEPOINT_PROBE_DYNAMIC_LINKAGE
#include "providers.h"

__attribute__((constructor))
int mon_constructeur(void)
{
        const void *ret = dlopen("myproviders.so", RTLD_NOW);
        printf("error: %s\n", dlerror());
        printf("dlopen returned %p, errno = %d\n", ret, errno);
        return !!ret;
}

int lol(int a)
{
        tracepoint(embedded_sys, current_temp, 67);
        return 42;
}
