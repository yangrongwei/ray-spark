/*
 * callbacks.c general callbacks for gcc-plugin
 *
 *  Created on: Mar 13, 2012
 *      Author: ray
 */
#include <assert.h>
#include <stdint.h>

#include "gcc-plugin.h"
#include "plugin.h"
#include "tree.h"
#include "diagnostic.h"

#define CUSTOM_ATTR_1 "raymond_type1"
#define CUSTOM_ATTR_2 "raymond_type2"

static tree handle_user_attribute(tree *node, tree name, tree args, int flags, bool *no_add_attrs);

//register our attributes here.
static const struct attribute_spec spec1 =
{
	.name = CUSTOM_ATTR_1,
	.min_length = 0,
	.max_length = 0,
	.decl_required = false,
	.type_required = false,
	.function_type_required = false,
	.handler = handle_user_attribute
};

static const struct attribute_spec spec2 =
{
	.name = "CUSTOM_ATTR_2",
	.min_length = 0,
	.max_length = 0,
	.decl_required = false,
	.type_required = false,
	.function_type_required = false,
	.handler = handle_user_attribute
};

void attributes_callback(void *gcc_data, void *user_data)
{
    register_attribute(&spec1);
    register_attribute(&spec2);
}
static tree handle_user_attribute(tree *node, tree name, tree args, int flags, bool *no_add_attrs)
{
//	CLOG_DEBUG_FUNC_ENTERING();
//	//const char * s = TREE_STRING_POINTER(name);
//	CLOG_DEBUG("===========\n");
//	CLOG_DEBUG_FUNC_LEAVING();
	return NULL_TREE;
}

