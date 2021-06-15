// ScriptTree.cpp : implementation file
//

#include "stdafx.h"
#include "TestSuite.h"
#include "ScriptTree.h"
#include "ScriptSheet.h"
#include "ComponentSheet.h"
#include "CaseSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptTree

BEGIN_MESSAGE_MAP(CScriptTree, COXTreeCtrl)
	//{{AFX_MSG_MAP(CScriptTree)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDC_SCRIPT_PROPERTIES, OnScriptProperties)
	ON_COMMAND(IDC_COMPONENT_PROPERTIES, OnComponentProperties)
	ON_COMMAND(IDC_CASE_PROPERTIES, OnCaseProperties)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CScriptTree::CScriptTree()
   {
   }

CScriptTree::~CScriptTree()
   {
   }

/////////////////////////////////////////////////////////////////////////////
// CScriptTree message handlers

void CScriptTree::OnLButtonDown(UINT nFlags, CPoint point) 
   {
	COXTreeCtrl::OnLButtonDown(nFlags, point);

	UINT iHTFlags;
	int idx = HitTest (point, &iHTFlags);
	HTREEITEM hItem = GetItemFromIndex(idx);

   if (!hItem)
   	return;

	TV_ITEM tvi;
	memset(&tvi,0,sizeof(tvi));
	tvi.hItem = hItem;
	tvi.mask= TVIF_HANDLE | TVIF_STATE;
	tvi.stateMask = TVIS_STATEIMAGEMASK;
   GetItem (&tvi);
   int iState = tvi.state>>12;

	COXTreeItem *xti=GetXItem(hItem);
   int iIndent = GetItemIndent(xti);
   int iDelta = point.x - iIndent;
   if (iDelta > 0 && iDelta < 13)
      {
   	tvi.mask = TVIF_HANDLE | TVIF_STATE;
   	tvi.stateMask = TVIS_STATEIMAGEMASK;
      tvi.state = INDEXTOSTATEIMAGEMASK(iState == 2 ? 1 : 2);
      SetItem (&tvi);
      }
   }

int CScriptTree::GetSelectionLevel () 
   {
	HTREEITEM hItem = GetSelectedItem();
	COXTreeItem *xti=GetXItem(hItem);
   if (xti)
      return xti->GetItemLevel();
   return 0;
   }

void CScriptTree::OnRButtonDown(UINT nFlags, CPoint point) 
   {
	COXTreeCtrl::OnRButtonDown(nFlags, point);

	UINT iHTFlags;
	int idx = HitTest (point, &iHTFlags);
	HTREEITEM hItem = GetItemFromIndex(idx);

   if (!hItem)
   	return;
	COXTreeItem *xti=GetXItem(hItem);
   int iLevel = xti->GetItemLevel();  // GetItemIndent(xti);

	CMenu	cPopupList;
   cPopupList.LoadMenu (IDR_POPUP_EDIT);

	CMenu* pcPopup = cPopupList.GetSubMenu (iLevel-1);
   CPoint cp = point;
   ClientToScreen(&cp);
	pcPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, cp.x, cp.y, this);
   }

void CScriptTree::OnScriptProperties() 
   {
   CScriptSheet cScriptSheet ("Script Properties");

   cScriptSheet.DoModal ();
   }

void CScriptTree::OnComponentProperties() 
   {
   CComponentSheet cComponentSheet ("Component Properties");

   cComponentSheet.DoModal ();
   }

void CScriptTree::OnCaseProperties() 
   {
   CCaseSheet cCaseSheet ("Test Case Properties");

   cCaseSheet.DoModal ();
}

void CScriptTree::OnSize(UINT nType, int cx, int cy) 
   {
	COXTreeCtrl::OnSize(nType, cx, cy);
   }
