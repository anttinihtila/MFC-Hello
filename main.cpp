#include <afxwin.h>

class CMyApp :public CWinApp {
public: virtual BOOL InitInstance();
};

class CMainWindow :public CFrameWnd {
public: CMainWindow();
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP();
};

CMyApp myApp;

BOOL CMyApp::InitInstance() {
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->MoveWindow(400, 400, 750, 350);
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMainWindow::CMainWindow() {
	Create(NULL, _T("Hello!"));
}

void CMainWindow::OnPaint() {
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);

	dc.FillSolidRect(rect, RGB(46, 139, 87));

	CFont font;
	font.CreatePointFont(300, TEXT("Arial"));

	dc.SetTextColor(RGB(0, 0, 0));

	dc.SetBkColor(RGB(255, 255, 255));

	dc.SelectObject(&font);

	dc.DrawText(_T("Hello! This is a MFC program."), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

}