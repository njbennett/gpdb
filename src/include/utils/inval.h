/*-------------------------------------------------------------------------
 *
 * inval.h
 *	  POSTGRES cache invalidation dispatcher definitions.
 *
 *
 * Portions Copyright (c) 1996-2001, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $Id: inval.h,v 1.25 2002/04/29 22:14:34 tgl Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef INVAL_H
#define INVAL_H

#include "access/htup.h"


typedef void (*CacheCallbackFunction) (Datum arg, Oid relid);


extern void AcceptInvalidationMessages(void);

extern void AtEOXactInvalidationMessages(bool isCommit);

extern void CommandEndInvalidationMessages(bool isCommit);

extern void CacheInvalidateHeapTuple(Relation relation, HeapTuple tuple);

extern void CacheInvalidateRelcache(Oid relationId);

extern void CacheRegisterSyscacheCallback(int cacheid,
										  CacheCallbackFunction func,
										  Datum arg);

extern void CacheRegisterRelcacheCallback(CacheCallbackFunction func,
										  Datum arg);

#endif   /* INVAL_H */
