/*
 * cxx-tree-def.hxx
 *
 *  Every xxx_EXPR tree_code found in
 *
 *  [plug-inc]/tree.def    (but not in [plug-inc]/tree.h)
 *  [plug-inc]/tree.h:61   enum tree_code_class
 *
 *  fall into this file.
 *
 *  And others, in working status, I may refine the comment or the file.
 *
 *  Created on: Mar 27, 2012
 *      Author: ray
 */

#ifndef CXX_TREE_DEF_HXX_
#define CXX_TREE_DEF_HXX_

#include "cxx-tree.hxx"

namespace plugin_cxx
{

//////////////////////////////////////////////////
//Ray: extend classes according to tree_code (which is not in 'union tree_node')

// tree_exp
// +-call_expr -- tree.def:529
// +-case_label_expr  -- tree.def:866
// +-predict_expr    -- tree.def:1155
//
// +-tcc_expression  -- tree.h:75
//   +-target_expr     -- tree.def:472
// +-tcc_vl_exp      -- tree.h:73
// +-tcc_statement   -- tree.h:71

//////////////////////////////////////////////////
// For each 'tree_code_class', define an interface ???
class tcc_exceptional
{
public:
//	virtual
};

class tcc_vl_exp
{
public:
	virtual int TreeOperandLength() = 0;  // -- tree.h:1580==5607
};

class tcc_expression
{
public:
	virtual int TreeOperandLength() = 0;  // -- tree.h:1580==5607
};

class vl_exp : public tree_exp //satisfy VL_EXP_CHECK--tree.h:955
{
public:
	static tree VlExpCheck(tree);  // -- tree.h:955
public:
	/* In a tcc_vl_exp node, operand 0 is an INT_CST node holding the operand
	   length.  Its value includes the length operand itself; that is,
	   the minimum valid length is 1.*/
	int VlExpOperandLength();  // -- tree.h:1588
};

//////////////////////////////////////////////////
// in tree.h:1572- macro order

// -- tree.h:846
/* A loop.  Operand 0 is the body of the loop.
   It must contain an EXIT_EXPR or is an infinite loop.
   The type should be void and the value should be ignored.  */
//DEFTREECODE (LOOP_EXPR, "loop_expr", tcc_statement, 1)
class loop_expr  // base.code ==  LOOP_EXPR
{
public:
	tree LoopExprBody();  // -- tree.h:1595 P_1863 // tree_exp
public:
	//?? static const Enum(tree_code) _GetClassTreeCode(); // LOOP_EXPR
};

// tree.h:1614-1617 TARGET_EXPR accessor
//
/* For TARGET_EXPR, operand 0 is the target of an initialization,
   operand 1 is the initializer for the target, which may be void
     if simply expanding it initializes the target.
   operand 2 is the cleanup for this node, if any.
   operand 3 is the saved initializer after this node has been
   expanded once; this is so we can re-expand the tree later.  */
// -- tree.def:472
//DEFTREECODE (TARGET_EXPR, "target_expr", tcc_expression, 4)
class target_expr : public tree_exp // base.code == TARGET_EXPR
{
public:
	tree TargetExprSlot();    // -- tree.h:1651 P_1863
	tree TargetExprInitial(); // -- tree.h:1616 P_1863
	tree TargetExprCleanup(); // -- tree.h:1617 P_1863
};

// tree.h:1619-1621 DECL_EXPR accessor
//
// -- tree.def:821
/* Used to represent a local declaration. The operand is DECL_EXPR_DECL.  */
//DEFTREECODE (DECL_EXPR, "decl_expr", tcc_statement, 1)
class decl_expr : public tree_exp // tree_code == DECL_EXPR
{
public:
	static tree DeclExprCheck(tree);  // tree-check.h:137 (generated file)
public:
	tree DeclExprDecl();  // -- tree.h:1621
};

// -- tree.def:841
/* Exit the inner most loop conditionally.  Operand 0 is the condition.
   The type should be void and the value should be ignored.  */
//DEFTREECODE (EXIT_EXPR, "exit_expr", tcc_statement, 1)
class exit_expr : public tree_exp // tree_code = EXIT_EXPR
{
public:
	static tree ExitExprCheck(tree);  // tree-check.h:141
public:
	tree ExitExprCond(); // -- tree.h:1623
};

// -- tree.h:1625-1629  COMPOUND_LITERAL_EXPR accessors.
// -- tree.def:772
/* A COMPOUND_LITERAL_EXPR represents a literal that is placed in a DECL.  The
   COMPOUND_LITERAL_EXPR_DECL_EXPR is the a DECL_EXPR containing the decl
   for the anonymous object represented by the COMPOUND_LITERAL;
   the DECL_INITIAL of that decl is the CONSTRUCTOR that initializes
   the compound literal.  */
//DEFTREECODE (COMPOUND_LITERAL_EXPR, "compound_literal_expr", tcc_expression, 1)
class compound_literal_expr
{
public:
//	static public
public:
	tree CompoundLiteralExprDeclExpr();  // -- tree.h:1626
	tree CompoundLiteralExprDecl();  // -- tree.h:1628 P_1621
};

// -- tree.h:1631-1636  SWITCH_EXPR accessors.
// -- tree.def:860
/* Switch expression.

   TREE_TYPE is the original type of the condition, before any
   language required type conversions.  It may be NULL, in which case
   the original type and final types are assumed to be the same.

   Operand 0 is the expression used to perform the branch,
   Operand 1 is the body of the switch, which probably contains
     CASE_LABEL_EXPRs.  It may also be NULL, in which case operand 2
     must not be NULL.
   Operand 2 is either NULL_TREE or a TREE_VEC of the CASE_LABEL_EXPRs
     of all the cases.  */
//DEFTREECODE (SWITCH_EXPR, "switch_expr", tcc_statement, 3)
class switch_expr
{
public:
	tree SwitchCond(); // -- tree.h:1634
	tree SwitchBody(); // -- tree.h:1635
	tree SwitchLabels(); // -- tree.h:1636
};


// -- tree.def:866
/* Used to represent a case label. The operands are CASE_LOW and
   CASE_HIGH, respectively. If CASE_LOW is NULL_TREE, the label is a
   'default' label. If CASE_HIGH is NULL_TREE, the label is a normal case
   label.  CASE_LABEL is the corresponding LABEL_DECL.  */
//DEFTREECODE (CASE_LABEL_EXPR, "case_label_expr", tcc_statement, 3)
class case_label_expr
{
public: // -- tree.h:1638-1642  CASE_LABEL_EXPR accessors.
	tree CaseLow(); // -- tree.h:1640
	tree CaseHigh(); // -- tree.h:1641
	tree CaseLabel(); // -- tree.h:1642
public: // from tree_base
	/* Used as a temporary field on a CASE_LABEL_EXPR to indicate that the
	   CASE_LOW operand has been processed.  */
	bool CaseLowSeen();         // -- tree.h:1129 P_372 // tree_base
public:
	bool _IsDefaultLabel();
	bool _IsNormalCaseLabel();

};

// -- tree.def:961
/* Low-level memory addressing.  Operands are BASE (address of static or
   global variable or register), OFFSET (integer constant),
   INDEX (register), STEP (integer constant), INDEX2 (register),
   The corresponding address is BASE + STEP * INDEX + INDEX2 + OFFSET.
   Only variations and values valid on the target are allowed.

   The type of STEP, INDEX and INDEX2 is sizetype.

   The type of BASE is a pointer type.  If BASE is not an address of
   a static or global variable INDEX2 will be NULL.

   The type of OFFSET is a pointer type and determines TBAA the same as
   the constant offset operand in MEM_REF.  */
//DEFTREECODE (TARGET_MEM_REF, "target_mem_ref", tcc_reference, 5)
class target_mem_ref
{
public: // tree.h:1644-1650  The operands of a TARGET_MEM_REF.
	tree TmrBase();  // -- tree.h:1646
	tree TmrOffset(); // -- tree.h:1647
	tree TmrIndex();  // -- tree.h:1648
	tree TmrStep();   // -- tree.h:1649
	tree TmrIndex2(); // -- tree.h:1650
public:

};

// -- tree.def:521
/* Declare local variables, including making RTL and allocating space.
   BIND_EXPR_VARS is a chain of VAR_DECL nodes for the variables.
   BIND_EXPR_BODY is the body, the expression to be computed using
   the variables.  The value of operand 1 becomes that of the BIND_EXPR.
   BIND_EXPR_BLOCK is the BLOCK that corresponds to these bindings
   for debugging purposes.  If this BIND_EXPR is actually expanded,
   that sets the TREE_USED flag in the BLOCK.

   The BIND_EXPR is not responsible for informing parsers
   about these variables.  If the body is coming from the input file,
   then the code that creates the BIND_EXPR is also responsible for
   informing the parser of the variables.

   If the BIND_EXPR is ever expanded, its TREE_USED flag is set.
   This tells the code for debugging symbol tables not to ignore the BIND_EXPR.
   If the BIND_EXPR should be output for debugging but will not be expanded,
   set the TREE_USED flag by hand.

   In order for the BIND_EXPR to be known at all, the code that creates it
   must also install it as a subblock in the tree of BLOCK
   nodes for the function.  */
//DEFTREECODE (BIND_EXPR, "bind_expr", tcc_expression, 3)
class bind_expr
{
public: // tree.h:1652-1655  The operands of a BIND_EXPR.
	tree BindExprVars();  // -- tree.h:1653
	tree BindExprBody();  // -- tree.h:1654
	tree BindExprBlock(); // -- tree.h:1655
public:
	// container chain _GetLocalVariables();
	// _GetSurroundingBolock();
};

// -- tree.def:830
/* GOTO.  Operand 0 is a LABEL_DECL node or an expression.
   The type should be void and the value should be ignored.  */
//DEFTREECODE (GOTO_EXPR, "goto_expr", tcc_statement, 1)
class goto_expr
{
public: // tree.h:1657-1659  GOTO_EXPR accessor.
	tree GotoDestination(); // -- tree.h:1659

};

// -- tree.def:873
/* Used to represent an inline assembly statement.  ASM_STRING returns a
   STRING_CST for the instruction (e.g., "mov x, y"). ASM_OUTPUTS,
   ASM_INPUTS, and ASM_CLOBBERS represent the outputs, inputs, and clobbers
   for the statement.  ASM_LABELS, if present, indicates various destinations
   for the asm; labels cannot be combined with outputs.  */
//DEFTREECODE (ASM_EXPR, "asm_expr", tcc_statement, 5)
class asm_expr
{
public: // tree.h:1661-1673 ASM_EXPR accessors.
	tree AsmString();  // -- tree.h:1665
	tree AsmOutputs(); // -- tree.h:1666
	tree AsmInputs();  // -- tree.h:1667
	tree AsmClobbers(); // -- tree.h:1668
	tree AsmLabels();   // -- tree.h:1669
	bool AsmInputP();   // -- tree.h:1672
	bool AsmVolatileP(); // -- tree.h:1673
public:

};

// -- tree.def:486
/* Conditional expression ( ... ? ... : ...  in C).
   Operand 0 is the condition.
   Operand 1 is the then-value.
   Operand 2 is the else-value.
   Operand 0 may be of any type.
   Operand 1 must have the same type as the entire expression, unless
   it unconditionally throws an exception, in which case it should
   have VOID_TYPE.  The same constraints apply to operand 2.  The
   condition in operand 0 must be of integral type.

   In cfg gimple, if you do not have a selection expression, operands
   1 and 2 are NULL.  The operands are then taken from the cfg edges. */
//DEFTREECODE (COND_EXPR, "cond_expr", tcc_expression, 3)
class cond_expr
{
public: // tree.h:1675-1678 COND_EXPR accessors.
	tree CondExprCond(); // -- tree.h:1676
	tree CondExprThen(); // -- tree.h:1677
	tree CondExprElse(); // -- tree.h:1678
public:

};

// -- tree.def:900
/* Polynomial chains of recurrences.
   Under the form: cr = {CHREC_LEFT (cr), +, CHREC_RIGHT (cr)}.  */
//DEFTREECODE (POLYNOMIAL_CHREC, "polynomial_chrec", tcc_expression, 3)
class polynomial_chrec
{
public: // tree.h:1680-1684  Accessors for the chains of recurrences.
	tree ChrecVar(); // -- tree.h:1681
	tree ChrecLeft(); // -- tree.h:1682
	tree ChrecRight(); // -- tree.h:1683
	unsigned HOST_WIDE_INT ChrecVariable(); // -- tree.h:1684 P_1681
public:

};

// -- tree.def:826
/* A label definition, encapsulated as a statement.
   Operand 0 is the LABEL_DECL node for the label that appears here.
   The type should be void and the value should be ignored.  */
//DEFTREECODE (LABEL_EXPR, "label_expr", tcc_statement, 1)
class label_expr
{
public: // tree.h:1686-1688 LABEL_EXPR accessor.
	tree LabelExprLabel(); // -- tree.h:1688
public:

};

// -- tree.h:1690
/* VDEF_EXPR accessors are specified in tree-flow.h, along with the other
   accessors for SSA operands.  */

// -- tree.def:882
/* Used to represent a typed exception handler.  CATCH_TYPES is the type (or
   list of types) handled, and CATCH_BODY is the code for the handler.  */
//DEFTREECODE (CATCH_EXPR, "catch_expr", tcc_statement, 2)
class catch_expr
{
public: // tree.h:1693-1695  CATCH_EXPR accessors.
	tree CatchTypes(); // -- tree.h:1694
	tree CatchBody();  // -- tree.h:1695
public:

};

// -- tree.def:888
/* Used to represent an exception specification.  EH_FILTER_TYPES is a list
   of allowed types, and EH_FILTER_FAILURE is an expression to evaluate on
   failure.  EH_FILTER_MUST_NOT_THROW controls which range type to use when
   expanding.  */
//DEFTREECODE (EH_FILTER_EXPR, "eh_filter_expr", tcc_statement, 2)
class eh_filter_expr
{
public: // tree.h:1697-1699  EH_FILTER_EXPR accessors.
	tree EhFilterTypes();   // -- tree.h:1698
	tree EhFilterFailure(); // -- tree.h:1699
public:

};

// -- tree.def:430
/* Used to represent lookup in a virtual method table which is dependent on
   the runtime type of an object.  Operands are:
   OBJ_TYPE_REF_EXPR: An expression that evaluates the value to use.
   OBJ_TYPE_REF_OBJECT: Is the object on whose behalf the lookup is
   being performed.  Through this the optimizers may be able to statically
   determine the dynamic type of the object.
   OBJ_TYPE_REF_TOKEN: An integer index to the virtual method table.  */
//DEFTREECODE (OBJ_TYPE_REF, "obj_type_ref", tcc_expression, 3)
class obj_type_ref
{
public: // tree.h:1701-1704  OBJ_TYPE_REF accessors.
	tree ObjTypeRefExpr();   // -- tree.h:1702
	tree ObjTypeRefObject(); // -- tree.h:1703
	tree ObjTypeRefToken();  // -- tree.h:1704
public:

};

// -- tree.def:923
/* Predicate assertion.  Artificial expression generated by the optimizers
   to keep track of predicate values.  This expression may only appear on
   the RHS of assignments.

   Given X = ASSERT_EXPR <Y, EXPR>, the optimizers can infer
   two things:

   	1- X is a copy of Y.
	2- EXPR is a conditional expression and is known to be true.

   Valid and to be expected forms of conditional expressions are
   valid GIMPLE conditional expressions (as defined by is_gimple_condexpr)
   and conditional expressions with the first operand being a
   PLUS_EXPR with a variable possibly wrapped in a NOP_EXPR first
   operand and an integer constant second operand.

   The type of the expression is the same as Y.  */
//DEFTREECODE (ASSERT_EXPR, "assert_expr", tcc_expression, 2)
class assert_expr
{
public: // tree.h:1706-1708  ASSERT_EXPR accessors.
	tree AssertExprVar();  // -- tree.h:1707
	tree AssertExprCond(); // -- tree.h:1708
public:
};

//////////////////////////////////////////////////

// -- tree.def:529
/* Function call.  CALL_EXPRs are represented by variably-sized expression
   nodes.  There are at least three fixed operands.  Operand 0 is an
   INTEGER_CST node containing the total operand count, the number of
   arguments plus 3.  Operand 1 is the function, while operand 2 is
   is static chain argument, or NULL.  The remaining operands are the
   arguments to the call.  */
//DEFTREECODE (CALL_EXPR, "call_expr", tcc_vl_exp, 3)
class call_expr
{
public: // tree.h:1710-1724  CALL_EXPR accessors.
	tree CallExprFn(); // -- tree.h:1712
	tree CallExprStaticChain(); // -- tree.h:1713
	tree CallExprArg(); // -- tree.h:1714
	int CallExprNargs(); // -- tree.h:1715
	//??? tree* CallExprArgp(); // -- tree.h:1724

public: // from tree_base
	/* Set on a CALL_EXPR if the call is in a tail position, ie. just before the
	   exit of a function.  Calls for which this is true are candidates for tail
	   call optimizations.  */
	bool CallExprTailcall();    // -- tree.h:1124 P_372 //tree_base

};

// -- tree.h:1726-1855  //Ray: ignore, I guess it is less interested. -- 2012/3/28
/* OpenMP directive and clause accessors.  */

// -- tree.def:1155
/* PREDICT_EXPR.  Specify hint for branch prediction.  The
   PREDICT_EXPR_PREDICTOR specify predictor and PREDICT_EXPR_OUTCOME the
   outcome (0 for not taken and 1 for taken).  Once the profile is guessed
   all conditional branches leading to execution paths executing the
   PREDICT_EXPR will get predicted by the specified predictor.  */
//DEFTREECODE (PREDICT_EXPR, "predict_expr", tcc_expression, 1)
class predict_expr //requires PREDICT_EXPR_CHECK
{
public: // macro to member function map
	// enum prediction // -- predict.h:33
	Enum(prediction) PredictExprOutcome();       // -- tree.h:1132 P_372  // tree_base
	Enum(prediction) SetPredictExprOutcome(Enum(prediction)); // -- tree.h:1134 P_372 //tree_base
	Enum(br_predictor) PredictExprPredictor();   // -- tree.h:1136 P_??
};


}// end namespace plugin_cxx

#endif /* CXX_TREE_DEF_HXX_ */
