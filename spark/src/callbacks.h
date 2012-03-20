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
extern void callback_for_override_gate(void *gcc_data, void *user_data);
extern void callback_for_attributes(void *gcc_data, void *user_data);


/*Ray: TODO
  1. Since void* is a generic data type, we'd better to provid (wrap) a type safe
    (or type-specific) callback function prototype for each event.
  2. Event callbackers may have more interested data than gcc given, sometimes
     they are global variables in gcc source code, we may wrap them within a struct, 
     and pass it via user_data.
  In brief, we need a type safe event dispatching layer for plugin callback.
  
  Known challenge, How to elegantly expose event specific structs declared/used in gcc source code?
  Hints 1: Everything should be located in [plug-inc] directory.
  Hints 2: If it (the struct decaration) is localed in [gcc-src] directory only, copy it ??? 
           C should accept it, of course.
 */


/* Where to put event? Leading or tailing? Which one will improve performace? call stack reuse*/
/* If arguments are passed from right to left, leading may improve it */
extern void callback_dispatcher(int event, void *gcc_data, void *user_data);
extern void generic_plugin_callback(void *gcc_data, void *user_data);



#endif /* CALLBACKS_H_ */
