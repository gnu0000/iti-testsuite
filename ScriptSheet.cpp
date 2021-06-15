// ScriptSheet.cpp : implementation file
//

#include "stdafx.h"
#include "TestSuite.h"
#include "ScriptSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptSheet

IMPLEMENT_DYNAMIC(CScriptSheet, CPropertySheet)

BEGIN_MESSAGE_MAP(CScriptSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CScriptSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CScriptSheet::CScriptSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage) 
 : CPropertySheet(pszCaption, pParentWnd, iSelectPage)
   {
   AddPage (&cScriptPage1);
   AddPage (&cScriptPage5);
   AddPage (&cScriptPage2);
//   AddPage (&cScriptPage3);
   AddPage (&cScriptPage4);
   }

CScriptSheet::~CScriptSheet()
   {
   }

/////////////////////////////////////////////////////////////////////////////
// CScriptSheet message handlers
