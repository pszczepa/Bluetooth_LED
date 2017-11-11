#include "bt_message.hh"

BT_Message::BT_Message()
{

}


BT_Message::BT_Message(unsigned int mode, unsigned int r , unsigned int g, unsigned int b ) : _mode(mode), _r(r), _g(g), _b(b) {}

const char * BT_Message::ReturnMessage()
{
 std::string temp;

 temp.push_back(_mode);

 return temp.c_str();
}

