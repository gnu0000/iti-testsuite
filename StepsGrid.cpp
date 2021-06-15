// OptionsIOGrid.cpp : implementation file
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
#include "OptionsCommonGrid.h"
#include "StepsGrid.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CStepsGrid, COptionsCommonGrid)
	//{{AFX_MSG_MAP(CStepsGrid)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CStepsGrid

CStepsGrid::CStepsGrid()
	{
	memset(m_szEditedCellText, 0, sizeof(m_szEditedCellText));
	}

CStepsGrid::~CStepsGrid()
	{
	}


void CStepsGrid::LoadGridData ()
	{
	LoadGridData(m_iIndex);
	}


// type step  halt async 
static PSZ szDUMMY_DATA[] =
      {
      "Exec", "Prep.exe @Parmfile",          "Y", "N",
      "SQL" , "Delete from Proposal ...",    "Y", "N",
      "Xfer", "XTABDATA.DAT",                "Y", "N",
      "Copy", "@DataDir\\Result.dat @RunDir","Y", "N",
      "Exec", "Replay.exe",                  "N", "N",
      "Prop", "Name=Value",                  "N", "N", 
      NULL, NULL, NULL, NULL
      };

void CStepsGrid::LoadGridData (int iFormatIndex)
	{
	SetNumberRows(25);
   for (int i=0; szDUMMY_DATA[i*4]; i++)
      {
   	QuickSetText (0, i, szDUMMY_DATA[i*4  ]); 	
   	QuickSetText (1, i, szDUMMY_DATA[i*4+1]);
   	QuickSetText (2, i, szDUMMY_DATA[i*4+2]);
   	QuickSetText (3, i, szDUMMY_DATA[i*4+3]);
      }
   }


void CStepsGrid::OnSetup()
	{
	COptionsCommonGrid::OnSetup ();

	SetNumberCols(4);
	QuickSetText (0, -1, "Type");
	QuickSetText (1, -1, "Step");
	QuickSetText (2, -1, "Halt");
	QuickSetText (3, -1, "Async");
	SetColWidth (0, 15);
	SetColWidth (1, 61);
	SetColWidth (2, 12);
	SetColWidth (3, 12);
   FitToWindow (0, 3);
	LoadGridData ();
   FitToWindow (0, 3);
	RedrawAll();
	}


int CStepsGrid::OnCellTypeNotify(long ID,int col,long row,long msg,long param)
	{
	
	//if (msg == UGCT_DROPLISTSTART)
	//	{
//		CStringList *psl = (CStringList *)param;
//
//		for (PSZ* ppsz = szIO_FIELDS; *ppsz; ppsz++)
//			psl->AddTail (*ppsz);
//
//		GetStr (col, row, m_szEditedCellText);	// save what text is before change
//		}
//	if (msg == UGCT_DROPLISTSELECT)
//		{
//		PSZ	 psz;
//		CString *str = (CString *)param;
//		BOOL bChanged = str->Compare(m_szEditedCellText);
//
//		if (psz = str->GetBuffer(64))
//			{
//			int iID = FieldNameToID (psz);
//			str->ReleaseBuffer();
//			int iSize = DefaultFieldSize (iID);
//			psz = CUtil::NumStr (iSize);
//			}
//
//		// Has the row changed ? ---
//		// The field might be the same, but not the length ---
//		if (!bChanged)
//			{
//			GetStr (1, row, m_szEditedCellText);	// save what text is before change
//			bChanged = strcmp(psz, m_szEditedCellText);
//			}
//
//		if (bChanged)
//			{
//			QuickSetText (1, row, psz);
//
//			// Page has been modified ---
//			CPropertyPage *pWnd = (CPropertyPage *)GetParent();
//			pWnd->SetModified (TRUE);
//			::SendMessage(GetParent()->m_hWnd, WM_USER_IOGRID_CELL_CHANGED, 0, 0);
//			}
//		RedrawRow (row);
//		}
	return 1;
	}


void CStepsGrid::InsertRow ()
	{
	int iRow = GetCurrentRow ();
	COptionsCommonGrid::InsertRow ();
//	QuickSetCellType   (0, iRow, UGCT_DROPLIST);
//	QuickSetCellTypeEx (0, iRow, UGCT_DROPLISTHIDEBUTTON);
	}


void CStepsGrid::SaveData () // from dlg to memory
	{
//	char szField[128];
//	char szSize[128];
//
//	PIOINFO piom = GetIOInfo ();
//
//	for (int i=0, j=0; i< GetNumberRows() && j<MAXIOCOLS; i++)
//		{
//		GetStr (0, i, szField);
//		GetStr (1, i, szSize);
//		if (*szField && *szSize)
//			{
//			piom->m_iFields[m_iIndex][j] 	 = FieldNameToID (szField);
//			piom->m_iFieldSizes[m_iIndex][j] = atoi(szSize);
//			j++;
//			}
//		}
//	piom->m_iFields[m_iIndex][j] 	 = 0;
//	piom->m_iFieldSizes[m_iIndex][j] = 0;
	}



int CStepsGrid::OnEditStart (int col, long row,CWnd **edit)
	{
	COptionsCommonGrid::OnEditStart(col, row, edit);

	GetStr (col, row, m_szEditedCellText);	// save what text is before change

	return 1;
	}

int CStepsGrid::OnEditFinish (int col, long row, CWnd *edit, CString& string, BOOL cancelFlag)
	{
	if (cancelFlag || (!string.Compare(m_szEditedCellText)))
		return TRUE;

	COptionsCommonGrid::OnEditFinish(col, row, edit, string, cancelFlag);

	::SendMessage(GetParent()->m_hWnd, WM_USER_IOGRID_CELL_CHANGED, 0, 0);
	return 1;
	}


void CStepsGrid::SetGridData(CStepsGrid& srcGrid)
   {
   }


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

