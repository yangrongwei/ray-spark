/*
 * cxx-tree.hxx
 *
 *  Mapping various GENERIC 'tree node' to C++ class.
 *
 *  Created on: Mar 14, 2012
 *      Author: ray
 */

#ifndef CXX_TREE_HXX_
#define CXX_TREE_HXX_

//Ray:
//
// I guess, this file can be generated by code, at least with its help.
// But, I do not know how to do it, we map them by hand now...
// Maybe someday later, this file is generated...
//
// The object-in-C style of [plug-inc]/tree.h is
//
// 1. Declaring manipulating macros for new GENERIC 'tree node' first
// 2. Declaring new struct for new GENERIC 'tree node'
//    The style is always put the parent class, which is C struct,
//    at the first field of declaring struct.
// _. Each object-in-C class is sepreated by a FF(form feed) character
//    I saw it in Notepad++, which editor is code maintainer using?
//    Maybe, they have a better view for the character.
//
// The purpose of this file (cxx-tree.hxx) is to wrap these macros into
// C++ member functions. As a result, it will give programmer visual
// shows which exactly the macro is doing from function prototype.
// And give programmer a true object feeling to access various 'tree node'.
//
// Keep in mind, no more, may less...
//
// Hints to map marcro to member function
//
// TODO: copy/translate notes from my SkyDrive into here
//  Two key hints:
//  1. xxx_CHECK   xxx_CST_CHECK
//  2. (NODE)->xxx.foo
// For example
//
// virtual ??

// Code Reference Comment Convention
// This comment points out the original source code position in gcc 4.6.1
//
// -- [dir-prefix] filename : linenumber
//
// 1. When no dir-prefix is given, default directory prefix is [plug-inc]
// 2. When refer to gcc source, we should alway use [gcc-src] prefix
// 3. Valid dir-prefix are:
//    [plug-inc]     plugin include directory for plugin deverlopers
//    [gcc-src]      gcc source code root directory
//
// For example:
// -- tree.h:367                      example 1
// -- [plug-inc]/tree.h:367           example 2
// -- [gcc-src]/gcc/tree.c:8624       example 3
//
//    'example 1' and 'example 2' are equivalent
//
// Informal extended example:
//
// M_ tree TypeCanonical(void);    // -- tree.h:2113, M_2374
//  Macro to member function map
//  1. The macro is defined     in [plug-inc]/tree.h line 2113
//  2. The return type is found in [plug-inc]/tree.h line 2374, which is describing a type specific member
//  -. All setter return the setting value, not 'void'.
//     Why? It will keep same effect as macro does. And maybe who needs it.
//     Cost? Negligible comparing with benefits.
//
// Macro purpose marker list:
//  M_      type specific Member variable getter macro
//  Ms_     type specific Member variable Setter macro
//  P_      like property (value is caculated on-the-foly) accessor
//
//  Pc_   == C_ ??
//  C_      aggregation (container) helper ?? accessor ??
//          // Why not Container ?  Easy to confusing with class,
//          // Somewhat borrowed from UML
//
//  Forward reference, M_ marks it's a type specific member getter
// to mark memeber access ?? (with attribute to verify our code ?? where to put ? I like leading...)
#define M_          // type specific member getter
#define Ms_         // type specific member setter

// Abbriviation list (sadly, used in intuitive name)
//   I want to use full name whenever possible in my coined intuitive name.
//   But, sometimes, the name is too long to read at a glance, which make it be not intuitive.
//   So we have this list. Key consitent express or use them sometime???
// identifier   ident
// pointer      ptr

// strange gcc-macro conversion founds:
// 1. For c-string, the macro uses the name xxx_POINTER (strange, why? like shit)

// Identfiy it is the top/root class in a class hierarchy
// Is handy attribute exist ?
#define ROOT_CLASS

#define LEAF_CLASS
#define MIDDLE_CLASS


// to mark bit-field ??  n1548-c-standard-sec-6.7.2.1-para-9
// 1 bit wide flag bit-field is mapped directly to C++ bool type, type safe purpse...
#define Bf(width)         //bit-field, use less bits in corresponding integer type



#include <stddef.h>



