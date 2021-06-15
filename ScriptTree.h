#if !defined(AFX_SCRIPTTREE_H__04CB1830_F1B4_4B76_A431_FB4FE001F43A__INCLUDED_)
#define AFX_SCRIPTTREE_H__04CB1830_F1B4_4B76_A431_FB4FE001F43A__INCLUDED_

#pragma once

#include "OXTreeCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CScriptTree window

class CScriptTree : public COXTreeCtrl
	{
public:
	CScriptTree();
	virtual ~CScriptTree();

	int GetSelectionLevel ();


	//{{AFX_VIRTUAL(CScriptTree)
	//}}AFX_VIRTUAL

public:
	//{{AFX_MSG(CScriptTree)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnScriptProperties();
	afx_msg void OnComponentProperties();
	afx_msg void OnCaseProperties();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
#endif // !defined(AFX_SCRIPTTREE_H__04CB1830_F1B4_4B76_A431_FB4FE001F43A__INCLUDED_)
