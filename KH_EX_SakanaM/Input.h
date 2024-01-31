
#pragma once

#include <graphics.h>

class Input
{   public:

	ExMessage msg;

	bool key_W = false;
	bool key_S = false;
	bool key_A = false;
	bool key_D = false;

	bool key_Q = false;
	bool key_E = false;
	bool key_R = false;
	bool key_F = false;

	bool arr_U = false;
	bool arr_D = false;
	bool arr_L = false;
	bool arr_R = false;

	bool space = false;
	bool shift = false;
	bool esc__ = false;
	bool enter = false;

	int  mouse_X = 0;
	int  mouse_Y = 0;
	bool mouse_V = false;
	bool mouse_L = false;
	bool mouse_R = false;
	bool mouse_M = false;
	int  mouse_W = 0;

	void 
    GetInput()
    {
        while (peekmessage(&msg))
        {
            switch (msg.message)
            {
            case 0x100: switch (msg.vkcode)
                {
                    case 0x57: key_W = true; break;
                    case 0x53: key_S = true; break;
                    case 0x41: key_A = true; break;
                    case 0x44: key_D = true; break;

                    case 0x51: key_Q = true; break;
                    case 0x45: key_E = true; break;
                    case 0x52: key_R = true; break;
                    case 0x46: key_F = true; break;

                    case 0x26: arr_U = true; break;
                    case 0x28: arr_D = true; break;
                    case 0x25: arr_L = true; break;
                    case 0x27: arr_R = true; break;

                    case 0x20: space = true; break;
                    case 0x10: shift = true; break;
                    case 0x1B: esc__ = true; break;
                    case 0x0D: enter = true; break;
                }break;

            case 0x101: switch (msg.vkcode)
                {
                    case 0x57: key_W = false; break;
                    case 0x53: key_S = false; break;
                    case 0x41: key_A = false; break;
                    case 0x44: key_D = false; break;

                    case 0x51: key_Q = false; break;
                    case 0x45: key_E = false; break;
                    case 0x52: key_R = false; break;
                    case 0x46: key_F = false; break;

                    case 0x26: arr_U = false; break;
                    case 0x28: arr_D = false; break;
                    case 0x25: arr_L = false; break;
                    case 0x27: arr_R = false; break;

                    case 0x20: space = false; break;
                    case 0x10: shift = false; break;
                    case 0x1B: esc__ = false; break;
                    case 0x0D: enter = false; break;
                }break;

            case 0x200: mouse_X = msg.x;
                        mouse_Y = msg.y;
                        mouse_V = true;  break;
            case 0x201: mouse_L = true;  break;
            case 0x202: mouse_L = false; break;
            case 0x204: mouse_R = true;  break;
            case 0x205: mouse_R = false; break;
            case 0x207: mouse_M = true;  break;
            case 0x208: mouse_M = false; break;
            case 0x20a: mouse_W = msg.wheel;
                                         break;
            default:                     break;
            }
        }
    }
};
