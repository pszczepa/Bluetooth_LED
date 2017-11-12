#ifndef BT_MESSAGE_HH
#define BT_MESSAGE_HH

#include <string>
#include <QByteArray>

class BT_Message
{
  public:
    BT_Message();
    BT_Message(unsigned char , unsigned char, unsigned char, unsigned char);

    const char * ReturnMessage();

  private:
    enum _mode_t {__RGB,__R,__G,__B};

    unsigned char _mode;
    unsigned char _r;
    unsigned char _g;
    unsigned char _b;
};

#endif // BT_MESSAGE_HH
