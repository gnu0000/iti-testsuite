// TestSuiteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestSuite.h"
#include "TestSuiteDlg.h"
#include "ScriptSheet.h"
#include "SystemPropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestSuiteDlg dialog

BEGIN_MESSAGE_MAP(CTestSuiteDlg, CDynaDialog)
	//{{AFX_MSG_MAP(CTestSuiteDlg)
  	ON_NOTIFY(TVN_ITEMEXPANDING, IDC_LIST1, OnItemExpandingTree1)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_OPTIONS_PARAMETERS, OnOptionsParameters)
	ON_WM_INITMENU()
	ON_COMMAND(IDC_SCRIPT_PROPERTIES, OnScriptProperties)
	ON_COMMAND(IDC_COMPONENT_PROPERTIES, OnComponentProperties)
	ON_COMMAND(IDC_CASE_PROPERTIES, OnCaseProperties)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CTestSuiteDlg::CTestSuiteDlg(CWnd* pParent /*=NULL*/): CDynaDialog(CTestSuiteDlg::IDD, pParent)
   {
	//{{AFX_DATA_INIT(CTestSuiteDlg)
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	UseResizingControls(TRUE, IDC_MR, IDC_SR, IDC_MB, IDC_SB);
   }

void CTestSuiteDlg::DoDataExchange(CDataExchange* pDX)
   {
	CDynaDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestSuiteDlg)
	DDX_Control(pDX, IDC_LIST1, m_cTreeCtl);
	//}}AFX_DATA_MAP
   }

BOOL CTestSuiteDlg::OnInitDialog()
   {
	CDynaDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_cCheckBoxImages.Create(IDB_CHECKBOX,13,1,RGB(255,255,255));
	m_cStatusImages.Create(IDB_STATUS,16,3,RGB(255,255,255));

   InitTree ();

   CRect cRect;
   GetWindowRect (cRect);
   MoveWindow (cRect.left, cRect.top, 500, 300);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
   }

char* szTestArray[] =
   {"Script: General Export test",     "1",
    "Script: General Import test",     "1",
    "Script: Pass to LAS",             "2",
    "Script: General PESGPPS test",    "2",
    "Script: General LASGBTE",         "1",
    "Script: General LASXTAB",         "1",
    "Script: Configuration Test",      "3",
    "Script: Multiple Jobs Test1",     "0",
    "Script: Custom Report Test",      "0",
    "Script: Generalized Importer",    "0",
    "Script: Custom Export #2",        "0",
    "Script: DSS System Tests",        "0",
    "Script: LAS System Tests",        "0",
    "Script: PES System Tests",        "0",
    "Script: CAS System Tests",        "0",
    NULL, NULL};


void CTestSuiteDlg::InitTree ()
   {
   CRect cRect;
   m_cTreeCtl.GetClientRect (cRect);

	LV_COLUMN lvColumn;
	memset (&lvColumn, 0, sizeof(lvColumn));
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = cRect.Width() - 210;
	lvColumn.pszText = _T("Item");
	lvColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT;
	m_cTreeCtl.SetColumn (0, &lvColumn);

	m_cTreeCtl.InsertColumn (1, "Status", LVCFMT_CENTER, 70, 1);
	m_cTreeCtl.InsertColumn (2, "Results", LVCFMT_CENTER,130, 2);

	m_cTreeCtl.SetImageList (&m_cStatusImages, TVSIL_NORMAL);
	m_cTreeCtl.SetImageList (&m_cCheckBoxImages, TVSIL_STATE);

   CString strTmp;
	for(int i=0; szTestArray[i*2]; i++)
	   {
      HTREEITEM hti = AddElement (TVI_ROOT, szTestArray[i*2], TRUE, szTestArray[i*2+1][0] - '0');

      int iMaxJ = (rand() >> 4) % 6 + 1;
   	for(int j=0; j<iMaxJ; j++)
         {
         strTmp.Format ("Component: %d", j+1);
         HTREEITEM htsi = AddElement (hti, strTmp, TRUE, szTestArray[i*2+1][0] - '0');

         int iMaxK = (rand() >> 4) % 6 + 1;
   	   for(int k=0; k<iMaxK; k++)
            {
            strTmp.Format ("Case: %d", k+1);
            HTREEITEM htssi = AddElement (htsi, strTmp, FALSE, szTestArray[i*2+1][0] - '0');
            }
         }
      }

	m_cTreeCtl.ModifyExStyle  (0,TVOXS_COLUMNHDR);
	m_cTreeCtl.ModifyExStyle  (0,TVOXS_MULTISEL);
	m_cTreeCtl.ModifyStyle    (0,TVS_EDITLABELS);
	m_cTreeCtl.ModifyStyle    (0,TVS_HASBUTTONS);
	m_cTreeCtl.ModifyStyle    (0,TVS_HASLINES);
	m_cTreeCtl.ModifyStyle    (0,TVS_LINESATROOT);
	m_cTreeCtl.ModifyStyle    (0,TVS_SHOWSELALWAYS);
//	m_cTreeCtl.ModifyExStyle  (0,TVOXS_VGRID);
//	m_cTreeCtl.ModifyExStyle  (0,TVOXS_HGRID);
	m_cTreeCtl.ModifyExStyle  (0,TVOXS_FLGRID);
	m_cTreeCtl.ModifyExStyle  (0,TVOXS_ROWSEL);
	m_cTreeCtl.ModifyExStyle  (0,TVOXS_PICKANYWHERE);
	m_cTreeCtl.ModifyExStyle  (0,TVOXS_ITEMTIPS);
	m_cTreeCtl.ShowWindow     (SW_SHOW);
   }


