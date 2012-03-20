/*
 * callbacks.h
 *
 *  Created on: Mar 13, 2012
 *      Author: ray
 */

#ifndef CALLBACKS_H_
#define CALLBACKS_H_

 /* The prototype for a plugin callback function.
	  gcc_data  - event-specific data provided by GCC
	  user_data - plugin-specific data provided by the plug-in.  */
/* typedef void (*plugin_callback_func)(void *gcc_data, void *user_data); */
extern void callback_for_PLUGIN_OVERRIDE_GATE(void *gcc_data, void *user_data);
extern void callback_for_PLUGIN_PASS_EXECUTION(void *gcc_data, void *user_data);

// ideal hook point, not present till gcc 4.7
//extern void callback_for_PLUGIN_FINISH_DECL(void *gcc_data, void *user_data);

void plugin_callback_dispatcher(void *gcc_data, void *user_data);

void generic_plugin_callback(void *gcc_data, void *user_data);
void override_gate_callback(void *gcc_data, void *user_data);
void attributes_callback(void *gcc_data, void *user_data);



#endif /* CALLBACKS_H_ */
