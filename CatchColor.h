// CatchColor.h : main header file for the CATCHCOLOR application
//

#if !defined(AFX_CATCHCOLOR_H__1404479E_A1AE_4134_822E_33C251225E16__INCLUDED_)
#define AFX_CATCHCOLOR_H__1404479E_A1AE_4134_822E_33C251225E16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCatchColorApp:
// See CatchColor.cpp for the implementation of this class
//

class CCatchColorApp : public CWinApp
{
public:
	CCatchColorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatchColorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCatchColorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATCHCOLOR_H__1404479E_A1AE_4134_822E_33C251225E16__INCLUDED_)
