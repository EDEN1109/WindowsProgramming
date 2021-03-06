
// 191017_ProblemDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "191017_Problem.h"
#include "191017_ProblemDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CMy191017ProblemDlg 대화 상자



CMy191017ProblemDlg::CMy191017ProblemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY191017_PROBLEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy191017ProblemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, myEdit1);
	DDX_Control(pDX, IDC_EDIT2, myEdit2);
	DDX_Control(pDX, IDC_EDIT3, myEdit3);
	DDX_Control(pDX, IDC_EDIT4, myEdit4);
	DDX_Control(pDX, IDC_EDIT5, myEdit5);
	DDX_Control(pDX, IDC_EDIT6, myEdit6);
	DDX_Control(pDX, IDC_EDIT7, myEdit7);
	DDX_Control(pDX, IDC_CHECK1, checkBox);
}

BEGIN_MESSAGE_MAP(CMy191017ProblemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEAR, &CMy191017ProblemDlg::OnClickedClear)
	ON_BN_CLICKED(IDC_REGISTER, &CMy191017ProblemDlg::OnClickedRegister)
ON_BN_CLICKED(IDC_CHECK1, &CMy191017ProblemDlg::OnClickedSame)
END_MESSAGE_MAP()


// CMy191017ProblemDlg 메시지 처리기

BOOL CMy191017ProblemDlg::OnInitDialog()
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

void CMy191017ProblemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMy191017ProblemDlg::OnPaint()
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
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMy191017ProblemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy191017ProblemDlg::OnClickedClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	myEdit1.SetWindowTextW(L"");
	myEdit2.SetWindowTextW(L"");
	myEdit3.SetWindowTextW(L"");
	myEdit4.SetWindowTextW(L"");
	myEdit5.SetWindowTextW(L"");
	myEdit6.SetWindowTextW(L"");
	myEdit7.SetWindowTextW(L"");
}


void CMy191017ProblemDlg::OnClickedRegister()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (myEdit1.GetWindowTextLengthW() != 0 && myEdit2.GetWindowTextLengthW() != 0 && myEdit3.GetWindowTextLengthW() != 0
		&& myEdit4.GetWindowTextLengthW() != 0 && myEdit5.GetWindowTextLengthW() != 0 && myEdit6.GetWindowTextLengthW() != 0
		&& myEdit7.GetWindowTextLengthW() != 0)
	{
		MessageBox(L"등록되었습니다.");
	}	
	else
	{
		MessageBox(L"빈칸을 모두 채워주세요.");
	}
}


void CMy191017ProblemDlg::OnClickedSame()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (checkBox.GetCheck() == 1)
	{
		CString strText;
		myEdit1.GetWindowTextW(strText);
		myEdit2.SetWindowTextW(strText);
		myEdit3.SetWindowTextW(strText);
		myEdit4.SetWindowTextW(strText);
		myEdit5.SetWindowTextW(strText);
		myEdit6.SetWindowTextW(strText);
		myEdit7.SetWindowTextW(strText);
	}
}
