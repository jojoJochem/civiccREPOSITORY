/**
 * @file
 *
 * This file contains the code for the OccIndentiefiers traversal.
 * The traversal has the uid: OI
 *
 *
 */

#include <stdio.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav_data.h"
#include "palm/hash_table.h"

void OIinit() { return; }
void OIfini() { return; }

static bool first_stmts = false;
static bool ht_created = false;
htable_st *ht_new = NULL;


/**
 * @fn OIstmts
 */
node_st *OIstmts(node_st *node)
{
    TRAVchildren(node);
    if (!first_stmts) {
        first_stmts = true;
        printf("Sum of identifiertypes: %d\n", HTelementCount(ht_new));
        HTdelete(ht_new);
    }
    return node;
}


/**
 * @fn OIvar
 */
node_st *OIvar(node_st *node)
{
    if (ht_created == false){
        ht_created = true;
        ht_new = HTnew_String(500);
    }

    int count = 1;

    if (HTlookup(ht_new, VAR_NAME(node)) != NULL){
        count = HTremove(ht_new, VAR_NAME(node));
        count +=1;
        HTinsert(ht_new, VAR_NAME(node), count);
    }else{
        HTinsert(ht_new, VAR_NAME(node), count);
    }
    printf("Identifier: %s occurance: %d\n", VAR_NAME(node), count);


    return node;
}