// Copied from [plug-inc]/coretypes.h to avoid include the file.
// Consequently, any file includes this file will not depend on GCC directly.
//
union tree_node;                            // -- coretypes.h:59   defined in -- tree.h:3510
typedef union tree_node *tree;              // -- coretypes.h:96
typedef const union tree_node *const_tree;  // -- coretypes.h:63


namespace plugin_cxx
{
// -- tree.h:347
/* A tree node can represent a data type, a variable, an expression
   or a statement.  Each node has a TREE_CODE which says what kind of
   thing it represents.  Some common codes are:
   INTEGER_TYPE -- represents a type of integers.
   ARRAY_TYPE -- represents a type of pointer.
   VAR_DECL -- represents a declared variable.
   INTEGER_CST -- represents a constant integer value.
   PLUS_EXPR -- represents a sum (an expression).

   As for the contents of a tree node: there are some fields
   that all nodes share.  Each TREE_CODE has various special-purpose
   fields as well.  The fields of a node are never accessed directly,
   always through accessor macros.  */

/* Every kind of tree node starts with this structure,
   so all nodes have these fields.

   See the accessor macros, defined below, for documentation of the
   fields.  */
//
//Ray: It is a base class, which provids lots service, it's large, as expected.
// 'tree_code' is used to distinguish various types.
// The heart of gcc's object-in-c way, its own type system.
// TODO: a brief comments for struct tree_base
// 1. tree_code for custom type system  -- tree.h:368
// 2. various flags                     -- tree.h:370-400
// 3. two other fields, one for flag padding, one for saving space
//    --total bit count of flags ??? caculate it by our demo code
// Hierachy tree
// tree_base                 -- tree.h:367
// \_tree_common             -- tree.h:???
//   +-tree_

// -- plugin/include/tree.h:367
//struct GTY(()) tree_base {
//  ENUM_BITFIELD(tree_code) code : 16;
//
//  unsigned side_effects_flag : 1;
//  unsigned constant_flag : 1;
//  unsigned addressable_flag : 1;
//  //...
class ROOT_CLASS tree_base {
protected:
	tree m_node;
	tree_base(const tree& node) = delete;
	tree_base& operator = (const tree& node) = delete;
public:
	explicit tree_base(tree node):m_node(node){};
	static bool _TryAattach(tree node);

public: // Direct macro to member function map
	//Ray:
	// Bit-field in enum
	// First, I do not understand why bit-field in enum.
	// Then, I realized, enum constants only use limited bits in its storage,
	// there are spare bits can be utilized for its variable... So that's it.
	//
	// ENUM_BITFIELD -- [plug-inc]/system.h:604-608
	//
	// I do not find the extension is documented in gcc-man-4.6.3
	// Only gcc-man-4.6.3-sec-4.9 lists some implementation-defined behavior, no help.
	// This forum topic gives me help.
	// 'enums as bitfields'
	// http://www.velocityreviews.com/forums/t754551-enum-as-bitfields.html
	//
	// Regardless it is bit-field in enum or in int, the bit-filed value is int
	// Signed or unsigned ??? I can only guess...unsigned?
	//
	// Type safe is not very useful here, we should use them rarely. Just int, simple.
	unsigned int Bf(16) TreeCode();                 // -- tree.h:656, M_368  //To more generic type, right?
	unsigned int Bf(16) TreeSetCode(unsigned int);  // -- tree.h:657, Ms_368 //Ray: good or bad? enum can be auto converted

	// -- tree.h:661-941
	// Various TREE_CHECK macro is not mapped here.
	// They are implementation detail, for coding support.
//	//Ray:
//	// TREE_CHECK() macro  --defined in-- plugin/include/tree.h:663
//	// tree_check_failed() function --defined in-- [gcc-src]/gcc/tree.c:8624
//	// internal_error() function --defined in-- [gcc-src]/gcc/diagnostic.c:832
//	bool Try_TREE_CHECK();

	// -- tree.h:947
	// tree code class check ??
	// It seems implementation detai, for coding support.

	// Ray:
	// It seems we do not need mapping xxx_CHECK macros here
	// They will be used in corresponding class constructor, looks like.


    // -- tree.h:970  Ray: Not belong this class ???

