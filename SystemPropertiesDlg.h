#if !defined(AFX_SYSTEMPROPERTIESDLG_H__D978DD6F_C4F1_41B9_83DB_2E1BD688D24D__INCLUDED_)
#define AFX_SYSTEMPROPERTIESDLG_H__D978DD6F_C4F1_41B9_83DB_2E1BD688D24D__INCLUDED_
#pragma once

#include "OptionsIOGrid.h"
#include "StepsGrid.h"

/////////////////////////////////////////////////////////////////////////////
// CSystemPropertiesDlg dialog

class CSystemPropertiesDlg : public CDialog
	{
public:
	COptionsIOGrid m_cGridCtl;

	CSystemPropertiesDlg(CWnd* pParent = NULL);   // standard constructor

	//{{AFX_DATA(CSystemPropertiesDlg)
	enum { IDD = IDD_SYS_PROPERTIES };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CSystemPropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CSystemPropertiesDlg)
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

//{{AFX_INSERT_LOCATION}}

#endif // !defined(AFX_SYSTEMPROPERTIESDLG_H__D978DD6F_C4F1_41B9_83DB_2E1BD688D24D__INCLUDED_)
