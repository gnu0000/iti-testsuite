#if !defined(AFX_SCRIPTSHEET_H__3420C0C7_C741_486F_9AF9_D16F4B287AF2__INCLUDED_)
#define AFX_SCRIPTSHEET_H__3420C0C7_C741_486F_9AF9_D16F4B287AF2__INCLUDED_
#pragma once

#include "ScriptPages.h"

/////////////////////////////////////////////////////////////////////////////
// CScriptSheet

class CScriptSheet : public CPropertySheet
	{
	DECLARE_DYNAMIC(CScriptSheet)

public:
	CScriptPage1 cScriptPage1; 
	CScriptPage2 cScriptPage2; 
//	CScriptPage3 cScriptPage3; 
	CScriptPage4 cScriptPage4; 
	CScriptPage5 cScriptPage5; 


	CScriptSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CScriptSheet();

	//{{AFX_VIRTUAL(CScriptSheet)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CScriptSheet)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPTSHEET_H__3420C0C7_C741_486F_9AF9_D16F4B287AF2__INCLUDED_)
