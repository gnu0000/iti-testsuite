// CaseSheet.cpp : implementation file
//

#include "stdafx.h"
#include "TestSuite.h"
#include "CaseSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCaseSheet

IMPLEMENT_DYNAMIC(CCaseSheet, CPropertySheet)

BEGIN_MESSAGE_MAP(CCaseSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CCaseSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CCaseSheet::CCaseSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage) 
 : CPropertySheet(pszCaption, pParentWnd, iSelectPage)
   {
   AddPage (&cCasePage1);
   AddPage (&cCasePage5);
//   AddPage (&cCasePage2);
   AddPage (&cCasePage3);
//   AddPage (&cCasePage4);
   }

CCaseSheet::~CCaseSheet()
   {
   }

/////////////////////////////////////////////////////////////////////////////
// CCaseSheet message handlers
