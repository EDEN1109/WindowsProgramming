
// mouseTrackingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mouseTracking.h"
#include "mouseTrackingDlg.h"
#include "afxdialogex.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void MouseClick(int Lbtn, int Rbtn);
void MouseMove(DWORD nX, DWORD nY);

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmouseTrackingDlg 대화 상자



CmouseTrackingDlg::CmouseTrackingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MOUSETRACKING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmouseTrackingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATE, mState);
	DDX_Control(pDX, IDC_REPLAY, mReplayBtn);
}

BEGIN_MESSAGE_MAP(CmouseTrackingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_REPLAY, &CmouseTrackingDlg::OnBnClickedReplay)
END_MESSAGE_MAP()


// CmouseTrackingDlg 메시지 처리기

BOOL CmouseTrackingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmouseTrackingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmouseTrackingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	::SetWindowPos(GetSafeHwnd(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmouseTrackingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CmouseTrackingDlg::PreTranslateMessage(MSG* pMsg) {

	CStatic stat;

	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_SPACE) {

		is_tracking_mode = !is_tracking_mode;

		if (is_tracking_mode == true) {
			mState.SetWindowTextW(L"Tracking");
		}
		else {
			mState.SetWindowTextW(L"Non Tracking");
		}
	}

	//부모에게 결과를 메세지로 보내야 함
	return CDialog::PreTranslateMessage(pMsg);
}


void CmouseTrackingDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (is_tracking_mode) {

		//모니터 상 절대좌표를 가져오는 함수
		GetCursorPos(&absolute_point);

		int point_x = absolute_point.x;
		int point_y = absolute_point.y;

		//int -> CString
		CString point_msg;

		point_msg.Format(L"x = %d | y = %d", point_x, point_y);
		MessageBox(point_msg);

		x.push(point_x);
		y.push(point_y);

		SetCapture();
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CmouseTrackingDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (is_tracking_mode) {
		ReleaseCapture();

		mState.SetWindowTextW(L"Release Capture");
		RedrawWindow();
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CmouseTrackingDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CString str;

	if (is_tracking_mode) {
		if (GetCapture() == this) {
			str.Format(L"Tracking");
		}
		else {
			str.Format(L"Lost");
		}

		mState.SetWindowTextW(str);
		RedrawWindow();
	}


	CDialogEx::OnMouseMove(nFlags, point);
}


void CmouseTrackingDlg::OnBnClickedReplay()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int size = x.size();

	for (int i = 0; i < size; i++)
	{
		MouseMove(x.front(), y.front());

		MouseClick(1, 0);
		MouseClick(2, 0);

		x.pop();
		y.pop();

		Sleep(1000);
	}

}

void MouseClick(int Lbtn, int Rbtn) {

	switch (Lbtn) {
	case 1:
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, NULL);
		break;
	case 2:
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, NULL);
		break;
	}

	switch (Rbtn) {
	case 1:
		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, NULL);
		break;
	case 2:
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, NULL);
		break;
	}
}

void MouseMove(DWORD nX, DWORD nY) {
	// 절대 좌표로 변경
	nX = (DWORD)(65535.0 * nX / (double)GetSystemMetrics(SM_CXSCREEN));
	nY = (DWORD)(65535.0 * nY / (double)GetSystemMetrics(SM_CXSCREEN));

	mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, nX, nY, 0, NULL);
}
