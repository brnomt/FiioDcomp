
// SnDatToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SnDatTool.h"
#include "SnDatToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
ULONG gTable_Crc32[256] =
{
	0x00000000, 0x04c10db7, 0x09821b6e, 0x0d4316d9,
	0x130436dc, 0x17c53b6b, 0x1a862db2, 0x1e472005,
	0x26086db8, 0x22c9600f, 0x2f8a76d6, 0x2b4b7b61,
	0x350c5b64, 0x31cd56d3, 0x3c8e400a, 0x384f4dbd,
	0x4c10db70, 0x48d1d6c7, 0x4592c01e, 0x4153cda9,
	0x5f14edac, 0x5bd5e01b, 0x5696f6c2, 0x5257fb75,
	0x6a18b6c8, 0x6ed9bb7f, 0x639aada6, 0x675ba011,
	0x791c8014, 0x7ddd8da3, 0x709e9b7a, 0x745f96cd,
	0x9821b6e0, 0x9ce0bb57, 0x91a3ad8e, 0x9562a039,
	0x8b25803c, 0x8fe48d8b, 0x82a79b52, 0x866696e5,
	0xbe29db58, 0xbae8d6ef, 0xb7abc036, 0xb36acd81,
	0xad2ded84, 0xa9ece033, 0xa4aff6ea, 0xa06efb5d,
	0xd4316d90, 0xd0f06027, 0xddb376fe, 0xd9727b49,
	0xc7355b4c, 0xc3f456fb, 0xceb74022, 0xca764d95,
	0xf2390028, 0xf6f80d9f, 0xfbbb1b46, 0xff7a16f1,
	0xe13d36f4, 0xe5fc3b43, 0xe8bf2d9a, 0xec7e202d,
	0x34826077, 0x30436dc0, 0x3d007b19, 0x39c176ae,
	0x278656ab, 0x23475b1c, 0x2e044dc5, 0x2ac54072,
	0x128a0dcf, 0x164b0078, 0x1b0816a1, 0x1fc91b16,
	0x018e3b13, 0x054f36a4, 0x080c207d, 0x0ccd2dca,
	0x7892bb07, 0x7c53b6b0, 0x7110a069, 0x75d1adde,
	0x6b968ddb, 0x6f57806c, 0x621496b5, 0x66d59b02,
	0x5e9ad6bf, 0x5a5bdb08, 0x5718cdd1, 0x53d9c066,
	0x4d9ee063, 0x495fedd4, 0x441cfb0d, 0x40ddf6ba,
	0xaca3d697, 0xa862db20, 0xa521cdf9, 0xa1e0c04e,
	0xbfa7e04b, 0xbb66edfc, 0xb625fb25, 0xb2e4f692,
	0x8aabbb2f, 0x8e6ab698, 0x8329a041, 0x87e8adf6,
	0x99af8df3, 0x9d6e8044, 0x902d969d, 0x94ec9b2a,
	0xe0b30de7, 0xe4720050, 0xe9311689, 0xedf01b3e,
	0xf3b73b3b, 0xf776368c, 0xfa352055, 0xfef42de2,
	0xc6bb605f, 0xc27a6de8, 0xcf397b31, 0xcbf87686,
	0xd5bf5683, 0xd17e5b34, 0xdc3d4ded, 0xd8fc405a,
	0x6904c0ee, 0x6dc5cd59, 0x6086db80, 0x6447d637,
	0x7a00f632, 0x7ec1fb85, 0x7382ed5c, 0x7743e0eb,
	0x4f0cad56, 0x4bcda0e1, 0x468eb638, 0x424fbb8f,
	0x5c089b8a, 0x58c9963d, 0x558a80e4, 0x514b8d53,
	0x25141b9e, 0x21d51629, 0x2c9600f0, 0x28570d47,
	0x36102d42, 0x32d120f5, 0x3f92362c, 0x3b533b9b,
	0x031c7626, 0x07dd7b91, 0x0a9e6d48, 0x0e5f60ff,
	0x101840fa, 0x14d94d4d, 0x199a5b94, 0x1d5b5623,
	0xf125760e, 0xf5e47bb9, 0xf8a76d60, 0xfc6660d7,
	0xe22140d2, 0xe6e04d65, 0xeba35bbc, 0xef62560b,
	0xd72d1bb6, 0xd3ec1601, 0xdeaf00d8, 0xda6e0d6f,
	0xc4292d6a, 0xc0e820dd, 0xcdab3604, 0xc96a3bb3,
	0xbd35ad7e, 0xb9f4a0c9, 0xb4b7b610, 0xb076bba7,
	0xae319ba2, 0xaaf09615, 0xa7b380cc, 0xa3728d7b,
	0x9b3dc0c6, 0x9ffccd71, 0x92bfdba8, 0x967ed61f,
	0x8839f61a, 0x8cf8fbad, 0x81bbed74, 0x857ae0c3,
	0x5d86a099, 0x5947ad2e, 0x5404bbf7, 0x50c5b640,
	0x4e829645, 0x4a439bf2, 0x47008d2b, 0x43c1809c,
	0x7b8ecd21, 0x7f4fc096, 0x720cd64f, 0x76cddbf8,
	0x688afbfd, 0x6c4bf64a, 0x6108e093, 0x65c9ed24,
	0x11967be9, 0x1557765e, 0x18146087, 0x1cd56d30,
	0x02924d35, 0x06534082, 0x0b10565b, 0x0fd15bec,
	0x379e1651, 0x335f1be6, 0x3e1c0d3f, 0x3add0088,
	0x249a208d, 0x205b2d3a, 0x2d183be3, 0x29d93654,
	0xc5a71679, 0xc1661bce, 0xcc250d17, 0xc8e400a0,
	0xd6a320a5, 0xd2622d12, 0xdf213bcb, 0xdbe0367c,
	0xe3af7bc1, 0xe76e7676, 0xea2d60af, 0xeeec6d18,
	0xf0ab4d1d, 0xf46a40aa, 0xf9295673, 0xfde85bc4,
	0x89b7cd09, 0x8d76c0be, 0x8035d667, 0x84f4dbd0,
	0x9ab3fbd5, 0x9e72f662, 0x9331e0bb, 0x97f0ed0c,
	0xafbfa0b1, 0xab7ead06, 0xa63dbbdf, 0xa2fcb668,
	0xbcbb966d, 0xb87a9bda, 0xb5398d03, 0xb1f880b4,
};
ULONG CRC_32(PBYTE pData, ULONG ulSize)
{
	UINT i;
	ULONG nAccum = 0;

	for ( i=0; i<ulSize; i++)
		nAccum = (nAccum<<8)^gTable_Crc32[(nAccum>>24)^(*pData++)];
	return nAccum;
}
CString GetModulePath()
{
	CString strModulePath=_T("");
	DWORD dwRet;
	dwRet = GetModuleFileName(NULL, strModulePath.GetBuffer(MAX_PATH), MAX_PATH);
	strModulePath.ReleaseBuffer();
	if (dwRet>0)
	{
		strModulePath = strModulePath.Left(strModulePath.ReverseFind(_T('\\'))+1);
	}
	return strModulePath;
}
BOOL UnicodeToAnsi(LPSTR &lpszDst,int &nDstSize,LPCWSTR lpwzSrc)
{
	lpszDst = NULL;
	if (!lpwzSrc)
	{
		return FALSE;
	}
	int nSrcSize;
	nSrcSize = wcslen(lpwzSrc);
	if (nSrcSize<=0)
	{
		return FALSE;
	}
	nDstSize = WideCharToMultiByte(CP_ACP,0,lpwzSrc,-1,NULL,0,NULL,NULL);
	if (nDstSize<=0)
	{
		return FALSE;
	}
	lpszDst = new CHAR[nDstSize];
	if (!lpszDst)
	{
		return FALSE;
	}
	int nCopySize;
	nCopySize = WideCharToMultiByte(CP_ACP,0,lpwzSrc,-1,lpszDst,nDstSize,NULL,NULL);
	if (nCopySize<=0)
	{
		delete []lpszDst;
		lpszDst = NULL;
		return FALSE;
	}
	return TRUE;
}
BOOL IsNumberString(CString strValue)
{
	CString strNumberChar=_T("0123456789");
	CString strRet;
	strRet = strValue.SpanIncluding(strNumberChar);
	if (strRet!=strValue)
	{
		return FALSE;
	}
	return TRUE;
}
CString IntStrIncrease(CString strValue)
{
	CString strRet;
	if (!IsNumberString(strValue))
	{
		strRet.Empty();
		return strRet;
	}
	int i,nLen;
	nLen = strValue.GetLength();
	TCHAR szChar;
	for (i=nLen-1;i>=0;i--)
	{
		szChar = strValue[i];
		if ((szChar>=_T('0'))&&(szChar<_T('9')))
		{
			szChar++;
		}
		else if (szChar==_T('9'))
		{
			szChar = _T('0');
			strValue.SetAt(i,szChar);
			continue;
		}
		strValue.SetAt(i,szChar);
		break;
	}
	strRet = strValue;
	return strRet;
}
ULONG StrToULong(CString value,int radix)
{
	ULONG ret;
	ret = _tcstoul((LPCTSTR)value,NULL,radix);
	return ret;
}
// CSnDatToolDlg 对话框

