/**
 * @file
 *
 * This file contains the code for the SumOperators traversal.
 * The traversal has the uid: SO
 *
 *
 */

#include <stdio.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"

void SOinit() { return; }
void SOfini() { return; }

static bool first_stmts = false;
static bool first_module = false;


/**
 * @fn SOstmts
 */
node_st *SOstmts(node_st *node)
{
    TRAVchildren(node);
    if (!first_stmts) {
        first_stmts = true;
        struct data_so *data = DATA_SO_GET();
        printf("Sum of arithmetic operators: %d\n", data->sum);
    }
    return node;
}


/**
 * @fn SObinop
 */
node_st *SObinop(node_st *node)
{
    if (BINOP_TYPE(node) == BO_add
    || BINOP_TYPE(node) == BO_sub
    || BINOP_TYPE(node) == BO_mul
    || BINOP_TYPE(node) == BO_div
    || BINOP_TYPE(node) == BO_mod){
        struct data_so *data = DATA_SO_GET();
        data->sum += 1;
    }
    return node;
}

/**
 * @fn SObmodule
 */
node_st *SOmodule(node_st *node)
{
    TRAVchildren(node);
    if (!first_module) {
        first_module = true;
        struct data_so *data = DATA_SO_GET();
        MODULE_VAL(node) = data->sum;
    }
    return node;
}


