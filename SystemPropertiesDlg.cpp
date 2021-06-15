// SystemPropertiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testsuite.h"
#include "SystemPropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSystemPropertiesDlg dialog


BEGIN_MESSAGE_MAP(CSystemPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CSystemPropertiesDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CSystemPropertiesDlg::CSystemPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemPropertiesDlg::IDD, pParent)
   {
	//{{AFX_DATA_INIT(CSystemPropertiesDlg)
	//}}AFX_DATA_INIT
   }

void CSystemPropertiesDlg::DoDataExchange(CDataExchange* pDX)
   {
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSystemPropertiesDlg)
	//}}AFX_DATA_MAP
   }



static PSZ szDUMMY_DATA[] =
      {
      "DBConfig"   , "\\PLC\\Config\\DBConnect.cfg",
      "ScriptDir"  , ".\\Scripts",
      "DataDir"    , ".\\Data",
      "RunDir"     , ".\\Run",
      "ResultDir"  , ".\\Results",
      "LogLevel"   , "4",
      "ErrLevel"   , "3",
      "DisplayMode", "1",
      "DebugMode"  , "FALSE",
      "Database"  , "TESTDB1",
      "DBServer"  , "dbsrv1.infotechfl.com",
      "OtherData" , "..\\ExtraData",
      "LDLogLevel", "@LogLevel",
      NULL, NULL
      };



BOOL CSystemPropertiesDlg::OnInitDialog() 
	{
	CDialog::OnInitDialog();
	m_cGridCtl.AttachGrid (this, IDC_LIST1);

   for (int i=0; szDUMMY_DATA[i*2]; i++)
      {
   	m_cGridCtl.QuickSetText (0, i, szDUMMY_DATA[i*2  ]); 	
   	m_cGridCtl.QuickSetText (1, i, szDUMMY_DATA[i*2+1]);
      }

	return FALSE;
	}
void CSystemPropertiesDlg::OnUp() 
	{
	m_cGridCtl.RowUp();
	m_cGridCtl.SetFocus ();
	}
void CSystemPropertiesDlg::OnDown() 
	{
	m_cGridCtl.RowDown ();
	m_cGridCtl.SetFocus ();
	}
void CSystemPropertiesDlg::OnAdd() 
	{
	m_cGridCtl.InsertRow ();
	m_cGridCtl.SetFocus ();
	}
void CSystemPropertiesDlg::OnDelete() 
	{
	m_cGridCtl.DeleteRow();
	m_cGridCtl.SetFocus ();
	}


