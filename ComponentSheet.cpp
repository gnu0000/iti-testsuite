// ComponentSheet.cpp : implementation file
//

#include "stdafx.h"
#include "TestSuite.h"
#include "ComponentSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComponentSheet

IMPLEMENT_DYNAMIC(CComponentSheet, CPropertySheet)

BEGIN_MESSAGE_MAP(CComponentSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CComponentSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComponentSheet::CComponentSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage) 
 : CPropertySheet(pszCaption, pParentWnd, iSelectPage)
   {
   AddPage (&cComponentPage1);
   AddPage (&cComponentPage2);
//   AddPage (&cComponentPage3);
   AddPage (&cComponentPage4);
   }

CComponentSheet::~CComponentSheet()
   {
   }

/////////////////////////////////////////////////////////////////////////////
// CComponentSheet message handlers
