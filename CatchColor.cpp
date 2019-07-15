// CatchColor.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "CatchColor.h"
#include "CatchColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCatchColorApp

BEGIN_MESSAGE_MAP(CCatchColorApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCatchColorApp construction

CCatchColorApp::CCatchColorApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCatchColorApp object

CCatchColorApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCatchColorApp initialization

BOOL CCatchColorApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CCatchColorDlg dlg;
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
