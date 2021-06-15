#if !defined(AFX_COMPONENTSHEET_H__3420C0C7_C741_486F_9AF9_D16F4B287AF2__INCLUDED_)
#define AFX_COMPONENTSHEET_H__3420C0C7_C741_486F_9AF9_D16F4B287AF2__INCLUDED_
#pragma once

#include "ComponentPages.h"

/////////////////////////////////////////////////////////////////////////////
// CComponentSheet

class CComponentSheet : public CPropertySheet
	{
	DECLARE_DYNAMIC(CComponentSheet)

public:
	CComponentPage1 cComponentPage1; 
	CComponentPage2 cComponentPage2; 
//	CComponentPage3 cComponentPage3; 
	CComponentPage4 cComponentPage4; 


	CComponentSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CComponentSheet();

	//{{AFX_VIRTUAL(CComponentSheet)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CComponentSheet)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPONENTSHEET_H__3420C0C7_C741_486F_9AF9_D16F4B287AF2__INCLUDED_)