	size_t TreeHash();    // -- tree.h:974, P_ based-on this pointer ???

	// skip from 977, later check it

	//Ray: not in this class, and wrong
//	// -- plugin/include/tree.h:993
//	const_tree StripNops(const_tree);       // -- tree.h:993
//	const_tree StripSignNops(const_tree);   // -- tree.h:998
//	const_tree StripTypeNops(const_tree);   // -- tree.h:1003
//	const_tree StripUselessTypeConversion(const_tree);  // -- tree.h:1014

public: // prediate mapping -- macro --> member function

	// Generic type classifying service
	bool IntegralTypeP();         // -- tree.h:1021 P_368
	bool NonSatFixedPointTypeP(); // -- tree.h:1028 P_(368, 386)
	bool SatFixedPointTypeP();    // -- tree.h:1033 P_(368, 386)
	bool FixedPointTypeP();       // -- tree.h:1038 P_368
	bool ScalarFloatTypeP();      // -- tree.h:1042 P_368
    //...till 1102
//	// -- plugin/include/tree.h:1021
//	//...
//	// -- plugin/include/tree.h:1091
//	bool CompleteTypeP();
//	// -- plugin/include/tree.h:1094
//	bool VoidTypeP();


public: // flag-mapping  -- Direct macro to member function map // member access
  //Ray:
  // flag purpose can be found in
  // 1. [plug-in]/tree.h:416-614   A big flag check list for various nodes
  // 2. macro's comment -- tree.h:1107-???        seperated in various location in tree.h
  // 3. the flag name defined in struct tree_base
  // ...
  // Ray: We have opportunity to direct describe various purpose
  //      in subclassed in our Intuitive name section. Each subclass
  //      member function call this one eventually...
  
	// multi-purpose flag, see code comments.
	bool TreeAddressable();       // -- tree.h:1119 M_372
	bool CallExprTailcall();      // -- tree.h:1124 M_372
	// shit, so many purpose...


	bool TypeSaturating();        // -- tree.h:1376 M_386

// -- plugin/include/tree.h:1105
public:
	bool TreeAddressable();  // -- tree.h:1119

	//...
	bool TreeStatic(); // -- tree.h:1142

	//...
	bool TreeSideEffects(); // -- tree.h:1228

