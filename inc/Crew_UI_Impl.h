#ifndef __CREW_UI_IMPL_H__
#define __CREW_UI_IMPL_H__

class UIImpl;
class Notifier;
class FlightInfo;

class CrewUIImpl : public IUI
{
  public:
    CrewUIImpl(Notifier& n1){}
    ~CrewUIImpl(){};
    virtual void RunUI(Notifier& n1);

  private:
    void BookFlight(Notifier& _n1);
    int  InitialRun(Notifier& n1);
    void CreateNewFlight(Notifier& n1);
    void UpdateExistingFlight(Notifier& n1);
    void CreateChange(Notifier& n1, int userChange, std::string& flightID);
};

#endif /* __CREW_UI_IMPL_H__ */
