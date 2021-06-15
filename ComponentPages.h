#if !defined(AFX_COMPONENTPAGE1_H__686E6711_A467_4E31_974A_F6C1D18B06C7__INCLUDED_)
#define AFX_COMPONENTPAGE1_H__686E6711_A467_4E31_974A_F6C1D18B06C7__INCLUDED_
#pragma once

#include "OptionsIOGrid.h"
#include "StepsGrid.h"

/////////////////////////////////////////////////////////////////////////////
// CComponentPage1 dialog

class CComponentPage1 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CComponentPage1)

public:
	COptionsIOGrid m_cGridCtl;

	CComponentPage1();
	~CComponentPage1();

	//{{AFX_DATA(CComponentPage2)
	enum { IDD = IDD_PROPPAGE_COMPONENT1 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CComponentPage1)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CComponentPage1)
	virtual BOOL OnInitDialog();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};


/////////////////////////////////////////////////////////////////////////////
// CComponentPage2 dialog

class CComponentPage2 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CComponentPage2)

public:
	CStepsGrid m_cGridCtl;

	CComponentPage2();
	~CComponentPage2();

	//{{AFX_DATA(CComponentPage2)
	enum { IDD = IDD_PROPPAGE_COMPONENT2 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CComponentPage2)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CComponentPage2)
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
// CComponentPage3 dialog

class CComponentPage3 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CComponentPage3)

public:
	CStepsGrid m_cGridCtl;

	CComponentPage3();
	~CComponentPage3();

	//{{AFX_DATA(CComponentPage3)
	enum { IDD = IDD_PROPPAGE_COMPONENT3 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CComponentPage3)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CComponentPage3)
	virtual BOOL OnInitDialog();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

/////////////////////////////////////////////////////////////////////////////
// CComponentPage4 dialog

class CComponentPage4 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CComponentPage4)

public:
	CStepsGrid m_cGridCtl;

	CComponentPage4();
	~CComponentPage4();

	//{{AFX_DATA(CComponentPage4)
	enum { IDD = IDD_PROPPAGE_COMPONENT4 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CComponentPage4)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CComponentPage4)
	virtual BOOL OnInitDialog();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnGridRowChange ();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

//{{AFX_INSERT_LOCATION}}



#endif // !defined(AFX_COMPONENTPAGE1_H__686E6711_A467_4E31_974A_F6C1D18B06C7__INCLUDED_)
