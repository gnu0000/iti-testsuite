// TestSuite.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TestSuite.h"
#include "TestSuiteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestSuiteApp

BEGIN_MESSAGE_MAP(CTestSuiteApp, CWinApp)
	//{{AFX_MSG_MAP(CTestSuiteApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestSuiteApp construction

CTestSuiteApp::CTestSuiteApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTestSuiteApp object

CTestSuiteApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTestSuiteApp initialization

BOOL CTestSuiteApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CTestSuiteDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
