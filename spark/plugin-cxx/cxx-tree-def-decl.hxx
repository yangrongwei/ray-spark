/*
 * cxx-tree-def-decl.hxx
 *
 *  Created on: Mar 29, 2012
 *      Author: ray
 */

#ifndef CXX_TREE_DEF_DECL_HXX_
#define CXX_TREE_DEF_DECL_HXX_


#include "cxx-tree.hxx"

namespace plugin_cxx
{
// --tree.def:286-379
/* Declarations.  All references to names are represented as ..._DECL
   nodes.  The decls in one binding context are chained through the
   TREE_CHAIN field.  Each DECL has a DECL_NAME field which contains
   an IDENTIFIER_NODE.  (Some decls, most often labels, may have zero
   as the DECL_NAME).  DECL_CONTEXT points to the node representing
   the context in which this declaration has its scope.  For
   FIELD_DECLs, this is the RECORD_TYPE, UNION_TYPE, or
   QUAL_UNION_TYPE node that the field is a member of.  For VAR_DECL,
   PARM_DECL, FUNCTION_DECL, LABEL_DECL, and CONST_DECL nodes, this
   points to either the FUNCTION_DECL for the containing function, the
   RECORD_TYPE or UNION_TYPE for the containing type, or NULL_TREE or
   a TRANSLATION_UNIT_DECL if the given decl has "file scope".
   DECL_ABSTRACT_ORIGIN, if non-NULL, points to the original (abstract)
    ..._DECL node of which this decl is an (inlined or template expanded)
    instance.
   The TREE_TYPE field holds the data type of the object, when relevant.
    LABEL_DECLs have no data type.  For TYPE_DECL, the TREE_TYPE field
    contents are the type whose name is being declared.
   The DECL_ALIGN, DECL_SIZE,
    and DECL_MODE fields exist in decl nodes just as in type nodes.
    They are unused in LABEL_DECL, TYPE_DECL and CONST_DECL nodes.

   DECL_FIELD_BIT_OFFSET holds an integer number of bits offset for
   the location.  DECL_VOFFSET holds an expression for a variable
   offset; it is to be multiplied by DECL_VOFFSET_UNIT (an integer).
   These fields are relevant only in FIELD_DECLs and PARM_DECLs.

   DECL_INITIAL holds the value to initialize a variable to,
   or the value of a constant.  For a function, it holds the body
   (a node of type BLOCK representing the function's binding contour
   and whose body contains the function's statements.)  For a LABEL_DECL
   in C, it is a flag, nonzero if the label's definition has been seen.

   PARM_DECLs use a special field:
   DECL_ARG_TYPE is the type in which the argument is actually
    passed, which may be different from its type within the function.

   FUNCTION_DECLs use four special fields:
   DECL_ARGUMENTS holds a chain of PARM_DECL nodes for the arguments.
   DECL_RESULT holds a RESULT_DECL node for the value of a function.
    The DECL_RTL field is 0 for a function that returns no value.
    (C functions returning void have zero here.)
    The TREE_TYPE field is the type in which the result is actually
    returned.  This is usually the same as the return type of the
    FUNCTION_DECL, but it may be a wider integer type because of
    promotion.
   DECL_FUNCTION_CODE is a code number that is nonzero for
    built-in functions.  Its value is an enum built_in_function
    that says which built-in function it is.

   DECL_SOURCE_FILE holds a filename string and DECL_SOURCE_LINE
   holds a line number.  In some cases these can be the location of
   a reference, if no definition has been seen.

   DECL_ABSTRACT is nonzero if the decl represents an abstract instance
   of a decl (i.e. one which is nested within an abstract instance of a
   inline function.  */

// -- tree.def:344
//DEFTREECODE (FUNCTION_DECL, "function_decl", tcc_declaration, 0)
class function_decl
{
public:

};

// -- tree.def:345
//DEFTREECODE (LABEL_DECL, "label_decl", tcc_declaration, 0)
class label_decl
{

};

// -- tree.def:346
/* The ordering of the following codes is optimized for the checking
   macros in tree.h.  Changing the order will degrade the speed of the
   compiler.  FIELD_DECL, VAR_DECL, CONST_DECL, PARM_DECL,
   TYPE_DECL.  */

// -- tree.def:350
//DEFTREECODE (FIELD_DECL, "field_decl", tcc_declaration, 0)
class field_decl
{
public:
	tree DeclFieldContext();  // -- tree.h:2573 M_(2584 tree_decl_minimal)
};

//Ray: Satisfy TREE_CHECK3 in DECL_HAS_VALUE_EXPR_P -- tree.h:2825
// VAR_DECL, PARM_DECL, RESULT_DECL
class _decl_has_value_expr
{
public:
	//Ray: this one is strange put into here or 'tree_decl_common'
	//    I think here is better, the reason is why gcc use check
  //    It is not expected in other decl
  //
	/* In a VAR_DECL or PARM_DECL, the location at which the value may be found,
	   if transformations have made this more complicated than evaluating the
	   decl itself.  This should only be used for debugging; once this field has
	   been set, the decl itself may not legitimately appear in the function.  */
	bool DeclHasValueExprP(); // -- tree.h:2825 M_2781
};

// -- tree.def:351
//DEFTREECODE (VAR_DECL, "var_decl", tcc_declaration, 0)
class var_decl
{

};

// -- tree.def:352
//DEFTREECODE (CONST_DECL, "const_decl", tcc_declaration, 0)
class const_decl
{

};

// -- tree.def:353
//DEFTREECODE (PARM_DECL, "parm_decl", tcc_declaration, 0)
class parm_decl
{

};

// -- tree.def:354
//DEFTREECODE (TYPE_DECL, "type_decl", tcc_declaration, 0)
class type_decl
{

};

// -- tree.def:355
//DEFTREECODE (RESULT_DECL, "result_decl", tcc_declaration, 0)
class result_decl
{

};

// -- tree.def:359
/* A "declaration" of a debug temporary.  It should only appear in
   DEBUG stmts.  */
//DEFTREECODE (DEBUG_EXPR_DECL, "debug_expr_decl", tcc_declaration, 0)
class debug_expr_decl
{
public:
	/* DEBUG_EXPR_DECLs get negative UID numbers, to catch erroneous
	   uses.  */
	signed int DebugTempUid();  // -- tree.h:2539 P_2582
};

// -- tree.def:363
/* A namespace declaration.  Namespaces appear in DECL_CONTEXT of other
   _DECLs, providing a hierarchy of names.  */
//DEFTREECODE (NAMESPACE_DECL, "namespace_decl", tcc_declaration, 0)
class namespace_decl
{

};

// -- tree.def:374
/* A declaration import.
   The C++ FE uses this to represent a using-directive; eg:
   "using namespace foo".
   But it could be used to represent any declaration import construct.
   Whenever a declaration import appears in a lexical block, the BLOCK node
   representing that lexical block in GIMPLE will contain an IMPORTED_DECL
   node, linked via BLOCK_VARS accessor of the said BLOCK.
   For a given NODE which code is IMPORTED_DECL,
   IMPORTED_DECL_ASSOCIATED_DECL (NODE) accesses the imported declaration.  */
//DEFTREECODE (IMPORTED_DECL, "imported_decl", tcc_declaration, 0)
class imported_decl
{

};

// -- tree.def:378
///* A translation unit.  This is not technically a declaration, since it
//   can't be looked up, but it's close enough.  */
//DEFTREECODE (TRANSLATION_UNIT_DECL, "translation_unit_decl",\
//	     tcc_declaration, 0)
class translation_unit_decl
{

};


}// end namespace plugin_cxx


#endif /* CXX_TREE_DEF_DECL_HXX_ */
