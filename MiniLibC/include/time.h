/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __STDLIB_H__
#define __STDLIB_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>
#include <internal/essentials.h>

struct timespec {
	long tv_sec;
	long tv_nsec;
};
int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
