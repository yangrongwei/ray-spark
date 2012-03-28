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
#include "cxx-tree-def-type.hxx"
#include "cxx-tree-def-expr.hxx"

#pragma GCC poison TREE_OPERAND_LENGTH tree_operand_length

namespace plugin_cxx {

bool _tree_code_helper::IntegralTypeP()
{
  bool p = INTEGRAL_TYPE_P(m_node);
  return p;
}


unsigned int tree_base::TreeCode() const
{
	//Ray:
	// Why we discard data type infomation here?
	// I do not want to depend the enum defined in tree.h:42
	// To keep the data type info, we have some choice:
	// 1. include tree.h   No! Our design purpose is to avoid use it in client code
	// 2. copy the enum    Dirty... It is still not type safe enought, 'enum class' is better
	// ...TODO: explain more, and doc it in our formal document/design principle
	unsigned int code = 
	({
		enum tree_code c = TREE_CODE(m_node);
		static_cast<unsigned int>(c);
	});
	return code;
}

const unsigned char * tree_identifier::IdentifierPointer(void) {
	//Ray:
	// Bug in gcc, inconsistent data type  
	// [plug-inc]/symtab.h:32     ht_identifier.str    : const unsigned char *
	// [plug-inc]/tree.h:1475     IDENTIFIER_POINTER() : const char * 
	// We adopt the actual data type, not the macro's, so we cast it.
	// I do not understand why tree.h:1475 cast it?
	// NOTICE, 'char' is implementation depended. 
	// c-standard-sec-???
	const unsigned char * str =
	__extension__ ({  //Ray: I like this extension, I was finding it for a long time.
	const char* s = IDENTIFIER_POINTER(m_node);
	//static_cast<const unsigned char *>(str); //why cannot used this one? n3242-C++11-last-draft-sec-5.2.9
	reinterpret_cast<const unsigned char *>(s);
	});
	
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


unsigned int tree_type::TypeUid(void)
{
	unsigned int uid = TYPE_UID(m_node);
	return uid;
}

unsigned int tree_type::TypeHash()
{
	unsigned int hash = TYPE_HASH(m_node);
	return hash;
}

//////////////////////////////////////////
bool call_expr::CallExprTailcall()
{
//	bool flag = CALL_EXPR_TAILCALL(m_node);
//	return flag;
	throw 13;
}


}// end namespace plugin_cxx