	//...
	bool TreeLangFlag0(); // -- tree.h:1379
public: // Direct macro to member function map


};


// -- plugin/include/tree.h:410
// struct GTY(()) tree_common {
// struct tree_base base;
// tree chain;
// tree type;
// };
class tree_common : public tree_base
{
public:
	explicit tree_common(tree node) : tree_base(node){};
// link list access
public:
	tree LinkListGetNext(void);

};



// -- [plug-inc]/double-int.h:54
//typedef struct
//{
//  unsigned HOST_WIDE_INT low;
//  HOST_WIDE_INT high;
//} double_int;
//
// -- tree.h:1409
// struct GTY(()) tree_int_cst {
//   struct tree_common common;
//   double_int int_cst;
// };
class tree_int_cst : public tree_common
{
public: // Direct macro to member function map
	double_int TreeIntCst();                // -- tree.h:1393, M_1411
	unsigned HOST_WIDE_INT TreeIntCstLow(); // -- tree.h:1394, P_1411
	HOST_WIDE_INT TreeIntCstHigh();         // -- tree.h:1395, P_1411
	// tree.h:1397, 1402  ?? not belong this class, but close related.
	// bool IntCstLt (const ) ???
public: // Intuitive name for macro purpose
	// bool operator < (const tree_int_cst&);    // =~= tree.h: WRONG.... both signed and unsigned...conflict
};

// -- tree.h:1422
//struct GTY(()) tree_real_cst {
//  struct tree_common common;
//  struct real_value * real_cst_ptr;
//};
class tree_real_cst : public tree_common
{
public: // Direct macro to member function map
	struct real_value * TreeRealCstPtr();  // -- tree.h:1419, M_1424
	struct real_value TreeRealCst();       // -- tree.h:1420, P_1424
public: // Intuitive name for macro purpose

};

// -- tree.h:1434
//struct GTY(()) tree_fixed_cst {
//  struct tree_common common;
//  struct fixed_value * fixed_cst_ptr;
//};
class tree_fixed_cst : public tree_common
{
public: // Direct macro to member function map
	struct fixed_value * TreeFixedCstPtr();  // -- tree.h:1430, M_1436
	struct fixed_value TreeFixedCst();       // -- tree.h:1432, P_1436 //Ray: Type safe. Cost? Compiler is smart
public: // Intuitive name for macro purpose

};


// -- tree.h:1444
// struct GTY(()) tree_string {
//   struct tree_common common;
//   int length;
//   char str[1];
// };
class tree_string : public tree_common
{
public: // Direct macro to member function map
	int TreeStringLength();            // -- tree.h:1440, M_1446
	const char * TreeStringPointer();  // -- tree.h:1441, M_1447
public: // Intuitive name for macro purpose
	//Ray:
	// Do NOT provide std::string conversion here, useless, boring, maybe stupid...
	// We do not want to depend std library here, unnecessary.
	// Anyone wants it can convert by themself.
};


// -- tree.h:1454
//struct GTY(()) tree_complex {
//  struct tree_common common;
//  tree real;
//  tree imag;
//};
class tree_complex : public tree_common
{
public: // Direct macro to member function map
	tree TreeRealpart(void);  // -- tree.h:1451, M_1456
	tree TreeImagpart(void);  // -- tree.h:1452, M_1457
public: // Intuitive name for macro purpose

};


//Ray:
// tree_vector != tree_vec [plug-inc]/tree.h:1508
//
// tree_vector is a tree representing a language vector, which is also a tree.
// tree_vec    is a tree representing a vector for tree, which is a real vector (C array)
//
// -- tree.h:1463
//struct GTY(()) tree_vector {
//  struct tree_common common;
//  tree elements;
//};
class tree_vector : public tree_common
{
public: // Direct macro to member function map
	tree TreeVectorCstElts(void);    // -- tree.h:1461, M_1465  ???

public: // Intuitive name for macro purpose

};


/*
 * gccint-sec-11.2.1 Identifiers
An IDENTIFIER_NODE represents a slightly more general concept that the standard C or
C++ concept of identifier. In particular, anIDENTIFIER_NODEmay contain a ‘$’, or other
extraordinary characters.
There are never two distinct IDENTIFIER_NODEs representing the same identifier. There-
fore, you may use pointer equality to compare IDENTIFIER_NODEs, rather than using a
routine like strcmp. Use get_identifier to obtain the unique IDENTIFIER_NODE for a
supplied string.
*/

// -- [plug-inc]/symtab.h:32
//struct GTY(()) ht_identifier {
//  const unsigned char *str;
//  unsigned int len;
//  unsigned int hash_value;
//};
//
// -- tree.h:1486
// struct GTY(()) tree_identifier {
//   struct tree_common common;
//   struct ht_identifier id;        // -- [plug-inc]/symtab.h:32  == [gcc-src]/libcpp/include/symtab.h
// };
class tree_identifier : public tree_common
{
public:
	explicit tree_identifier(/*const_*/ tree node) : tree_common(node) {};
public: // Direct macro to member function map
	unsigned int IdentifierLength(void);           // -- tree.h:1472, P_1488
	const unsigned char * DentifierPointer(void);  // -- tree.h:1474, P_1488
	unsigned int HashValue(void);                  // -- tree.h:1476, P_1488
public: // macros used to convert between data types
	// -- tree.h:1479
	/* Translate a hash table identifier pointer to a tree_identifier
	   pointer, and vice versa.  */
	static tree HtIdentToGccIdent(struct ht_identifier *);   // -- tree.h:1482 type convertor
	static struct ht_identifier * GccIdentToHtIdent(tree);   // -- tree.h:1484 type convertor
public:
	bool IdentifierTransparentAlias(); // -- tree.h:1372 ??
public: // Intuitive name for macro purpose
	static tree_identifier _FromHashtableIdentPtr(struct ht_identifier *); // =~= HtIdentToGccIdent
	struct ht_identifier * _ToHashtableIdentPtr(void); // =~= GccIdentToHtIdent
};


// -- tree.h:1495
//struct GTY(()) tree_list {
//  struct tree_common common;
//  tree purpose;
//  tree value;
//};
class tree_list : public tree_common //Ray: tree_list is not a container ???
{
public: // Direct macro to member function map
	tree TreePurpose(void);  // -- tree.h:1492, M_1497
	tree TreeValue(void);    // -- tree.h:1493, M_1498
public: // Intuitive name for macro purpose

};


// -- tree.h:1508
// struct GTY(()) tree_vec {
//   struct tree_common common;
//   int length;
//   tree GTY ((length ("TREE_VEC_LENGTH ((tree)&%h)"))) a[1];
// };
class tree_vec : public tree_common
{
public: // Direct macro to member function map
	int TreeVecLength(void);    // -- tree.h:1502, M_1510
	//??TreeVecEnd(void); // -- tree.h:1503, P_ 1511
	tree TreeVecElt(int index); // -- tree.h:1502, C_ ??
public: // Intuitive name for macro purpose
};


// -- tree.h:1567
//struct GTY(()) tree_constructor {
//  struct tree_common common;
//  VEC(constructor_elt,gc) *elts;
//};
class tree_constructor : public tree_common
{
public: // Direct macro to member function map

public: // Intuitive name for macro purpose

};
//Ray: We really need a container wrapper for VEC, etc.
//     keep it with standard (limited) 'std::' container semantics.


// -- tree.h:1857
//struct GTY(()) tree_exp {
//  struct tree_common common;
//  location_t locus;
//  tree block;
//  tree GTY ((special ("tree_exp"),
//	     desc ("TREE_CODE ((tree) &%0)")))
//    operands[1];
//};
class tree_exp : public tree_common
{
public: // Direct macro to member function map
	location_t SetExprLocation(location_t value);  // tree.h:1602, Ms_1859
	//??ExprFilename(void); // tree.h:1605 P_
	//??ExprLineno(void);   // tree.h:1606 P_
public: // Intuitive name for macro purpose

};

// -- tree.h:1923
//struct GTY(()) tree_ssa_name {
//  struct tree_common common;
//
//  /* _DECL wrapped by this SSA name.  */
//  tree var;
class tree_ssa_name : public tree_common
{
public: // Direct macro to member function map
	tree SsaNameVar(void);       // -- tree.h:1870, M_1927
	gimple SsaNameDefStmt(void); // -- tree.h:1873, M_1930
	unsigned int SsaNameVersion(void); // -- tree.h:1877, M_1933

