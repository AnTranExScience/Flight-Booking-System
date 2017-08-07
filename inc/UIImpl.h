#ifndef __UI_IMPL_H__
#define __UI_IMPL_H__

#include <iostream>
#include "Notifier.h"

class IUI
{
  public:
    IUI(){};
    IUI(Notifier& n1){};
    virtual ~IUI();
    virtual void RunUI(Notifier& n1) = 0;

  protected:
    IUI*  m_UI;
};

#endif /* __IUI_H__ */
