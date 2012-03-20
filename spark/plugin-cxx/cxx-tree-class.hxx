/*
 * cxx-tree-class.h
 *
 *  Created on: Mar 18, 2012
 *      Author: ray
 */

#ifndef CXX_TREE_CLASS_H_
#define CXX_TREE_CLASS_H_

namespace plugin_cxx
{



// -- [plugin-inc]/tree.h:347
/* A tree node can represent a data type, a variable, an expression
   or a statement.  Each node has a TREE_CODE which says what kind of
   thing it represents. ...

   As for the contents of a tree node: there are some fields
   that all nodes share.  Each TREE_CODE has various special-purpose
   fields as well.  The fields of a node are never accessed directly,
   always through accessor macros.  */
enum class TreeCode
{

};


// -- [plugin-inc]/tree.h:61
//Ray: We have various tree_code, but only limited tree_code_class.
//     The purpose of tree_code_class should be *classifying* tree_code.
//
/* Each tree_code has an associated code class represented by a
   TREE_CODE_CLASS.  */
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


#endif /* CXX_TREE_CLASS_H_ */
