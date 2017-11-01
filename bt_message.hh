#ifndef BT_MESSAGE_HH
#define BT_MESSAGE_HH


class BT_Message
{
  public:
    BT_Message();

    //char * ReturnMessage();

  private:
    enum _Mode {__RGB,__R,__G,__B};
    unsigned int _r;
    unsigned int _g;
    unsigned int _b;
};

#endif // BT_MESSAGE_HH
