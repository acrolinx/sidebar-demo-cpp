/* Copyright (c) 2018 Acrolinx GmbH */

#pragma once
#include "..\modules\AcrolinxInterface.h"
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