	// typedef struct GTY(()) ssa_use_operand_d {  // -- tree.h:1908
	struct ssa_use_operand_d SsaNameImmUseNode(void); // -- tree.h:1921, M_1939
public: // Intuitive name for macro purpose

};

//Ray: Since we have M_ in comment, why put it to function declare?
//    Remark, we modify this file from bottom to up

// -- tree.h:1942
//struct GTY(()) phi_arg_d {
//  /* imm_use MUST be the first element in struct because we do some
//     pointer arithmetic with it.  See phi_arg_index_from_use.  */
//  struct ssa_use_operand_d imm_use;
//
//Ray: What's this?

// -- tree.h:1963
//struct GTY(()) tree_omp_clause {
//  struct tree_common common;
//  location_t locus;
//  enum omp_clause_code code;
class tree_omp_clause : public tree_common
{
public: // Direct macro to member function map

public: // Intuitive name for macro purpose

};

// -- tree.h:2034
//struct GTY(()) tree_block {
//  struct tree_common common;
//
//  unsigned abstract_flag : 1;
//  unsigned block_num : 31;
class tree_block : public tree_common
{
public: // Direct macro to member function map
	M_ tree BlockVars(void);                  // -- tree.h:1983, M_2042
	M_ tree BlockSubblocks(void);             // -- tree.h:1990, M_2045
	M_ tree BlockSupercontext(void);          // -- tree.h:1991, M_2046
	M_ tree BlockAbstractOrigin(void);        // -- tree.h:1995, M_2047
	M_ bool BlockAbstract(void);              // -- tree.h:1996, M_2037
	M_ Bf(31) unsigned BlockNumber(void);     // -- tree.h:2001, M_2038
	M_ tree BlockFragmentOrigin(void);        // -- tree.h:2025, M_2048
	M_ tree BlockFragmentChain(void);         // -- tree.h:2026, M_2049
	M_ location_t BlockSourceLocation(void);  // -- tree.h:2032, M_2040
public: // Intuitive name for macro purpose

};



// -- tree.h:2332
//struct GTY(()) tree_type {
//  struct tree_common common;
//  tree values;
//  tree size;
//  //...
class tree_type : public tree_common
{
public: // Direct macro to member function map
	M_ unsigned int TypeUid(void);  // -- tree.h:2063
	M_ tree TypeSize(void);         // -- tree.h:2064
	M_ tree TypeSizeUnit(void);     // -- tree.h:2065
	/*virtual*/ tree TypeValues(void);       // -- tree.h:2066 - 2069  be virtual ?
	// various virtual candidate ??
	// .minval .maxval should be virtual ....
	//
	M_ tree TypePointerTo(void);    // -- tree.h:2075
	M_ tree TypeReferenceTo(void);  // -- tree.h:2076
	M_ Bf(10) unsigned int TypePrecision(void);  // -- tree.h:2340
	M_ tree TypeName(void);         // -- tree.h:2082
	M_ tree TypeNextVariant(void);  // -- tree.h:2083
	M_ tree TypeMainVariant(void);  // -- tree.h:2084
	M_ tree TypeContext(void);      // -- tree.h:2085
	M_ tree TypeMaxval(void);       // -- tree.h:2086, M_2369
	M_ tree TypeMinval(void);       // -- tree.h:2087, M_2368

