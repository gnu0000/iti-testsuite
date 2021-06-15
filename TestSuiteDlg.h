// TestSuiteDlg.h : header file
//

#if !defined(AFX_TESTSUITEDLG_H__56DA36A1_592F_4E88_97A8_2CEE90D2EA35__INCLUDED_)
#define AFX_TESTSUITEDLG_H__56DA36A1_592F_4E88_97A8_2CEE90D2EA35__INCLUDED_
#pragma once

#include "ScriptTree.h"

/////////////////////////////////////////////////////////////////////////////
// CTestSuiteDlg dialog

class CTestSuiteDlg : public CDynaDialog
	{
public:
	CScriptTree	m_cTreeCtl;
	CImageList 	m_cCheckBoxImages;
	CImageList 	m_cStatusImages;

	CTestSuiteDlg(CWnd* pParent = NULL);	// standard constructor

   void InitTree ();
	HTREEITEM AddElement (HTREEITEM hParentItem, CString strText, BOOL bHasKids, int iStatus);

   //{{AFX_DATA(CTestSuiteDlg)
	enum { IDD = IDD_TESTSUITE_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CTestSuiteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	HICON m_hIcon;

	//{{AFX_MSG(CTestSuiteDlg)
	virtual BOOL OnInitDialog();
  	afx_msg void OnItemExpandingTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnOptionsParameters();
	afx_msg void OnInitMenu(CMenu* pMenu);
	afx_msg void OnScriptProperties();
	afx_msg void OnComponentProperties();
	afx_msg void OnCaseProperties();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};



//{{AFX_INSERT_LOCATION}}
#endif // !defined(AFX_TESTSUITEDLG_H__56DA36A1_592F_4E88_97A8_2CEE90D2EA35__INCLUDED_)
