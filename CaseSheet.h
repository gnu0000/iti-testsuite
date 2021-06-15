#if !defined(AFX_CASESHEET_H__3420C0C7_C741_486F_9AF9_D16F4B287AF2__INCLUDED_)
#define AFX_CASESHEET_H__3420C0C7_C741_486F_9AF9_D16F4B287AF2__INCLUDED_
#pragma once

#include "CasePages.h"

/////////////////////////////////////////////////////////////////////////////
// CCaseSheet

class CCaseSheet : public CPropertySheet
	{
	DECLARE_DYNAMIC(CCaseSheet)

public:
	CCasePage1 cCasePage1; 
	CCasePage2 cCasePage2; 
	CCasePage3 cCasePage3; 
	CCasePage4 cCasePage4; 
	CCasePage5 cCasePage5; 


	CCaseSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CCaseSheet();

	//{{AFX_VIRTUAL(CCaseSheet)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CCaseSheet)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASESHEET_H__3420C0C7_C741_486F_9AF9_D16F4B287AF2__INCLUDED_)
