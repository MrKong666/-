#include<iostream>

#include<windows.h>
using namespace std;
class A {
public:
	std::wstring lujing;
	std::wstring mingzi;
	int left;
	int top;

	A(const std::wstring& a, const std::wstring& b, int c, int d)
		: lujing(a), mingzi(b), left(c), top(d) {}
	A(const A&other)
		:lujing(other.lujing),mingzi(other.mingzi),left(other.left),top(other.top){}
};
 auto weixin = L"WeChatMainWndForPC";
 auto qq = L"Chrome_WidgetWin_1";
 A* wechat = new A(weixin, L"΢��", 400, 400);
 A* QQ = new A(qq, L"QQ", 400, 500);
void f(int flag);
int main() {
	
	f(0);
	
	
	return 0;
}
void f(int flag=0) {//1ΪqqĬ��Ϊ΢��
	//Ѱ�Ҵ���
	//�ַ�����������ǰ���L
	//HWND weixinchuangko = FindWindow(qq, L"QQ");
	A ruanjian = *wechat;
	if (flag == 1) {
		ruanjian = *QQ;
	}
	auto lujin = ruanjian.lujing.c_str();
	auto mingzi = ruanjian.mingzi.c_str();
	HWND chuangko = FindWindow(lujin,mingzi);
	 
	//�Ѵ����ö�
	SetWindowPos(chuangko, HWND_TOPMOST, 0, 0, 700, 500, SWP_NOMOVE | SWP_NOSIZE);
	ShowWindow(chuangko, SW_RESTORE);

	//��ȡ����λ��
	RECT rect;
	GetWindowRect(chuangko, &rect);
	for (int i = 0; i < 10; i++) {
		//�ƶ���굽�����
		SetCursorPos(rect.left + ruanjian.left, rect.top + ruanjian.top);

		//ģ�������
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

		//ճ��
		keybd_event(VK_CONTROL, 0, 0, 0);
		keybd_event('V', 0, 0, 0);
		keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

		//����
		keybd_event(VK_RETURN, 0, 0, 0);
		keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
		keybd_event(VK_RETURN, 0, 0, 0);
		keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
		Sleep(300);
	}
	//���ڻָ�
	SetWindowPos(chuangko, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}