	// TODO:
	// We need a strong-typed enum, not gcc's C enum in this header file, of course C++11's enum class
	// This means we MUST copy the enum from gcc code, dirty, but it will give us type safe benefit..
//	/*virtual */ M_ enum class machine_mode TypeMode(void);
//	Ms_ enum class machine_mode SetTypeMode(enum class machine_mode);

	M_ tree TypeCanonical(void);    // -- tree.h:2113, M_2374
	M_ struct lang_type * TypeLangSpecific(void);  // -- tree.h:2125, M_2376
	M_ tree TypeAttributes(void);   // -- tree.h:2149, M_2337
	M_ unsigned int TypeAlign(void);// -- tree.h:2153, M_2358
//	/*virtual ??*/ M_ bool TypeNoForceBlk(void);   // -- tree.h:2174, M_2341
	M_ bool TypeRestrict(void);     // -- tree.h:2195, M_2344

	// various semantics, ?? how to handle ??
	// define semantic specific memeber function in subclass?
	// Hide this member function in this class ?? Too arbitrary ??
	// M_ bool TypeStringFlag(void);   // -- tree.h:2253, M_2349

	M_ bool TypeLangFlag0(void);    // -- tree.h:2238, M_2350
	M_ bool TypeLangFlag1(void);    // -- tree.h:2238, M_2351
	M_ bool TypeLangFlag2(void);    // -- tree.h:2238, M_2352
	M_ bool TypeLangFlag3(void);    // -- tree.h:2238, M_2353
	M_ bool TypeLangFlag4(void);    // -- tree.h:2238, M_2354
	M_ bool TypeLangFlag5(void);    // -- tree.h:2238, M_2355
	M_ bool TypeLangFlag6(void);    // -- tree.h:2238, M_2356

	M_ bool TypeNeedsConstructing(void); // -- tree.h:2277, M_2342
    M_ Bf(2) unsigned TypeContainsPlaceholderInternal(void); // -- tree.h:2300, M_2345

