// ScriptPage1.cpp : implementation file
//

#include "stdafx.h"
#include "TestSuite.h"
#include "ScriptPages.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptPage1 property page

IMPLEMENT_DYNCREATE(CScriptPage1, CPropertyPage)

BEGIN_MESSAGE_MAP(CScriptPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CScriptPage1)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CScriptPage1::CScriptPage1() : CPropertyPage(CScriptPage1::IDD)
   {
	//{{AFX_DATA_INIT(CScriptPage1)
	//}}AFX_DATA_INIT
   }

CScriptPage1::~CScriptPage1()
   {
   }

void CScriptPage1::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScriptPage1)
	//}}AFX_DATA_MAP
   }

BOOL CScriptPage1::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}


void CScriptPage1::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}

void CScriptPage1::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}

void CScriptPage1::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}

void CScriptPage1::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}


/////////////////////////////////////////////////////////////////////////////
// CScriptPage2 property page

IMPLEMENT_DYNCREATE(CScriptPage2, CPropertyPage)

BEGIN_MESSAGE_MAP(CScriptPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CScriptPage2)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
   ON_LBN_SELCHANGE(IDC_LIST1,OnGridRowChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CScriptPage2::CScriptPage2() : CPropertyPage(CScriptPage2::IDD)
   {
	//{{AFX_DATA_INIT(CScriptPage2)
	//}}AFX_DATA_INIT
   }

CScriptPage2::~CScriptPage2()
   {
   }

void CScriptPage2::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScriptPage2)
	//}}AFX_DATA_MAP
   }


BOOL CScriptPage2::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}
void CScriptPage2::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CScriptPage2::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CScriptPage2::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CScriptPage2::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}

void CScriptPage2::OnGridRowChange ()
   {
   int iRow = m_cGridCtl.GetCurrentRow();
   GetDlgItem (IDC_COMBO1)->SetWindowText (m_cGridCtl.QuickGetText (0, iRow));
   GetDlgItem (IDC_EDIT1 )->SetWindowText (m_cGridCtl.QuickGetText (1, iRow));
   PSZ psz = (PSZ)m_cGridCtl.QuickGetText (2, iRow);
   ((CButton*)GetDlgItem (IDC_CHECK2))->SetCheck (psz ? psz[0] == 'Y' : FALSE);
   }


/////////////////////////////////////////////////////////////////////////////
// CScriptPage3 property page

IMPLEMENT_DYNCREATE(CScriptPage3, CPropertyPage)

BEGIN_MESSAGE_MAP(CScriptPage3, CPropertyPage)
	//{{AFX_MSG_MAP(CScriptPage3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CScriptPage3::CScriptPage3() : CPropertyPage(CScriptPage3::IDD)
   {
	//{{AFX_DATA_INIT(CScriptPage3)
	//}}AFX_DATA_INIT
   }

CScriptPage3::~CScriptPage3()
   {
   }

void CScriptPage3::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScriptPage3)
	//}}AFX_DATA_MAP
   }



/////////////////////////////////////////////////////////////////////////////
// CScriptPage4 property page

IMPLEMENT_DYNCREATE(CScriptPage4, CPropertyPage)

BEGIN_MESSAGE_MAP(CScriptPage4, CPropertyPage)
	//{{AFX_MSG_MAP(CScriptPage4)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
   ON_LBN_SELCHANGE(IDC_LIST1,OnGridRowChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CScriptPage4::CScriptPage4() : CPropertyPage(CScriptPage4::IDD)
   {
	//{{AFX_DATA_INIT(CScriptPage4)
	//}}AFX_DATA_INIT
   }

CScriptPage4::~CScriptPage4()
   {
   }

void CScriptPage4::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScriptPage4)
	//}}AFX_DATA_MAP
   }

BOOL CScriptPage4::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}
void CScriptPage4::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CScriptPage4::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CScriptPage4::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CScriptPage4::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CScriptPage4::OnGridRowChange ()
   {
   int iRow = m_cGridCtl.GetCurrentRow();
   GetDlgItem (IDC_COMBO1)->SetWindowText (m_cGridCtl.QuickGetText (0, iRow));
   GetDlgItem (IDC_EDIT1 )->SetWindowText (m_cGridCtl.QuickGetText (1, iRow));
   PSZ psz = (PSZ)m_cGridCtl.QuickGetText (2, iRow);
   ((CButton*)GetDlgItem (IDC_CHECK2))->SetCheck (psz ? psz[0] == 'Y' : FALSE);
   }

/////////////////////////////////////////////////////////////////////////////
// CScriptPage5 property page

IMPLEMENT_DYNCREATE(CScriptPage5, CPropertyPage)

BEGIN_MESSAGE_MAP(CScriptPage5, CPropertyPage)
	//{{AFX_MSG_MAP(CScriptPage5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CScriptPage5::CScriptPage5() : CPropertyPage(CScriptPage5::IDD)
   {
	//{{AFX_DATA_INIT(CScriptPage5)
	//}}AFX_DATA_INIT
   }

CScriptPage5::~CScriptPage5()
   {
   }

void CScriptPage5::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScriptPage5)
	//}}AFX_DATA_MAP
   }

