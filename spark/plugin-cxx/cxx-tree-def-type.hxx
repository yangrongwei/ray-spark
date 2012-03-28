/*
 * cxx-tree-def-type.hxx
 *
 *  Every xxx_TYPE tree_code found in
 *
 *  [plug-inc]/tree.def    (but not in [plug-inc]/tree.h)
 *
 *  tcc_type
 *
 *  Created on: Mar 27, 2012
 *      Author: ray
 */

#ifndef CXX_TREE_DEF_TYPE_HXX_
#define CXX_TREE_DEF_TYPE_HXX_

#include "cxx-tree.hxx"

namespace plugin_cxx
{

// +-tree_type                    -- tree.h:2332
//   +enumeral_type  -- tree.def:136
//
//

// -- tree.def:81
/* Each data type is represented by a tree node whose code is one of
   the following:  */
/* Each node that represents a data type has a component TYPE_SIZE
   containing a tree that is an expression for the size in bits.
   The TYPE_MODE contains the machine mode for values of this type.
   The TYPE_POINTER_TO field contains a type for a pointer to this type,
     or zero if no such has been created yet.
   The TYPE_NEXT_VARIANT field is used to chain together types
     that are variants made by type modifiers such as "const" and "volatile".
   The TYPE_MAIN_VARIANT field, in any member of such a chain,
     points to the start of the chain.
   The TYPE_NAME field contains info on the name used in the program
     for this type (for GDB symbol table output).  It is either a
     TYPE_DECL node, for types that are typedefs, or an IDENTIFIER_NODE
     in the case of structs, unions or enums that are known with a tag,
     or zero for types that have no special name.
   The TYPE_CONTEXT for any sort of type which could have a name or
    which could have named members (e.g. tagged types in C/C++) will
    point to the node which represents the scope of the given type, or
    will be NULL_TREE if the type has "file scope".  For most types, this
    will point to a BLOCK node or a FUNCTION_DECL node, but it could also
    point to a FUNCTION_TYPE node (for types whose scope is limited to the
    formal parameter list of some function type specification) or it
    could point to a RECORD_TYPE, UNION_TYPE or QUAL_UNION_TYPE node
    (for C++ "member" types).
    For non-tagged-types, TYPE_CONTEXT need not be set to anything in
    particular, since any type which is of some type category  (e.g.
    an array type or a function type) which cannot either have a name
    itself or have named members doesn't really have a "scope" per se.
  The TREE_CHAIN field is used as a forward-references to names for
    ENUMERAL_TYPE, RECORD_TYPE, UNION_TYPE, and QUAL_UNION_TYPE nodes;
    see below.  */

// -- tree.def:114
/* The ordering of the following codes is optimized for the checking
   macros in tree.h.  Changing the order will degrade the speed of the
   compiler.  OFFSET_TYPE, ENUMERAL_TYPE, BOOLEAN_TYPE, INTEGER_TYPE,
   REAL_TYPE, POINTER_TYPE.  */

// -- tree.def:123
/* An offset is a pointer relative to an object.
   The TREE_TYPE field is the type of the object at the offset.
   The TYPE_OFFSET_BASETYPE points to the node for the type of object
   that the offset is relative to.  */
//DEFTREECODE (OFFSET_TYPE, "offset_type", tcc_type, 0)
class offset_type
{
public:
	tree TypeOffsetBasetype(); // -- tree.h:2074 M_2369
};

//Ray: Satisfy NUMERICAL_TYPE_CHECK() -- tree.h:964
// INTEGER_TYPE, ENUMERAL_TYPE, BOOLEAN_TYPE, REAL_TYPE, FIXED_POINT_TYPE
class _numerical_type
{
public:
	tree TypeMinValue(); // -- tree.h:2079 M_2368
	tree TypeMaxValue(); // -- tree.h:2080 M_2369

};

// -- tree.def:136
/* C enums.  The type node looks just like an INTEGER_TYPE node.
   The symbols for the values of the enum type are defined by
   CONST_DECL nodes, but the type does not point to them;
   however, the TYPE_VALUES is a list in which each element's TREE_PURPOSE
   is a name and the TREE_VALUE is the value (an INTEGER_CST node).  */
/* A forward reference `enum foo' when no enum named foo is defined yet
   has zero (a null pointer) in its TYPE_SIZE.  The tag name is in
   the TYPE_NAME field.  If the type is later defined, the normal
   fields are filled in.
   RECORD_TYPE, UNION_TYPE, and QUAL_UNION_TYPE forward refs are
   treated similarly.  */
//DEFTREECODE (ENUMERAL_TYPE, "enumeral_type", tcc_type, 0)
class enumeral_type : public _numerical_type
{
public:
	tree TypeValues(); // -- tree.h:2066 M_2334

};

// -- tree.def:140
/* Boolean type (true or false are the only values).  Looks like an
   INTEGRAL_TYPE.  */
//DEFTREECODE (BOOLEAN_TYPE, "boolean_type", tcc_type, 0)
class boolean_type : public _numerical_type
{

};

// -- tree.def:150
/* Integer types in all languages, including char in C.
   Also used for sub-ranges of other discrete types.
   Has components TYPE_MIN_VALUE, TYPE_MAX_VALUE (expressions, inclusive)
   and TYPE_PRECISION (number of bits used by this type).
   In the case of a subrange type in Pascal, the TREE_TYPE
   of this will point at the supertype (another INTEGER_TYPE,
   or an ENUMERAL_TYPE or BOOLEAN_TYPE).
   Otherwise, the TREE_TYPE is zero.  */
//DEFTREECODE (INTEGER_TYPE, "integer_type", tcc_type, 0)
class integer_type : public _numerical_type
{
public:

