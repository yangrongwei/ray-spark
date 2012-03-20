/*
 * log.h
 *
 *  Created on: Mar 6, 2012
 *      Author: ray
 */

#ifndef CLOG_H_
#define CLOG_H_

extern void dbg_vprintf(int level, ...);

/* log levels are borrowed from http://log4cplus.sourceforge.net */
#define OFF_LOG_LEVEL      60000	//is used during configuration to turn off logging.
#define FATAL_LOG_LEVEL    50000	//designates very severe error events that will presumably lead the application to abort.
#define ERROR_LOG_LEVEL    40000	//designates error events that might still allow the application to continue running.
#define WARN_LOG_LEVEL     30000	//designates potentially harmful situations.
#define INFO_LOG_LEVEL     20000	//designates informational messages that highlight the progress of the application at coarse-grained level.
#define DEBUG_LOG_LEVEL    10000	//designates fine-grained informational events that are most useful to debug an application.
#define TRACE_LOG_LEVEL    0		//is used to "trace" entry and exiting of methods.
#define ALL_LOG_LEVEL      TRACE_LOG_LEVEL	//is used during configuration to turn on all logging.
#define NOT_SET_LOG_LEVEL  -1		//is used to indicated that no particular LogLevel is desired and that the default should be used.


/* call logging function within .c file */
/* from richest to lowest */
#define CLOG_TRACE_IN()		dbg_vprintf(TRACE_LOG_LEVEL, "Entering %s.\n", __func__, __FILE__, __LINE__)
#define CLOG_TRACE_OUT()	dbg_vprintf(TRACE_LOG_LEVEL, "Leaving  %s.\n", __func__, __FILE__, __LINE__)
#define CLOG_DEBUG(...)    dbg_vprintf(WARN_LOG_LEVEL, __VA_ARGS__)
#define CLOG_INFO
#define CLOG_WARN
#define CLOG_ERROR
#define CLOG_FATAL


#endif /* CLOG_H_ */
