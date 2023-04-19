/* Copyright (c) 2018 Acrolinx GmbH */

#pragma once

// The libs are copied from packages\Acrolinx.Sidebar.SDK.<version>\lib to ../acrolinx-sdk/lib in a pre build event
#if defined _M_X64
#include "..\acrolinx-sdk\lib\x64\AcrolinxInterface.h"
#else
#include "..\acrolinx-sdk\lib\x86\AcrolinxInterface.h"
#endif
class TextBoxAdapter :
    public CUniversalAdapter
{
public:
    TextBoxAdapter(CString tagName, BOOL encodeContent, CEdit& textbox);
    virtual ~TextBoxAdapter(void);

    CString ExtractRaw();
    BOOL SelectRawRange(IRange* rawRange, Input_Format format);
    BOOL ReplaceRawRange(IRange* rawRange, CString replacement, Input_Format format);
private:
    CEdit* m_textBox;
};

