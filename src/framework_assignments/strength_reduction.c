/**
 * @file
 *
 * This file contains the code for the StrengthReduction traversal.
 * The traversal has the uid: SR
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "ccngen/enum.h"
#include "palm/str.h"
#include "palm/memory.h"

node_st *SRbinop(node_st *node)
{
    TRAVleft(node);
    TRAVright(node);
    node_st *var_1 = NULL;
    node_st *var_2 = NULL;

    if (BINOP_TYPE(node) == BO_mul) {
        int num_1 = 4;
        char *s_1 = NULL;

        if ((NODE_TYPE( BINOP_RIGHT(node)) == NT_NUM)
        && (NUM_VAL(BINOP_RIGHT(node)) <= 3)
        && (NODE_TYPE( BINOP_LEFT(node)) == NT_VAR)) {
            num_1 = NUM_VAL(BINOP_RIGHT(node));
            s_1 = VAR_NAME(BINOP_LEFT(node));
        } else if ((NODE_TYPE( BINOP_LEFT(node)) == NT_NUM)
        && (NUM_VAL(BINOP_LEFT(node)) <= 3)
        && (NODE_TYPE( BINOP_RIGHT(node)) == NT_VAR)) {
            num_1 = NUM_VAL(BINOP_LEFT(node));
            s_1 = VAR_NAME(BINOP_RIGHT(node));

        }

        switch (num_1)
        {
        case 0:
            node = ASTnum(0);
            break;
        case 1:
            node = ASTvar(s_1);
            break;
        case 2:
            BINOP_LEFT(node) = ASTvar(s_1);
            BINOP_RIGHT(node) = ASTvar(s_1);
            BINOP_TYPE(node) = BO_add;
            break;
        case 3:
            var_1 = ASTvar(s_1);
            var_2 = ASTvar(s_1);
            BINOP_TYPE(node) = BO_add;
            BINOP_LEFT(node) = ASTvar(s_1);
            BINOP_RIGHT(node) = ASTbinop(var_1, var_2, BO_add);
            break;
        default:
            break;
        }

    }

    return node;
}