    // Following three are defined within a union, mark it??
    M_ int TypeSymtabAddress(void);             // -- tree.h:2312, M_2363
    M_ const char * TypeSymtabPointer(void);    // -- tree.h:2316, M_2364
    M_ struct die_struct * TypeSymtabDie(void); // -- tree.h:2320, M_2365

public: // Intuitive name for macro purpose
    const char * _GetSymtabAsAString(void);
    int _GetSymtabAsAnInteger(void);
    struct die_struct * _GetSymtabAsAPointToADwarfDie(void);
};



// -- tree.h:2482
//struct GTY (()) tree_binfo {
//  struct tree_common common;
//
//  tree offset;
//  //...
class tree_binfo : public tree_common
{
public: // Direct macro to member function map
	tree BinfoOffset(void);    // -- tree.h:2417
	tree BinfoVtable(void);    // -- tree.h:2424
	tree BinfoVirtuals(void);  // -- tree.h:2429
	/*VEC*/ BinfoBaseBinfos(void);  // -- tree.h:2437
	/*VEC_length*/ BinfoNBaseBinfos(void); // -- tree.h:2440
	//...container access ....
	tree BinfoVptrField(void);  // -- tree.h:2455
	//
	tree BinfoSubvttIndex(void);  // -- tree.h:2469
	tree BinfoVptrIndex(void);    // -- tree.h:2473
	tree BinfoInheritanceChain(void)  // -- tree.h:2479
public: // Intuitive name for macro purpose

};

// -- tree.h:2579
//struct GTY(()) tree_decl_minimal {
//  struct tree_common common;
//  location_t locus;
//  unsigned int uid;
//  tree name;
//  tree context;
//};
class tree_decl_minimal : public tree_common
{
public: // Direct macro to member function map
	// typedef source_location location_t;   -- [plug-inc]/input.h:58
	// typedef unsigned int source_location; -- [plug-inc]/line-map.h:42
	location_t DeclSourceLocation(void);  // -- tree.h:2558
	/*virtual*/ tree DeclContext(void);               // -- tree.h:2572  2573 ?? to be virtual ??
	bool DeclNameless(void);              // -- tree.h:2577

public: // Intuitive name for macro purpose

};

// -- tree.h:2747
//struct GTY(()) tree_decl_common {
//  struct tree_decl_minimal common;
//  tree size;
//  //...
class tree_decl_common : public tree_decl_minimal
{
public: // Direct macro to member function map

public: // Intuitive name for macro purpose

};

// -- tree.h:2863
//struct GTY(()) tree_decl_with_rtl {
//  struct tree_decl_common common;
//  rtx rtl;
//};
class tree_decl_with_rtl : public tree_decl_common
{
public: // Direct macro to member function map

public: // Intuitive name for macro purpose

};

// -- tree.h:2931
//struct GTY(()) tree_field_decl {
//  struct tree_decl_common common;
//
//  tree offset;
//  tree bit_field_type;
//  tree qualifier;
//  tree bit_offset;
//  tree fcontext;
//};
class tree_field_decl : public tree_decl_common
{
public: // macro to member function map
};

// -- tree.h:2954
//struct GTY(()) tree_label_decl {
//  struct tree_decl_with_rtl common;
//  int label_decl_uid;
//  int eh_landing_pad_nr;
//};
class tree_label_decl : public tree_decl_with_rtl
{
public: // macro to member function map
	int LabelDeclUid();    // -- tree.h:2944
	int EhLandingPadNr();  // -- tree.h:2949
};


// -- tree.h:2964
//struct GTY(()) tree_result_decl {
//  struct tree_decl_with_rtl common;
//  struct var_ann_d *ann;
//};
class tree_result_decl : public tree_decl_with_rtl
{
public: // macro to member function map
};

// -- tree.h:2969
//struct GTY(()) tree_const_decl {
//  struct tree_decl_with_rtl common;
//};
class tree_const_decl : public tree_decl_with_rtl
{
public: // macro to member function map
};

// -- tree.h:2982
//struct GTY(()) tree_parm_decl {
//  struct tree_decl_with_rtl common;
//  rtx incoming_rtl;
//  struct var_ann_d *ann;
//};
class tree_parm_decl : public tree_decl_with_rtl
{
public: // macro to member function map

};


// -- tree.h:3121
//struct GTY(()) tree_decl_with_vis {
// struct tree_decl_with_rtl common;
// tree assembler_name;
// tree section_name;
// tree comdat_group;
// //...
class tree_decl_with_vis : public tree_decl_with_rtl
{
public: // macro to member function map