CSnDatToolDlg::CSnDatToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSnDatToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSnDatToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSnDatToolDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_GENERATE, &CSnDatToolDlg::OnBnClickedBtnGenerate)
END_MESSAGE_MAP()


// CSnDatToolDlg 消息处理程序

BOOL CSnDatToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSnDatToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSnDatToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSnDatToolDlg::OnBnClickedBtnGenerate()
{
	// TODO: Add your control notification handler code here
	CString strStartSn,strSnCount,strFixLength,strFix,strCarry;
	ULONG ulSnLength,ulFixLength,ulSnCount;
	GetDlgItemText(IDC_EDT_SN,strStartSn);
	GetDlgItemText(IDC_EDT_COUNT,strSnCount);
	GetDlgItemText(IDC_EDT_FIX_LENGTH,strFixLength);
	if (strFixLength.IsEmpty())
	{
		ulFixLength = 0;
	}
	else
		ulFixLength = StrToULong(strFixLength,10);
	ulSnLength = strStartSn.GetLength();
	if (ulFixLength>=ulSnLength)
	{
		MessageBox(_T("固定字符超过SN长度"),NULL,MB_OK|MB_ICONERROR);
		return;
	}
	ulSnCount = StrToULong(strSnCount,10);
	ULONG i,ulFileSize;
	PBYTE pFileData=NULL;
	CFile file;
	CString strSnDatFile;
	BOOL bRet;
	PSTRUCT_SN_DAT_HEAD pHeader;
	ulFileSize = sizeof(STRUCT_SN_DAT_HEAD)+ulSnCount-1+4+SN_MAX_LENGTH*ulSnCount;
	pFileData = new BYTE[ulFileSize];
	if (!pFileData)
	{
		MessageBox(_T("分配内存失败"),NULL,MB_OK|MB_ICONERROR);
		return;
	}
	memset(pFileData,0,ulFileSize);
	pHeader = (PSTRUCT_SN_DAT_HEAD)pFileData;
	pHeader->uiTag = SN_DAT_HEADER_TAG;
	pHeader->uiHeaderSize = ulFileSize-SN_MAX_LENGTH*ulSnCount;
	pHeader->uiTotal = ulSnCount;
	pHeader->uiFree = ulSnCount;
	pHeader->uiSnLength = ulSnLength;
	PBYTE pSn = pFileData+pHeader->uiHeaderSize;
	if (ulFixLength)
	{
		strFix = strStartSn.Left(ulFixLength);
		strCarry = strStartSn.Mid(ulFixLength);
	}
	else
	{
		strFix = _T("");
		strCarry = strStartSn;
	}
	int nDstSize;
	LPSTR pSrc=NULL;
	for (i=0;i<ulSnCount;i++)
	{
		strStartSn = strFix+ strCarry;
		bRet = UnicodeToAnsi(pSrc,nDstSize,strStartSn);
		if (!pSrc)
		{
			delete []pFileData;
			pFileData = NULL;
			MessageBox(_T("转换失败"),NULL,MB_OK|MB_ICONERROR);
			return;
		}
		memcpy(pSn,pSrc,nDstSize);
		pSn += SN_MAX_LENGTH;
		strCarry = IntStrIncrease(strCarry);
		delete []pSrc;
	}
	pHeader->uiSnDataCrc = CRC_32(pFileData+pHeader->uiHeaderSize,SN_MAX_LENGTH*ulSnCount);
	*(PDWORD)(pFileData+pHeader->uiHeaderSize-4)=CRC_32(pFileData,pHeader->uiHeaderSize-4);
	strSnDatFile = GetModulePath()+_T("sn.dat");
	bRet = file.Open(strSnDatFile,CFile::typeBinary|CFile::modeCreate|CFile::modeReadWrite);
	if (!bRet)
	{
		delete []pFileData;
		pFileData = NULL;
		MessageBox(_T("创建Sn.dat文件失败"),NULL,MB_OK|MB_ICONERROR);
		return;
	}
	file.Write(pFileData,ulFileSize);
	file.Close();
	delete []pFileData;
	pFileData = NULL;
	MessageBox(_T("Sn.dat文件创建成功,已保存到程序目录."));

}
