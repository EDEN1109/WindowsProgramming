// BrightnessContrastControlDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "BrightnessContrastControlDlg.h"
#include "afxdialogex.h"


// CBrightnessContrastControlDlg 대화 상자

IMPLEMENT_DYNAMIC(CBrightnessContrastControlDlg, CDialogEx)

CBrightnessContrastControlDlg::CBrightnessContrastControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BRIGHTNESS_CONTRAST, pParent)
	, m_nBrightness(0)
	, m_nContrast_2017136128(0)
{

}

CBrightnessContrastControlDlg::~CBrightnessContrastControlDlg()
{
}

void CBrightnessContrastControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BRIGHTNESS, m_nBrightness);
	DDV_MinMaxInt(pDX, m_nBrightness, -255, 255);
	DDX_Control(pDX, IDC_SLIDER_BRIGHTNESS, m_sliderBrightness);
	DDX_Control(pDX, IDC_SLIDER_CONTRAST_2017136128, m_sliderContrast_2017136128);
	DDX_Text(pDX, IDC_EDIT_CONTRAST_2017136128, m_nContrast_2017136128);
	DDV_MinMaxInt(pDX, m_nContrast_2017136128, -100, 100);
	DDX_Control(pDX, IDC_EDIT1, mEdit);
	mEdit.SetWindowTextW(L"IDC_SLIDER_CONTRAST_2017136128");
	DDX_Control(pDX, IDC_EDIT2, mEdit2);
	mEdit2.SetWindowTextW(L"IDC_EDIT_CONTRAST_2017136128");
}


BEGIN_MESSAGE_MAP(CBrightnessContrastControlDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT_BRIGHTNESS, &CBrightnessContrastControlDlg::OnEnChangeEditBrightness)
	ON_EN_CHANGE(IDC_EDIT_CONTRAST_2017136128, &CBrightnessContrastControlDlg::OnChangeEditContrast2017136128)
END_MESSAGE_MAP()


// CBrightnessContrastControlDlg 메시지 처리기


BOOL CBrightnessContrastControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//초기화 Brightness
	m_sliderBrightness.SetRange(-255, 255);
	m_sliderBrightness.SetTicFreq(32);
	m_sliderBrightness.SetPageSize(32);

	//초기화 Contrast
	m_sliderContrast_2017136128.SetRange(-100, 100);
	m_sliderContrast_2017136128.SetTicFreq(20);
	m_sliderContrast_2017136128.SetPageSize(20);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CBrightnessContrastControlDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_sliderBrightness.GetSafeHwnd() == pScrollBar->GetSafeHwnd())
	{
		m_nBrightness = m_sliderBrightness.GetPos();
		UpdateData(FALSE);
	}

	if (m_sliderContrast_2017136128.GetSafeHwnd() == pScrollBar->GetSafeHwnd())
	{
		m_nContrast_2017136128 = m_sliderContrast_2017136128.GetPos();
		UpdateData(FALSE);
	}
	
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CBrightnessContrastControlDlg::OnEnChangeEditBrightness()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_sliderBrightness.SetPos(m_nBrightness);
}


void CBrightnessContrastControlDlg::OnChangeEditContrast2017136128()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_sliderContrast_2017136128.SetPos(m_nContrast_2017136128);
}
