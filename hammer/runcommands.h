//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//

#ifndef _RUNCOMMANDS_H
#define _RUNCOMMANDS_H

#include <afxtempl.h>

//
// RunCommands functions
//

enum
{
	CCChangeDir = 0x100,
	CCCopyFile,
	CCDelFile,
	CCRenameFile
};

class KeyValues;

struct CCOMMAND
{
    BOOL bEnable;
    int iSpecialCmd;
    char szRun[MAX_PATH];
    char szParms[MAX_PATH];
    BOOL bLongFilenames;
    BOOL bEnsureCheck;
    char szEnsureFn[MAX_PATH];
    BOOL bUseProcessWnd;
    BOOL bNoWait;

    void Save(KeyValues* pKv) const;
    void Load(KeyValues* pKv);
};

// Déclaration correcte du typedef pointeur
typedef CCOMMAND* PCCOMMAND;


// list of commands:
typedef CArray<CCOMMAND, CCOMMAND&> CCommandArray;

// run a list of commands:
bool RunCommands(CCommandArray& Commands, LPCTSTR pszDocName);
void FixGameVars(char *pszSrc, char *pszDst, BOOL bUseQuotes = TRUE);
bool IsRunningCommands();

#endif // _RUNCOMMANDS_H
