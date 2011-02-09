/*-------------------------------------------------------------------------
 *
 * extension.h
 *		Extension management commands (create/drop extension).
 *
 *
 * Portions Copyright (c) 1996-2011, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/commands/extension.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef EXTENSION_H
#define EXTENSION_H

#include "nodes/parsenodes.h"


/*
 * creating_extension is only true while running a CREATE EXTENSION command.
 * It instructs recordDependencyOnCurrentExtension() to register a dependency
 * on the current pg_extension object for each SQL object created by its
 * installation script.
 */
extern bool creating_extension;
extern Oid CurrentExtensionObject;


extern void CreateExtension(CreateExtensionStmt *stmt);

extern void RemoveExtensions(DropStmt *stmt);
extern void RemoveExtensionById(Oid extId);

extern Oid	get_extension_oid(const char *extname, bool missing_ok);
extern char *get_extension_name(Oid ext_oid);

extern void AlterExtensionNamespace(List *names, const char *newschema);

#endif   /* EXTENSION_H */
