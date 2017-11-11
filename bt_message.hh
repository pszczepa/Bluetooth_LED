#ifndef BT_MESSAGE_HH
#define BT_MESSAGE_HH

#include <string>

class BT_Message
{
  public:
    BT_Message();
    BT_Message(unsigned int , unsigned int, unsigned int, unsigned int);

    const char * ReturnMessage();

  private:
    enum _mode_t {__RGB,__R,__G,__B};

    unsigned int _mode;
    unsigned int _r;
    unsigned int _g;
    unsigned int _b;
};

#endif // BT_MESSAGE_HH
