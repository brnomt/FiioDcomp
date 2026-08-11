
// SnDatToolDlg.h : 头文件
//

#pragma once
//定义sn文件结构
#define SN_DAT_HEADER_TAG 0x46444E53
#define SN_MAX_LENGTH 60
#pragma pack(1)
typedef struct {
	UINT uiTag;//'SNDF'
	UINT uiHeaderSize;//size of header
	UINT uiTotal;//total of sn
	UINT uiFree;//count of available sn
	UINT uiSnLength;//must be smaller than 60 
	UINT uiSnDataCrc;//crc of sn
	BYTE snBitmap[1];
}STRUCT_SN_DAT_HEAD,*PSTRUCT_SN_DAT_HEAD;
#pragma pack()

// CSnDatToolDlg 对话框
class CSnDatToolDlg : public CDialog
{
// 构造
public:
	CSnDatToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SNDATTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnGenerate();
};