HTREEITEM  CTestSuiteDlg::AddElement (HTREEITEM hParentItem, CString strText, BOOL bHasKids, int iStatus)
   {
   PSZ pszStatus = (iStatus==0 ? "Not Run"   : "Done"        );
   PSZ pszResult = (iStatus==0 ? "<Not Run>" : "<Click Here>");
   if (iStatus == 3) // a hack
      {
      pszStatus = "Running...";
      pszResult = "<Running...>";
      iStatus = 0;
      }


   HTREEITEM hti = m_cTreeCtl.InsertItem (strText, hParentItem);
   m_cTreeCtl.SetSubItem (hti, 1, OX_SUBITEM_TEXT | OX_SUBITEM_IMAGE, pszStatus, iStatus);
   m_cTreeCtl.SetSubItem (hti, 2, OX_SUBITEM_TEXT, pszResult);
   if (iStatus == 1 || iStatus == 2)
      m_cTreeCtl.SetItemColor (hti, RGB(0,0,255), 2);

	TV_ITEM tvi;
	memset(&tvi,0,sizeof(tvi));
	tvi.cChildren=1;
	tvi.mask= TVIF_HANDLE | TVIF_STATE | (bHasKids ? TVIF_CHILDREN : 0);
	tvi.stateMask = TVIS_STATEIMAGEMASK;
	tvi.state = INDEXTOSTATEIMAGEMASK(2);
	tvi.hItem = hti;
	m_cTreeCtl.SetItem(&tvi);
//	m_cTreeCtl.SetItemImage(hti, 0 ,1);
   return hti;
   }


void CTestSuiteDlg::OnItemExpandingTree1(NMHDR* pNMHDR, LRESULT* pResult) 
   {
   }


void CTestSuiteDlg::OnLButtonDown(UINT nFlags, CPoint point) 
   {
   }


void CTestSuiteDlg::OnOptionsParameters() 
   {
	CSystemPropertiesDlg  cDlg;
   cDlg.DoModal ();
   }

void CTestSuiteDlg::OnInitMenu(CMenu* pMenu) 
   {
	CDynaDialog::OnInitMenu(pMenu);
   CMenu* pOptionsMenu = pMenu->GetSubMenu (0);

   //ID_OPTIONS_CONTEXT_PARAMETERS
   //pOptionsMenu->InsertMenu (-1, MF_BYPOSITION, 1234, "New Menu Item");

   PSZ psz;
   int iID;
   switch (m_cTreeCtl.GetSelectionLevel ())
      {
      case 1:   iID = IDC_SCRIPT_PROPERTIES     ; psz = "Script Properties ..."     ; break;
      case 2:   iID = IDC_COMPONENT_PROPERTIES  ; psz = "Component Properties ..."  ; break;
      case 3:   iID = IDC_CASE_PROPERTIES       ; psz = "Test Case Properties ..."  ; break;
      default:  iID = IDC_SCRIPT_PROPERTIES     ; psz = "Script Properties ..."     ; break; // A hack
      }
   pOptionsMenu->ModifyMenu (0, MF_BYPOSITION, iID, psz);
   
   }

void CTestSuiteDlg::OnScriptProperties() 
   {
   m_cTreeCtl.OnScriptProperties();
   }

void CTestSuiteDlg::OnComponentProperties() 
   {
   m_cTreeCtl.OnComponentProperties(); 
   }

void CTestSuiteDlg::OnCaseProperties() 
   {
   m_cTreeCtl.OnCaseProperties();
   }

void CTestSuiteDlg::OnSize(UINT nType, int cx, int cy) 
   {
	CDynaDialog::OnSize(nType, cx, cy);

   if (m_cTreeCtl.m_hWnd)
      {
      CRect cRect;
      m_cTreeCtl.GetClientRect (cRect);
      m_cTreeCtl.SetColumnWidth (0, cRect.Width () - 200);
      }
   }

