#include "bt_message.hh"

BT_Message::BT_Message()
{
  _mode = 1;
  _r    = 100;
  _g    = 100;
  _b    = 100;

}


BT_Message::BT_Message(unsigned char mode, unsigned char r , unsigned char g, unsigned char b ) : _mode(mode), _r(r), _g(g), _b(b) {}

const char * BT_Message::ReturnMessage()
{
 std::string temp;

 temp.push_back(_mode);
 temp.push_back(',');
 temp.push_back(_r);
 temp.push_back(',');
 temp.push_back(_g);
 temp.push_back(',');
 temp.push_back(_b);

 const char * message = temp.c_str();

 return message;
}


