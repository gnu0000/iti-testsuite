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
//#include "ugctrl.h"
#include "OptionsCommonGrid.h"
#include "OptionsIOGrid.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(COptionsIOGrid, COptionsCommonGrid)
	//{{AFX_MSG_MAP(COptionsIOGrid)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// COptionsIOGrid

COptionsIOGrid::COptionsIOGrid()
	{
	memset(m_szEditedCellText, 0, sizeof(m_szEditedCellText));
	}

COptionsIOGrid::~COptionsIOGrid()
	{
	}


void COptionsIOGrid::LoadGridData ()
	{
	LoadGridData(m_iIndex);
	}

static PSZ szDUMMY_DATA[] =
      {
      "Database"  , "TESTDB1",
      "DBServer"  , "dbsrv1.infotechfl.com",
      "ErrorLevel", "3",
      "LogLevel"  , "4",
      "PrintMode" , "1",
      "OtherData" , "..\\ExtraData",
      NULL, NULL
      };

void COptionsIOGrid::LoadGridData (int iFormatIndex)
	{
	SetNumberRows(25);
   for (int i=0; szDUMMY_DATA[i*2]; i++)
      {
   	QuickSetText (0, i, szDUMMY_DATA[i*2  ]); 	
   	QuickSetText (1, i, szDUMMY_DATA[i*2+1]);
      }
   }


//	PIOINFO piom = GetIOInfo ();
//	if (!piom)
//		return;
//	
//	int i, iRows = 25;
//	for (i=0; piom->m_iFields[iFormatIndex][i]; i++)
//		;
//
//	iRows = max (i, 25);
//	SetNumberRows(iRows);
//
//	for (i=0; piom->m_iFields[iFormatIndex][i]; i++)
//		{
//		QuickSetText (0, i, szIO_FIELDS[piom->m_iFields[iFormatIndex][i]]);
//		QuickSetText (1, i, CUtil::NumStr (piom->m_iFieldSizes[iFormatIndex][i]));
//		}
//	for (; i<iRows; i++)
//		{
//		QuickSetText (0, i, "");
//		QuickSetText (1, i, "");
//		}
//	for (i=0; i<iRows; i++)
//		{
//		QuickSetCellType   (0, i, UGCT_DROPLIST);
//		QuickSetCellTypeEx (0, i, UGCT_DROPLISTHIDEBUTTON);
//		}
//	}


void COptionsIOGrid::OnSetup()
	{
	COptionsCommonGrid::OnSetup ();

	SetNumberCols(2);
	QuickSetText (0, -1, "Property");
	QuickSetText (1, -1, "Value");

	SetColWidth (0, 40);
	SetColWidth (1, 60);
   FitToWindow (0, 1);
	LoadGridData ();
   FitToWindow (0, 1);
	RedrawAll();
	}


int COptionsIOGrid::OnCellTypeNotify(long ID,int col,long row,long msg,long param)
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


void COptionsIOGrid::InsertRow ()
	{
	int iRow = GetCurrentRow ();
	COptionsCommonGrid::InsertRow ();
//	QuickSetCellType   (0, iRow, UGCT_DROPLIST);
//	QuickSetCellTypeEx (0, iRow, UGCT_DROPLISTHIDEBUTTON);
	}


void COptionsIOGrid::SaveData () // from dlg to memory
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



int COptionsIOGrid::OnEditStart (int col, long row,CWnd **edit)
	{
	COptionsCommonGrid::OnEditStart(col, row, edit);

	GetStr (col, row, m_szEditedCellText);	// save what text is before change

	return 1;
	}

int COptionsIOGrid::OnEditFinish (int col, long row, CWnd *edit, CString& string, BOOL cancelFlag)
	{
	if (cancelFlag || (!string.Compare(m_szEditedCellText)))
		return TRUE;

	COptionsCommonGrid::OnEditFinish(col, row, edit, string, cancelFlag);

	::SendMessage(GetParent()->m_hWnd, WM_USER_IOGRID_CELL_CHANGED, 0, 0);
	return 1;
	}


void COptionsIOGrid::SetGridData(COptionsIOGrid& srcGrid)
   {
   }


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

