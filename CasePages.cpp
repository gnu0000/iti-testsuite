// CasePage1.cpp : implementation file
//

#include "stdafx.h"
#include "TestSuite.h"
#include "CasePages.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCasePage1 property page

IMPLEMENT_DYNCREATE(CCasePage1, CPropertyPage)

BEGIN_MESSAGE_MAP(CCasePage1, CPropertyPage)
	//{{AFX_MSG_MAP(CCasePage1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CCasePage1::CCasePage1() : CPropertyPage(CCasePage1::IDD)
   {
	//{{AFX_DATA_INIT(CCasePage1)
	//}}AFX_DATA_INIT
   }

CCasePage1::~CCasePage1()
   {
   }

void CCasePage1::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCasePage1)
	//}}AFX_DATA_MAP
   }


/////////////////////////////////////////////////////////////////////////////
// CCasePage2 property page

IMPLEMENT_DYNCREATE(CCasePage2, CPropertyPage)

BEGIN_MESSAGE_MAP(CCasePage2, CPropertyPage)
	//{{AFX_MSG_MAP(CCasePage2)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CCasePage2::CCasePage2() : CPropertyPage(CCasePage2::IDD)
   {
	//{{AFX_DATA_INIT(CCasePage2)
	//}}AFX_DATA_INIT
   }

CCasePage2::~CCasePage2()
   {
   }

void CCasePage2::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCasePage2)
	//}}AFX_DATA_MAP
   }


BOOL CCasePage2::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}
void CCasePage2::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage2::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage2::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage2::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}

/////////////////////////////////////////////////////////////////////////////
// CCasePage3 property page

IMPLEMENT_DYNCREATE(CCasePage3, CPropertyPage)

BEGIN_MESSAGE_MAP(CCasePage3, CPropertyPage)
	//{{AFX_MSG_MAP(CCasePage3)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
   ON_LBN_SELCHANGE(IDC_LIST1,OnGridRowChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CCasePage3::CCasePage3() : CPropertyPage(CCasePage3::IDD)
   {
	//{{AFX_DATA_INIT(CCasePage3)
	//}}AFX_DATA_INIT
   }

CCasePage3::~CCasePage3()
   {
   }

void CCasePage3::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCasePage3)
	//}}AFX_DATA_MAP
   }


BOOL CCasePage3::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}
void CCasePage3::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage3::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage3::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage3::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage3::OnGridRowChange ()
   {
   int iRow = m_cGridCtl.GetCurrentRow();
   GetDlgItem (IDC_COMBO1)->SetWindowText (m_cGridCtl.QuickGetText (0, iRow));
   GetDlgItem (IDC_EDIT1 )->SetWindowText (m_cGridCtl.QuickGetText (1, iRow));
   PSZ psz = (PSZ)m_cGridCtl.QuickGetText (2, iRow);
   ((CButton*)GetDlgItem (IDC_CHECK2))->SetCheck (psz ? psz[0] == 'Y' : FALSE);
   }

/////////////////////////////////////////////////////////////////////////////
// CCasePage4 property page

IMPLEMENT_DYNCREATE(CCasePage4, CPropertyPage)

BEGIN_MESSAGE_MAP(CCasePage4, CPropertyPage)
	//{{AFX_MSG_MAP(CCasePage4)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CCasePage4::CCasePage4() : CPropertyPage(CCasePage4::IDD)
   {
	//{{AFX_DATA_INIT(CCasePage4)
	//}}AFX_DATA_INIT
   }

CCasePage4::~CCasePage4()
   {
   }

void CCasePage4::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCasePage4)
	//}}AFX_DATA_MAP
   }

BOOL CCasePage4::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}
void CCasePage4::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage4::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage4::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage4::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}

/////////////////////////////////////////////////////////////////////////////
// CCasePage5 property page

IMPLEMENT_DYNCREATE(CCasePage5, CPropertyPage)

BEGIN_MESSAGE_MAP(CCasePage5, CPropertyPage)
	//{{AFX_MSG_MAP(CCasePage5)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CCasePage5::CCasePage5() : CPropertyPage(CCasePage5::IDD)
   {
	//{{AFX_DATA_INIT(CCasePage5)
	//}}AFX_DATA_INIT
   }

CCasePage5::~CCasePage5()
   {
   }

void CCasePage5::DoDataExchange(CDataExchange* pDX)
   {
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCasePage5)
	//}}AFX_DATA_MAP
   }


BOOL CCasePage5::OnInitDialog() 
	{
	CPropertyPage::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);
	return FALSE;
	}
void CCasePage5::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage5::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage5::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
void CCasePage5::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	SetModified (TRUE);
	}
