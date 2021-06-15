// OptionsCommonGrid.cpp : implementation file
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

#include "stdafx.h"
//#include "ugctrl.h"
//#include "GnuStr.h"
#include "OptionsCommonGrid.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(COptionsCommonGrid, CUGCtrl)
	//{{AFX_MSG_MAP(COptionsCommonGrid)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// COptionsCommonGrid

COptionsCommonGrid::COptionsCommonGrid()
	{
	m_bAllowEdit = TRUE;

	//CUGCtrl::CUGCtrl();  do i do this??
	}

COptionsCommonGrid::~COptionsCommonGrid()
	{
	}


void COptionsCommonGrid::OnSetup()
	{
	CUGCtrl::OnSetup ();

	int iFont = AddFont (_T("MS Sans Serif"), 12, FW_MEDIUM);
	SetDefFont(iFont) ;
	SetMultiSelectMode(TRUE);
	SetUniformRowHeight (TRUE);
	SetSH_Width (20);
	SetDefRowHeight(16);

	SetVScrollMode (UG_SCROLLTRACKING);
	SetHScrollMode (UG_SCROLLTRACKING);
//	SetMultiSelectMode(TRUE);
	SetMultiSelectMode(FALSE); // what was I thinking?
	SetHS_Height(0);
	}

void COptionsCommonGrid::OnSH_LClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed)
	{
	ClearSelections(); 
	int iCol = GetCurrentCol ();
	SelectRange(0,row,GetNumberCols()-1,row);
	GotoCell (iCol, row);
	}


void COptionsCommonGrid::OnDClicked(int col, long row, RECT *rect, POINT *point, int processed)
	{
	if (m_bAllowEdit)
		StartEdit ();
	}

void COptionsCommonGrid::OnCharDown(UINT *vcKey,BOOL processed)
	{
	if (m_bAllowEdit)
		StartEdit(*vcKey);
	}

int  COptionsCommonGrid::OnEditStart(int col, long row, CWnd **edit)
	{
	return TRUE;
	}

int COptionsCommonGrid::OnEditFinish(int col, long row,CWnd* edit,CString& string,BOOL cancelFlag)
	{
	if (cancelFlag)
		return TRUE;
		
	CPropertyPage *pWnd = (CPropertyPage *)GetParent();
	pWnd->SetModified (TRUE);
	return TRUE;
	}


void COptionsCommonGrid::InsertRow ()
	{
	int iRow = GetCurrentRow ();
	CUGCtrl::InsertRow (iRow);
	GotoCell (0, iRow);
	}

void COptionsCommonGrid::DeleteRow ()
	{
	int iRow = GetCurrentRow ();
	int iCol = GetCurrentCol ();
	CUGCtrl::DeleteRow (GetCurrentRow ());
	GotoCell (iCol, iRow);
	}

void COptionsCommonGrid::SwapRow (int i1, int i2)
	{
	CUGCell cell1, cell2;

	for (int i=0; i < GetNumberCols (); i++)
		{
		GetCell (i, i1, &cell1);
		GetCell (i, i2, &cell2);
		SetCell (i, i1, &cell2);
		SetCell (i, i2, &cell1);
		}
	RedrawRow (i1);
	RedrawRow (i2);
	}


void COptionsCommonGrid::RowUp ()
	{
	int iRow = GetCurrentRow ();
	int iCol = GetCurrentCol ();

	if (iRow)
		{
		SwapRow (iRow, iRow-1);
		GotoCell (iCol, iRow-1);
		}
	}

void COptionsCommonGrid::RowDown ()
	{
	int iRow = GetCurrentRow ();
	int iCol = GetCurrentCol ();

	if (iRow < GetNumberRows ()-1)
		{
		SwapRow (iRow, iRow+1);
		GotoCell (iCol, iRow+1);
		}
	}


PSZ COptionsCommonGrid::GetStr (int iCol, int iRow, PSZ psz)
	{
	CString cs;

	QuickGetText (iCol, iRow, &cs);
	strcpy (psz, cs.GetBuffer(256));
//	return StrStrip (StrClip (psz, " \t"), " \t");
   return psz;
	}


/////////////////////////////////////////////////////////////////////////////
// COptionsCommonGrid message handlers

void COptionsCommonGrid::OnSize(UINT nType, int cx, int cy) 
	{
	CUGCtrl::OnSize(nType, cx, cy);

   FitToWindow (0, GetNumberCols()-1);

	// TODO: Add your message handler code here	
	}


void COptionsCommonGrid::OnRowChange(long oldrow,long newrow)
   {
   int i=0;
   int iID = GetWindowLong (m_hWnd, GWL_ID);

   CWnd* pParent = GetParent ();
//   pParent->PostMessage (WM_COMMAND, MAKEWPARAM (iID, LVN_ITEMCHANGED), (LPARAM)(this->m_hWnd));
   pParent->PostMessage (WM_COMMAND, MAKEWPARAM (iID, LBN_SELCHANGE), (LPARAM)(this->m_hWnd));
   }