	// -- tree.h:2176
	/* In an INTEGER_TYPE, it means the type represents a size.  We use
	   this both for validity checking and to permit optimizations that
	   are unsafe for other types.  Note that the C `size_t' type should
	   *not* have this flag set.  The `size_t' type is simply a typedef
	   for an ordinary integer type that happens to be the type of an
	   expression returned by `sizeof'; `size_t' has no special
	   properties.  Expressions whose type have TYPE_IS_SIZETYPE set are
	   always actual sizes.  */
	bool TypeIsSizetype(); // -- tree.h:2184, M_2341

};

// -- tree.def:154
/* C's float and double.  Different floating types are distinguished
   by machine mode and by the TYPE_SIZE and the TYPE_PRECISION.  */
//DEFTREECODE (REAL_TYPE, "real_type", tcc_type, 0)
class real_type : public _numerical_type
{

};

// -- tree.def:156
/* The ordering of the following codes is optimized for the checking
   macros in tree.h.  Changing the order will degrade the speed of the
   compiler.  POINTER_TYPE, REFERENCE_TYPE.  Note that this range
   overlaps the previous range of ordered types.  */

// -- tree.def:163
/* All pointer-to-x types have code POINTER_TYPE.
   The TREE_TYPE points to the node for the type pointed to.  */
//DEFTREECODE (POINTER_TYPE, "pointer_type", tcc_type, 0)
class pointer_type
{
public:
	tree TypeNextPtrTo(); // -- tree.h:2077 M_2360

};

// -- tree.def:167
/* A reference is like a pointer except that it is coerced
   automatically to the value it points to.  Used in C++.  */
//DEFTREECODE (REFERENCE_TYPE, "reference_type", tcc_type, 0)
class reference_type
{
public:
	tree TypeNextRefTo(); // -- tree.h:2078 M_2360
};

// -- tree.def:170
/* The C++ decltype(nullptr) type.  */
//DEFTREECODE (NULLPTR_TYPE, "nullptr_type", tcc_type, 0)
class nullptr_type
{

};

// -- tree.def:175
/* _Fract and _Accum types in Embedded-C.  Different fixed-point types
   are distinguished by machine mode and by the TYPE_SIZE and the
   TYPE_PRECISION.  */
//DEFTREECODE (FIXED_POINT_TYPE, "fixed_point_type", tcc_type, 0)
class fixed_point_type : public _numerical_type
{

};

// -- tree.def:177
/* The ordering of the following codes is optimized for the checking
   macros in tree.h.  Changing the order will degrade the speed of the
   compiler.  COMPLEX_TYPE, VECTOR_TYPE, ARRAY_TYPE.  */

// -- tree.def:184
/* Complex number types.  The TREE_TYPE field is the data type
   of the real and imaginary parts.  It must be of scalar
   arithmetic type, not including pointer type.  */
//DEFTREECODE (COMPLEX_TYPE, "complex_type", tcc_type, 0)
class complex_type
{

};

// -- tree.def:189
/* Vector types.  The TREE_TYPE field is the data type of the vector
   elements.  The TYPE_PRECISION field is the number of subparts of
   the vector.  */
//DEFTREECODE (VECTOR_TYPE, "vector_type", tcc_type, 0)
class vector_type
{

};

// -- tree.def:191
/* The ordering of the following codes is optimized for the checking
   macros in tree.h.  Changing the order will degrade the speed of the
   compiler.  ARRAY_TYPE, RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE.
   Note that this range overlaps the previous range.  */

// -- tree.def:205
/* Types of arrays.  Special fields:
   TREE_TYPE		  Type of an array element.
   TYPE_DOMAIN		  Type to index by.
			    Its range of values specifies the array length.
 The field TYPE_POINTER_TO (TREE_TYPE (array_type)) is always nonzero
 and holds the type to coerce a value of that array type to in C.
 TYPE_STRING_FLAG indicates a string (in contrast to an array of chars)
 in languages (such as Chill) that make a distinction.  */
/* Array types in C or Pascal */
//DEFTREECODE (ARRAY_TYPE, "array_type", tcc_type, 0)
class array_type
{
public:
	tree TypeDomain(); // -- tree.h:2067 M_2334
public:
	//tree _TypeOfAnArrayElement();
};

//Ray TODO: To put where?
// this class (the check macro) is not strict,
// But the intention is clear.
//
//Ray: Satisfy NOT_RECORD_OR_UNION_CHECK() -- tree.h:961
class _not_record_or_union
{
public:
	tree TypeLangSlot1(); // -- tree.h:2134 M_2372
};

//Ray: Satisfy RECORD_OR_UNION_CHECK() -- tree.h:959
class _record_or_union // RECORD_TYPE, UNION_TYPE, QUAL_UNION_TYPE
{
public:
	//Ray: if we can ensure this class has only three subclass
	//     These member function, can be not virtual.
	tree TypeFields();  // -- tree.h:2068 M_2334
	tree TypeMethods(); // -- tree.h:2070 M_2369
	tree TypeVfield();  // -- tree.h:2071 M_2368
	tree TypeBinfo();   // -- tree.h:2131 M_2372
public:
	//?? static const Enum(tree_code)[] _GetClassTreeCodes(); //Ray: to get valid tree_codes
};

// -- tree.def:215
/* Struct in C, or record in Pascal.  */
/* Special fields:
   TYPE_FIELDS  chain of FIELD_DECLs for the fields of the struct,
     and VAR_DECLs, TYPE_DECLs and CONST_DECLs for record-scope variables,
     types and enumerators.
   A few may need to be added for Pascal.  */
/* See the comment above, before ENUMERAL_TYPE, for how
   forward references to struct tags are handled in C.  */
//DEFTREECODE (RECORD_TYPE, "record_type", tcc_type, 0)
class record_type : public _record_or_union
{
public:
};

// -- tree.def:221
/* Union in C.  Like a struct, except that the offsets of the fields
   will all be zero.  */
/* See the comment above, before ENUMERAL_TYPE, for how
   forward references to union tags are handled in C.  */
//DEFTREECODE (UNION_TYPE, "union_type", tcc_type, 0)	/* C union type */
class union_type : public _record_or_union
{
public:
};

// -- tree.def:227
/* Similar to UNION_TYPE, except that the expressions in DECL_QUALIFIER
   in each FIELD_DECL determine what the union contains.  The first
   field whose DECL_QUALIFIER expression is true is deemed to occupy
   the union.  */
//DEFTREECODE (QUAL_UNION_TYPE, "qual_union_type", tcc_type, 0)
class qual_union_type : public _record_or_union
{
public:
};

/* The ordering of the following codes is optimized for the checking
   macros in tree.h.  Changing the order will degrade the speed of the
   compiler.  VOID_TYPE, FUNCTION_TYPE, METHOD_TYPE.  */

// -- tree.def:234
/* The void type in C */
//DEFTREECODE (VOID_TYPE, "void_type", tcc_type, 0)
class void_type
{
public:

};

//Ray: Satisfy FUNC_OR_METHOD_CHECK() -- tree.h
class _func_or_method // FUNCTION_TYPE, METHOD_TYPE
{
public:
	tree TypeArgTypes();       // -- tree.h:2072 M_2334
	tree TypeMethodBasetype(); // -- tree.h:2073 M_2369
};

// -- tree.def:242
/* Type of functions.  Special fields:
   TREE_TYPE		    type of value returned.
   TYPE_ARG_TYPES      list of types of arguments expected.
	this list is made of TREE_LIST nodes.
   Types of "Procedures" in languages where they are different from functions
   have code FUNCTION_TYPE also, but then TREE_TYPE is zero or void type.  */
// DEFTREECODE (FUNCTION_TYPE, "function_type", tcc_type, 0)
class function_type : public _func_or_method
{
public:

};

// -- tree.def:249
/* METHOD_TYPE is the type of a function which takes an extra first
   argument for "self", which is not present in the declared argument list.
   The TREE_TYPE is the return type of the method.  The TYPE_METHOD_BASETYPE
   is the type of "self".  TYPE_ARG_TYPES is the real argument list, which
   includes the hidden argument for "self".  */
//DEFTREECODE (METHOD_TYPE, "method_type", tcc_type, 0)
class method_type : public _func_or_method
{
public:

};

// -- tree.def:255
/* This is a language-specific kind of type.
   Its meaning is defined by the language front end.
   layout_type does not know how to lay this out,
   so the front-end must do so manually.  */
//DEFTREECODE (LANG_TYPE, "lang_type", tcc_type, 0)
class lang_type
{
public:

};

}// end namespace plugin_cxx

#endif /* CXX_TREE_DEF_TYPE_HXX_ */
