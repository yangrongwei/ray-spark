/*
 * clong.c
 *
 *  Created on: Mar 6, 2012
 *      Author: ray
 */
#include <stdarg.h>
#include <stdio.h>
#include "clog.h"

static int get_current_logging_level(void);

void dbg_vprintf(int level, ...)
{
//	if (get_current_logging_level() < level)
//		return;
	va_list ap;
	va_start(ap, level);
	const char * msg = va_arg(ap, const char *);
	vprintf(msg, ap);
	va_end(ap);
}

static int get_current_logging_level()
{
	return ALL_LOG_LEVEL;
}
