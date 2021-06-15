#if !defined(AFX_CASEPAGE1_H__686E6711_A467_4E31_974A_F6C1D18B06C7__INCLUDED_)
#define AFX_CASEPAGE1_H__686E6711_A467_4E31_974A_F6C1D18B06C7__INCLUDED_
#pragma once

#include "OptionsIOGrid.h"
#include "StepsGrid.h"

/////////////////////////////////////////////////////////////////////////////
// CCasePage1 dialog

class CCasePage1 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CCasePage1)

public:
	CCasePage1();
	~CCasePage1();

	//{{AFX_DATA(CCasePage2)
	enum { IDD = IDD_PROPPAGE_CASE1 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCasePage1)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CCasePage1)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};


/////////////////////////////////////////////////////////////////////////////
// CCasePage2 dialog

class CCasePage2 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CCasePage2)

public:
	CStepsGrid m_cGridCtl;

	CCasePage2();
	~CCasePage2();

	//{{AFX_DATA(CCasePage2)
	enum { IDD = IDD_PROPPAGE_CASE2 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCasePage2)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CCasePage2)
	virtual BOOL OnInitDialog();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

/////////////////////////////////////////////////////////////////////////////
// CCasePage3 dialog

class CCasePage3 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CCasePage3)

public:
	CStepsGrid m_cGridCtl;

	CCasePage3();
	~CCasePage3();

	//{{AFX_DATA(CCasePage3)
	enum { IDD = IDD_PROPPAGE_CASE3 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCasePage3)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CCasePage3)
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
// CCasePage4 dialog

class CCasePage4 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CCasePage4)

public:
	CStepsGrid m_cGridCtl;

	CCasePage4();
	~CCasePage4();

	//{{AFX_DATA(CCasePage4)
	enum { IDD = IDD_PROPPAGE_CASE4 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCasePage4)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CCasePage4)
	virtual BOOL OnInitDialog();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};


/////////////////////////////////////////////////////////////////////////////
// CCasePage5 dialog

class CCasePage5 : public CPropertyPage
	{
	DECLARE_DYNCREATE(CCasePage5)

public:
	COptionsIOGrid m_cGridCtl;

	CCasePage5();
	~CCasePage5();

	//{{AFX_DATA(CCasePage5)
	enum { IDD = IDD_PROPPAGE_CASE5 };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CCasePage5)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CCasePage5)
	virtual BOOL OnInitDialog();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};


//{{AFX_INSERT_LOCATION}}



#endif // !defined(AFX_CASEPAGE1_H__686E6711_A467_4E31_974A_F6C1D18B06C7__INCLUDED_)
