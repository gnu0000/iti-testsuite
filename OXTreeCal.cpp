// ==========================================================================
//						COXTreeCal
// ==========================================================================

// Copyright © Dundas Software Ltd. 1997 - 1998, All Rights Reserved
                         
// //////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OXTreeCal.h"
#include "OXTreeCtrl.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


COXTreeCal::COXTreeCal():COXCalendar()
{
}

COXTreeCal::~COXTreeCal()
{
}


BEGIN_MESSAGE_MAP(COXTreeCal, COXCalendar)
	ON_WM_KILLFOCUS()
	ON_EN_KILLFOCUS(COXCalendar::IDEDIT, OnKillFocusEdit)
END_MESSAGE_MAP()



void COXTreeCal::Init(HTREEITEM hItem,int iItem,int iSubItem)
{
	m_iItem= iItem;
	m_iSubItem = iSubItem;
	COXTreeCtrl *pTreeCtrl = (COXTreeCtrl*) GetParent();
	CStringArray& sa = pTreeCtrl->GetItemTextEx(hItem,iSubItem);
	m_wndEdit.SetWindowText(pTreeCtrl->GetItemText(hItem,iSubItem));
	if(sa.GetSize() == 0)
		return;
	COleDateTime dtStart(0,0,0,0,0,0);
	COleDateTime dtEnd(9999,12,31,0,0,0);
	if(sa.GetSize() > 0)
	{
		CString sFirstDate = sa[0];
		dtStart.ParseDateTime(sFirstDate);
	}
	if(sa.GetSize() > 1)
	{
		CString sEndDate = sa[1];
		dtEnd.ParseDateTime(sEndDate);
	}
	SetDateRange(dtStart,dtEnd);
}


void COXTreeCal::OnKillFocus(CWnd* pNewWnd) 
{
	COXCalendar::OnKillFocus(pNewWnd);
	if(pNewWnd)
	{
		if(pNewWnd->GetSafeHwnd() != m_wndEdit.GetSafeHwnd()
			&& pNewWnd->GetSafeHwnd() != m_wndDatePicker.GetSafeHwnd())
		{
			CString str;
			m_wndEdit.GetWindowText(str);
			// Send Notification to parent 
			LV_DISPINFO di;
			di.hdr.hwndFrom = GetParent()->m_hWnd;
			di.hdr.idFrom = GetDlgCtrlID();
			di.hdr.code = LVN_ENDLABELEDIT;
			di.item.mask = LVIF_TEXT;
			di.item.iItem = m_iItem;
			di.item.iSubItem = m_iSubItem;
			di.item.pszText = LPTSTR((LPCTSTR)str);
			di.item.cchTextMax = str.GetLength();
			GetParent()->GetParent()->SendMessage( WM_NOTIFY, GetParent()->GetDlgCtrlID(), (LPARAM)&di );
			// and close window too
			DestroyWindow();
		}
	}
}


BOOL COXTreeCal::Create(DWORD dwStyle,const CRect&r ,CWnd * pParentWnd,UINT nID)
{
	return COXCalendar::Create(dwStyle,r,pParentWnd,nID);// initialization
}

void COXTreeCal::OnKillFocusEdit()
{
	COleDateTime dt = GetCurrentDate();
	COXCalendar::OnKillFocusEdit();
	CWnd *pFocusWnd = GetFocus();
	HWND hFocus = pFocusWnd->GetSafeHwnd();
	if( hFocus != GetSafeHwnd() &&
		hFocus != m_wndDatePicker.GetSafeHwnd())
			FinishEdit(dt.GetStatus() == 0);

}

void COXTreeCal::PostNcDestroy()
{
	COXCalendar::PostNcDestroy();
}

BOOL COXTreeCal::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message == WM_KEYDOWN )
	{
		if(pMsg->wParam == VK_RETURN && pMsg->hwnd == m_wndEdit.GetSafeHwnd())
		{
			COXCalendar::OnKillFocusEdit();
			::TranslateMessage(pMsg);
			::DispatchMessage(pMsg);
			FinishEdit(TRUE);
			return TRUE;
		}
		else if(pMsg->wParam == VK_ESCAPE)
		{
			::TranslateMessage(pMsg);
			::DispatchMessage(pMsg);
			FinishEdit(FALSE);
			return TRUE;
		}
	}

	return COXCalendar::PreTranslateMessage(pMsg);
}

void COXTreeCal::FinishEdit(BOOL bOK)
{
	CString str;
	m_wndEdit.GetWindowText(str);
	// Send Notification to parent 
	LV_DISPINFO di;
	di.hdr.hwndFrom = GetParent()->m_hWnd;
	di.hdr.idFrom = GetDlgCtrlID();
	di.hdr.code = LVN_ENDLABELEDIT;
	di.item.mask = LVIF_TEXT;
	di.item.iItem = bOK ? m_iItem : -1;
	di.item.iSubItem = m_iSubItem;
	di.item.pszText = LPTSTR((LPCTSTR)str);
	di.item.cchTextMax = str.GetLength();
	GetParent()->GetParent()->SendMessage( WM_NOTIFY, GetParent()->GetDlgCtrlID(), 
		(LPARAM)&di );
	// and close window too
	DestroyWindow();
}
