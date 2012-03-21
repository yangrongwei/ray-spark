/*
 * cxx-tree.cpp
 *
 *  Created on: Mar 14, 2012
 *      Author: ray
 */

#include "gcc-plugin.h"

//Ray:
// The dirty header should only be included here, not current file's corresponding header.
// Otherwise, macros and C structs are exposed to our client directly,
// which is intentionally to avoid.
#include "tree.h"

#include "cxx-tree.hxx"
//#include "coretypes.h"

namespace plugin_cxx {

const char *tree_identifier::DentifierPointer(void) {
	const char* str = IDENTIFIER_POINTER(m_node);
	return str;
}

unsigned int tree_identifier::IdentifierLength(void) {
	unsigned int len = IDENTIFIER_LENGTH(m_node);
	return len;
}

unsigned int tree_identifier::HashValue(void) {
	unsigned int hash_value = IDENTIFIER_HASH_VALUE(m_node);
	return hash_value;
}

tree tree_identifier::HtIdentToGccIdent(struct ht_identifier *ht_ident_ptr)
{
	//Ray:
	// HT_IDENT_TO_GCC_IDENT() used an improper name for its argument.
	// It should remark the argument is a hashtable identifier pointer,
	// not a NODE. However, it is just an argument name, computer will not complain,
	// but programmers do.
	tree t = HT_IDENT_TO_GCC_IDENT(ht_ident_ptr);
	return t;
}



tree tree_common::LinkListGetNext(void)
{
	tree next = TREE_CHAIN(m_node);
	return next;
}

}// end namespace plugin_cxx