	/* Nonzero for a given ..._DECL node means that no warnings should be
	   generated just because this node is unused.  */
	bool DeclInSystemHeader(); // -- tree.h:2991
	/* Used to indicate that the linkage status of this DECL is not yet known,
	   so it should not be output now.  */
	bool DeclDeferOutput(); // -- tree.h:2996
	/* In a VAR_DECL that's static,
	   nonzero if the space is in the text section.  */
	bool DeclInTextSection(); // -- tree.h:3001
	/* In a VAR_DECL that's static,
	   nonzero if it belongs to the global constant pool.  */
	bool DeclInConstantPool(); // -- tree.h:3006
	/* Nonzero for a given ..._DECL node means that this node should be
	   put in .common, if possible.  If a DECL_INITIAL is given, and it
	   is not error_mark_node, then the decl cannot be put in .common.  */
	bool DeclCommon();      // -- tree.h:3012
	/* Used to indicate that this DECL has weak linkage.  */
	bool DeclWeak();  // -- tree.h:3021
	/* Used to indicate that the DECL is a dllimport.  */
	bool DeclDllimportP(); // -- tree.h:3024
	/* Return true if NODE is a NODE that can contain a DECL_ASSEMBLER_NAME.
	   This is true of all DECL nodes except FIELD_DECL.  */
	bool HasDeclAssemblerNameP(); // -- tree.h:3053
};

// -- tree.h:3205
//struct GTY(()) tree_var_decl {
//  struct tree_decl_with_vis common;
//  struct var_ann_d *ann;
//};
class tree_var_decl : public tree_decl_with_vis
{

};

// -- tree.h:3227
//struct GTY(())
// tree_decl_non_common {
//  struct tree_decl_with_vis common;
//  /* C++ uses this in namespaces.  */
//  tree saved_tree;
//  /* C++ uses this in templates.  */
//  tree arguments;
//  /* Almost all FE's use this.  */
//  tree result;
//  /* C++ uses this in namespaces.  */
//  tree vindex;
//};
class tree_decl_non_common : public tree_decl_with_vis
{

public: // macro to member function map
	tree DeclResultFld(); // -- tree.h:3213
	tree DeclVindex();    // -- tree.h:3224
};


// -- tree.h:3369
/* FUNCTION_DECL inherits from DECL_NON_COMMON because of the use of the
   arguments/result/saved_tree fields by front ends.   It was either inherit
   FUNCTION_DECL from non_common, or inherit non_common from FUNCTION_DECL,
   which seemed a bit strange.  */
//struct GTY(()) tree_function_decl {
//  struct tree_decl_non_common common;
//
//  struct function *f;
//  //...
class tree_function_decl : public tree_decl_non_common
{
public: // macro to member function map

};

// -- tree.h:3417
/* TRANSLATION_UNIT_DECL inherits from DECL_MINIMAL.  */
//struct GTY(()) tree_translation_unit_decl {
//  struct tree_decl_common common;
//  /* Source language of this translation unit.  Used for DWARF output.  */
//  const char * GTY((skip(""))) language;
//  /* TODO: Non-optimization used to build this translation unit.  */
//  /* TODO: Root of a partial DWARF tree for global types and decls.  */
//};
class tree_translation_unit_decl : public tree_decl_common
{

public: // macro to member function map
	const char * TranslationUnitLanguage(); // -- tree.h:??
};


// -- tree.h:3443
//struct GTY(()) tree_type_decl {
//  struct tree_decl_non_common common;
//
//};
class tree_type_decl : public tree_decl_non_common
{

};

// -- tree.h:3466
//struct GTY(()) tree_statement_list
// {
//  struct tree_common common;
//  struct tree_statement_list_node *head;
//  struct tree_statement_list_node *tail;
//};
class tree_statement_list : public tree_common
{

};

// -- tree.h:3476
/* Optimization options used by a function.  */
//struct GTY(()) tree_optimization_option {
//  struct tree_common common;
//
//  /* The optimization options used by the user.  */
//  struct cl_optimization opts;
//};
class tree_optimization_option : public tree_common
{

};

// -- tree.h:3491
/* Target options used by a function.  */
//struct GTY(()) tree_target_option {
//  struct tree_common common;
//
//  /* The optimization options used by the user.  */
//  struct cl_target_option opts;
//};
class tree_target_option : public tree_common
{
public:

};


}// end namespace plugin_cxx

//#pragma GCC poison tree


#endif /* CXX_TREE_HXX_ */
