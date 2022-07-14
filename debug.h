#ifndef __debug_h__
#define __debug_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(Message, ...)
#else
#define debug(Message, ...) fprintf(stderr,"DEBUG %s:%d: " Message "\n",__FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno()(errno==0? "None":strerror(errno))

#define log_err(Message, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " Message "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(Message, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " Message "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(Message, ...) fprintf(stderr, "[INFO] (%s:%d) " Message "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, Message, ...) if(!(A)) {log_err(Message, ##__VA_ARGS__); errno=0; goto error;}

#define sentinel(Message, ...) {log_err(Message, ##__VA_ARGS__); errno=0; goto error;}

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, Message, ...) if(!(A)){debug(Message, ##__VA_ARGS__); errno=0; goto error;}

#endif
