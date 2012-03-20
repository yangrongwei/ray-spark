/*
 * cxx-tree.cpp
 *
 *  Created on: Mar 14, 2012
 *      Author: ray
 */

#include "gcc-plugin.h"
#include "tree.h"
#include "cxx-tree.hxx"
//#include "coretypes.h"

namespace plugin_cxx {

const char *tree_identifier::DentifierPointer(void) {
	const char* str = IDENTIFIER_POINTER(m_node);
	return str;
}

unsigned int tree_identifier::IdentifierLength() {
	unsigned int len = IDENTIFIER_LENGTH(m_node);
	return len;
}

unsigned int tree_identifier::HashValue() {
	unsigned int hash_value = IDENTIFIER_HASH_VALUE(m_node);
	return hash_value;
}

tree tree_common::LinkListGetNext(void)
{
	tree next = TREE_CHAIN(m_node);
	return next;
}

}// end namespace plugin_cxx

