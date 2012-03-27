/*
 * cxx-tree-def.hxx
 *
 *  Evey class find/mapped from [plug-inc]/tree.def but not in [plug-inc]/tree.h
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

//////////////////////////////////////////////////
// in tree.h:1572- macro order

class vl_exp : public tree_exp //satisfy VL_EXP_CHECK // -- tree.h:955
{
public:
	static tree VlExpCheck(tree);  // -- tree.h:955
public:
	/* In a tcc_vl_exp node, operand 0 is an INT_CST node holding the operand
	   length.  Its value includes the length operand itself; that is,
	   the minimum valid length is 1.*/
	int VlExpOperandLength();  // -- tree.h:1588
};

class loop_expr : public tree_exp  // base.code ==  LOOP_EXPR
{
public:
	tree LoopExprBody();  // -- tree.h:1595 P_1863 // tree_exp
};

//////////////////////////////////////////////////

// -- tree.def:529  // Function call.
//DEFTREECODE (CALL_EXPR, "call_expr", tcc_vl_exp, 3)
class call_expr : public tree_exp  //requires
{
public: // macro to member function map
	/* Set on a CALL_EXPR if the call is in a tail position, ie. just before the
	   exit of a function.  Calls for which this is true are candidates for tail
	   call optimizations.  */
	bool CallExprTailcall();    // -- tree.h:1124 P_372 //tree_base

};

// -- tree.def:866
//DEFTREECODE (CASE_LABEL_EXPR, "case_label_expr", tcc_statement, 3)
class case_label_expr : public tree_exp	//requires CASE_LABEL_EXPR_CHECK
{
public: // macro to member function map
	/* Used as a temporary field on a CASE_LABEL_EXPR to indicate that the
	   CASE_LOW operand has been processed.  */
	bool CaseLowSeen();         // -- tree.h:1129 P_372 // tree_base
};

// -- tree.def:1155
//DEFTREECODE (PREDICT_EXPR, "predict_expr", tcc_expression, 1)
class predict_expr : public tree_exp //requires PREDICT_EXPR_CHECK
{
public: // macro to member function map
	// enum prediction // -- predict.h:33
	Enum(prediction) PredictExprOutcome();       // -- tree.h:1132 P_372  // tree_base
	Enum(prediction) SetPredictExprOutcome(Enum(prediction)); // -- tree.h:1134 P_372 //tree_base
	Enum(br_predictor) PredictExprPredictor();   // -- tree.h:1136 P_??
};


}// end namespace plugin_cxx

#endif /* CXX_TREE_DEF_HXX_ */
