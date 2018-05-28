/* Copyright (c) 2018 Acrolinx GmbH */

#include "StdAfx.h"
#include "TextBoxAdapter.h"


TextBoxAdapter::TextBoxAdapter(CString tagName, BOOL encodeContent, CEdit& textBox)
    :CUniversalAdapter(tagName, encodeContent)
    ,m_textBox(&textBox)
{
}


TextBoxAdapter::~TextBoxAdapter(void)
{
    m_textBox = NULL;
}


CString TextBoxAdapter::ExtractRaw()
{
    if(m_textBox == NULL)
    {
        return CString();
    }

    CString windowText;
    m_textBox->GetWindowTextW(windowText);
    return windowText;
}


BOOL TextBoxAdapter::SelectRawRange(IRange* rawRange, Input_Format format)
{
    LONG start = 0, end = 0;
    rawRange->GetStart(&start);
    rawRange->GetEnd(&end);

    m_textBox->SetSel(start, end);

    return TRUE;
}


BOOL TextBoxAdapter::ReplaceRawRange(IRange* rawRange, CString replacement, Input_Format format)
{
    LONG start = 0, end = 0;
    rawRange->GetStart(&start);
    rawRange->GetEnd(&end);

    m_textBox->SetSel(start,end);
    m_textBox->ReplaceSel(replacement, TRUE);

    return TRUE;
}
