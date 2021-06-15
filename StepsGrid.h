#if !defined(AFX_STEPSGRID_H__64D6CE45_F3F2_11D2_8A7F_00105A21C878__INCLUDED_)
#define AFX_STEPSGRID_H__64D6CE45_F3F2_11D2_8A7F_00105A21C878__INCLUDED_
#pragma once


// StepsGrid.h : header file
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

#include "OptionsCommonGrid.h"

// ----------------------- CONSTANTS --------------------------------

#define WM_USER_IOGRID_CELL_CHANGED		WM_USER + 5
#define MAX_IOCELL_TEXT_LENGTH			128



/////////////////////////////////////////////////////////////////////////////
// CStepsGrid window

class CStepsGrid : public COptionsCommonGrid
	{
// Construction
public:
	CStepsGrid();
	~CStepsGrid();

// Attributes
public:
	int  m_iIndex;
	char m_szEditedCellText[MAX_IOCELL_TEXT_LENGTH];		// text of the cell being edited

// Operations
public:
	void OnSetup();
	void LoadGridData ();
	void LoadGridData (int iFormatIndex);
	int  OnCellTypeNotify(long ID,int col,long row,long msg,long param);
	void SaveData ();
	void InsertRow ();
	void SetGridData (CStepsGrid& srcGrid);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStepsGrid)
	virtual int OnEditStart (int col, long row,CWnd **edit);
	virtual int OnEditFinish (int col, long row, CWnd *edit, CString& string, BOOL cancelFlag);
	//}}AFX_VIRTUAL


	// Generated message map functions
protected:
	//{{AFX_MSG(CStepsGrid)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSIOGRID_H__64D6CE45_F3F2_11D2_8A7F_00105A21C878__INCLUDED_)
