/*
 * cxx-tree-enum.hxx
 *
 *  Provid type safe enum (scoped enum), C++11 new feature. Since gcc 4.4
 *
 *  Although, I do not want, but the enums are copied directly from gcc
 *  source code, just add a single world within type declaration -- class.
 *
 *  Created on: Mar 21, 2012
 *      Author: ray
 */

#ifndef CXX_TREE_ENUM_HXX_
#define CXX_TREE_ENUM_HXX_

namespace plugin_cxx
{

// -- tree.h:43
#define DEFTREECODE(SYM, STRING, TYPE, NARGS)   SYM,
#define END_OF_BASE_TREE_CODES LAST_AND_UNUSED_TREE_CODE,

enum class tree_code {
#include "all-tree.def"
MAX_TREE_CODES
};

#undef DEFTREECODE
#undef END_OF_BASE_TREE_CODES

// -- tree.h:54
const int  _gNumberOfLanguageIndepentTreeCodes =  (int) tree_code::LAST_AND_UNUSED_TREE_CODE;
//Ray: maybe we are too far ??

// -- tree.h:61
enum class tree_code_class {
  tcc_exceptional, /* An exceptional code (fits no category).  */
  tcc_constant,    /* A constant.  */
  /* Order of tcc_type and tcc_declaration is important.  */
  tcc_type,        /* A type object code.  */
  tcc_declaration, /* A declaration (also serving as variable refs).  */
  tcc_reference,   /* A reference to storage.  */
  tcc_comparison,  /* A comparison expression.  */
  tcc_unary,       /* A unary arithmetic expression.  */
  tcc_binary,      /* A binary arithmetic expression.  */
  tcc_statement,   /* A statement expression, which have side effects
                      but usually no interesting value.  */
  tcc_vl_exp,      /* A function call or other expression with a
                      variable-length operand vector.  */
  tcc_expression   /* Any other expression.  */
};

//Ray: We are unable to define member functions for enum...
class tree_code_class_helper
{
	enum class tree_code_class m_tcc_value;
public:
	explicit tree_code_class_helper(enum class tree_code_class tcc_value):m_tcc_value(tcc_value){}
	// Ray:???
//	tree_code_class_helper(const tree_code_class_helper&) = delete;
//	tree_code_class_helper& opertor = (const tree_code_class_helper&) = delete;
public:
	/* Returns the string representing CLASS.  */
	static const char * TreeCodeClassString(enum class tree_code_class); // tree.h:85


//  Predicate macros
// -- plugin/include/tree.h:91-
public:
	//TODO: Ray, use long name??m,
	// IsRepresentingxxxx()
	bool IsExceptional();
	bool IsConstant();
	bool IsType();
	//...TODO extend...
public:
	// -- plugin/include/tree.h:89
	static TreeCodeClass QueryTreeCodeClass(int code);
};

}//end namespace plugin_cxx


// -- tree.h:190
typedef enum class {
  ALIAS_DIAG_NONE      = 0x0,
  ALIAS_DIAG_TO_UNDEF  = 0x1,
  ALIAS_DIAG_TO_EXTERN = 0x2
} alias_diag_flags;

}// end namespace plugin_cxx


#endif /* CXX_TREE_ENUM_HXX_ */
