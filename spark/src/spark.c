/*
 * sanbox.c
 *
 *  Created on: Mar 12, 2012
 *      Author: ray
 */
int plugin_is_GPL_compatible;

#include "gcc-plugin.h"
#include "callbacks.h"

int plugin_init(struct plugin_name_args *plugin_info,
		struct plugin_gcc_version *version)
{
	static const int plugin_init_fail = !0;
	static const int plugin_init_success = 0;
	printf("plugin called from sandbox\n");
	//dump_plugin_name_args(plugin_info);
//	register_callback(plugin_info->base_name, PLUGIN_PASS_MANAGER_SETUP, NULL, NULL);
//	register_callback(plugin_info->base_name, PLUGIN_ATTRIBUTES, NULL, attributes_callback);

	register_callback(plugin_info->base_name, PLUGIN_OVERRIDE_GATE, callback_for_PLUGIN_OVERRIDE_GATE, NULL);
	//register_callback(plugin_info->base_name, PLUGIN_PASS_EXECUTION, callback_for_PLUGIN_PASS_EXECUTION, NULL);

	return plugin_init_success;
}



