#if !defined(AFX_OPTIONSCOMMONGRID_H__64D6CE45_F3F2_11D2_8A7F_00105A21C878__INCLUDED_)
#define AFX_OPTIONSCOMMONGRID_H__64D6CE45_F3F2_11D2_8A7F_00105A21C878__INCLUDED_
#pragma once

// OptionsCommonGrid.h : header file
//
//-----------------------------------------------------------------------
//         Copyright (c) 1999 by AASHTO.  All Rights Reserved.
// 
// This program module is part of EBS, the Electronic Bidding System, a 
// proprietary product of AASHTO, no part of which may be reproduced or 
// transmitted in any form or by any means, electronic, mechanical, or 
// otherwise, including photocopying and recording or in connection with 
// any information storage or retrieval system, without permission in 
// writing from AASHTO. 
//-----------------------------------------------------------------------
//
//Craig Fitzgerald
//
//

/////////////////////////////////////////////////////////////////////////////
// COptionsCommonGrid window

#include "ugctrl.h"

class COptionsCommonGrid : public CUGCtrl
{
// Construction
public:
	COptionsCommonGrid();
	~COptionsCommonGrid();

// Attributes
public:
	BOOL m_bAllowEdit;

// Operations
public:
	void OnSetup();
	void OnSH_LClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed=0);
	void OnDClicked (int col, long row, RECT *rect, POINT *point, int processed);
	void OnCharDown (UINT *vcKey,BOOL processed);
	int  OnEditStart (int col, long row,CWnd **edit);

	int  OnEditFinish (int col, long row, CWnd* edit, CString& string, BOOL cancelFlag);
//	int  OnEditFinish (int col, long row, CWnd* edit, LPCTSTR  string, BOOL cancelFlag);

	int  OnCanSizeCol(int col) {return 0;};
	int  OnCanSizeRow(long row){return 0;};
	int  OnCanSizeTopHdg()		{return 0;};
	int  OnCanSizeSideHdg()		{return 0;};

	void SwapRow (int i1, int i2);
	PSZ COptionsCommonGrid::GetStr (int iCol, int iRow, PSZ psz);
	void InsertRow ();
	void DeleteRow ();
	void RowUp ();
	void RowDown ();

	virtual void OnRowChange(long oldrow,long newrow);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionsCommonGrid)
	//}}AFX_VIRTUAL


	// Generated message map functions
protected:
	//{{AFX_MSG(COptionsCommonGrid)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSCOMMONGRID_H__64D6CE45_F3F2_11D2_8A7F_00105A21C878__INCLUDED_)
