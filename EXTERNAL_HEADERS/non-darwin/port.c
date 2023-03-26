#include <mach-o/dyld.h>
#include <mach/mach_init.h>

vm_size_t vm_page_size = 4096;

#if defined(__FreeBSD__)
#include <sys/sysctl.h>
#include <errno.h>
#include <stdlib.h>
#endif

int
_NSGetExecutablePath(char *buf, uint32_t *bufsize)
{
#if defined(__FreeBSD__)
	int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
	int ret = -1;
	size_t sz = *bufsize;
	ret = sysctl(mib, 4, buf, &sz, NULL, 0);
	if (ret == -1 && errno == ENOMEM) {
		*bufsize = sz;
		return -1;
	}
	return 0;
#endif
	return -1;
}
