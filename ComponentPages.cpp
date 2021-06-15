// ComponentPage1.cpp : implementation file
//

#include "stdafx.h"
#include "TestSuite.h"
#include "ComponentPages.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComponentPage1 property page

IMPLEMENT_DYNCREATE(CComponentPage1, CPropertyPage)

BEGIN_MESSAGE_MAP(CComponentPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CComponentPage1)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComponentPage1::CComponentPage1() : CPropertyPage(CComponentPage1::IDD)
   {
	//{{AFX_DATA_INIT(CComponentPage1)
	//}}AFX_DATA_INIT
   }

CComponentPage1::~CComponentPage1()
   {
   }

void CComponentPage1::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComponentPage1)
	//}}AFX_DATA_MAP
   }


BOOL CComponentPage1::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}


void CComponentPage1::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}

void CComponentPage1::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}

void CComponentPage1::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}

void CComponentPage1::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}


/////////////////////////////////////////////////////////////////////////////
// CComponentPage2 property page

IMPLEMENT_DYNCREATE(CComponentPage2, CPropertyPage)

BEGIN_MESSAGE_MAP(CComponentPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CComponentPage2)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
   ON_LBN_SELCHANGE(IDC_LIST1,OnGridRowChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComponentPage2::CComponentPage2() : CPropertyPage(CComponentPage2::IDD)
   {
	//{{AFX_DATA_INIT(CComponentPage2)
	//}}AFX_DATA_INIT
   }

CComponentPage2::~CComponentPage2()
   {
   }

void CComponentPage2::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComponentPage2)
	//}}AFX_DATA_MAP
   }


BOOL CComponentPage2::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}
void CComponentPage2::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage2::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage2::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage2::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage2::OnGridRowChange ()
   {
   int iRow = m_cGridCtl.GetCurrentRow();
   GetDlgItem (IDC_COMBO1)->SetWindowText (m_cGridCtl.QuickGetText (0, iRow));
   GetDlgItem (IDC_EDIT1 )->SetWindowText (m_cGridCtl.QuickGetText (1, iRow));
   PSZ psz = (PSZ)m_cGridCtl.QuickGetText (2, iRow);
   ((CButton*)GetDlgItem (IDC_CHECK2))->SetCheck (psz ? psz[0] == 'Y' : FALSE);
   }

/////////////////////////////////////////////////////////////////////////////
// CComponentPage3 property page

IMPLEMENT_DYNCREATE(CComponentPage3, CPropertyPage)

BEGIN_MESSAGE_MAP(CComponentPage3, CPropertyPage)
	//{{AFX_MSG_MAP(CComponentPage3)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComponentPage3::CComponentPage3() : CPropertyPage(CComponentPage3::IDD)
   {
	//{{AFX_DATA_INIT(CComponentPage3)
	//}}AFX_DATA_INIT
   }

CComponentPage3::~CComponentPage3()
   {
   }

void CComponentPage3::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComponentPage3)
	//}}AFX_DATA_MAP
   }

BOOL CComponentPage3::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}
void CComponentPage3::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage3::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage3::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage3::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}


/////////////////////////////////////////////////////////////////////////////
// CComponentPage4 property page

IMPLEMENT_DYNCREATE(CComponentPage4, CPropertyPage)

BEGIN_MESSAGE_MAP(CComponentPage4, CPropertyPage)
	//{{AFX_MSG_MAP(CComponentPage4)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
   ON_LBN_SELCHANGE(IDC_LIST1,OnGridRowChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CComponentPage4::CComponentPage4() : CPropertyPage(CComponentPage4::IDD)
   {
	//{{AFX_DATA_INIT(CComponentPage4)
	//}}AFX_DATA_INIT
   }

CComponentPage4::~CComponentPage4()
   {
   }

void CComponentPage4::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComponentPage4)
	//}}AFX_DATA_MAP
   }


BOOL CComponentPage4::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}
void CComponentPage4::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage4::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage4::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage4::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CComponentPage4::OnGridRowChange ()
   {
   int iRow = m_cGridCtl.GetCurrentRow();
   GetDlgItem (IDC_COMBO1)->SetWindowText (m_cGridCtl.QuickGetText (0, iRow));
   GetDlgItem (IDC_EDIT1 )->SetWindowText (m_cGridCtl.QuickGetText (1, iRow));
   PSZ psz = (PSZ)m_cGridCtl.QuickGetText (2, iRow);
   ((CButton*)GetDlgItem (IDC_CHECK2))->SetCheck (psz ? psz[0] == 'Y' : FALSE);
   }
