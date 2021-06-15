#if !defined(AFX_SCRIPTPAGE1_H__686E6711_A467_4E31_974A_F6C1D18B06C7__INCLUDED_)
#define AFX_SCRIPTPAGE1_H__686E6711_A467_4E31_974A_F6C1D18B06C7__INCLUDED_
#pragma once

#include "OptionsIOGrid.h"
#include "StepsGrid.h"

/////////////////////////////////////////////////////////////////////////////
// CScriptPage1 dialog

class CScriptPage1 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CScriptPage1)

public:
	COptionsIOGrid m_cGridCtl;

	CScriptPage1();
	~CScriptPage1();

	//{{AFX_DATA(CScriptPage1)
	enum { IDD = IDD_PROPPAGE_SCRIPT1 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CScriptPage1)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CScriptPage1)
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};


/////////////////////////////////////////////////////////////////////////////
// CScriptPage2 dialog

class CScriptPage2 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CScriptPage2)

public:
	CStepsGrid m_cGridCtl;

	CScriptPage2();
	~CScriptPage2();

	//{{AFX_DATA(CScriptPage2)
	enum { IDD = IDD_PROPPAGE_SCRIPT2 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CScriptPage2)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CScriptPage2)
	virtual BOOL OnInitDialog();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnGridRowChange ();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

/////////////////////////////////////////////////////////////////////////////
// CScriptPage3 dialog

class CScriptPage3 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CScriptPage3)

public:
	CScriptPage3();
	~CScriptPage3();

	//{{AFX_DATA(CScriptPage3)
	enum { IDD = IDD_PROPPAGE_SCRIPT3 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CScriptPage3)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CScriptPage3)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

/////////////////////////////////////////////////////////////////////////////
// CScriptPage4 dialog

class CScriptPage4 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CScriptPage4)

public:
	CStepsGrid m_cGridCtl;

	CScriptPage4();
	~CScriptPage4();

	//{{AFX_DATA(CScriptPage4)
	enum { IDD = IDD_PROPPAGE_SCRIPT4 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CScriptPage4)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CScriptPage4)
	virtual BOOL OnInitDialog();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnGridRowChange ();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

/////////////////////////////////////////////////////////////////////////////
// CScriptPage5 dialog

class CScriptPage5 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CScriptPage5)

public:
	CScriptPage5();
	~CScriptPage5();

	//{{AFX_DATA(CScriptPage5)
	enum { IDD = IDD_PROPPAGE_SCRIPT5 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CScriptPage5)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CScriptPage5)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

//{{AFX_INSERT_LOCATION}}



#endif // !defined(AFX_SCRIPTPAGE1_H__686E6711_A467_4E31_974A_F6C1D18B06C7__INCLUDED_)
