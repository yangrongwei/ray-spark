/*
 * gcc-pass.c
 *
 *  Created on: Mar 14, 2012
 *      Author: ray
 */
#include "gcc-plugin.h"
#include "tree-pass.h"

#include <assert.h>
#include "clog.h"

void callback_for_PLUGIN_OVERRIDE_GATE(void *gcc_data, void *user_data)
{
	bool gate_status = *(bool *)gcc_data;
	CLOG_DEBUG("current pass: %s\tstatus: %d\n", current_pass->name, gate_status);
}
void callback_for_PLUGIN_PASS_EXECUTION(void *gcc_data, void *user_data)
{
	//CLOG_TRACE_IN();
	struct opt_pass *pass = (struct opt_pass *)gcc_data;
	assert(pass);
	CLOG_DEBUG("%s\n", pass->name);
	//CLOG_TRACE_OUT();
}
