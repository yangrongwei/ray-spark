/*
 * callbacks.c
 *
 *  Created on: Mar 18, 2012
 *      Author: ray
 */

#include "gcc-plugin.h"
#include "tree.h"
void foo()
{
	tree t;
	TREE_CHAIN(t);
	({int a; a = 3;});
}
